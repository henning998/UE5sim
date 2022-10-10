// Fill out your copyright notice in the Description page of Project Settings.


#include "Server.h"
THIRD_PARTY_INCLUDES_START

#include "MessageTCP.pb.h"

THIRD_PARTY_INCLUDES_END

// Sets default values
AServer::AServer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//static ConstructorHelpers::FObjectFinder<UBlueprint> blueprint_finder_test(TEXT("Blueprint'/Game/Blueprints/cartpoletest.cartpoletest'"));
	//if (blueprint_finder_test.Succeeded())
	//	mBCTest = (UClass*)blueprint_finder_test.Object->GeneratedClass;
	//static ConstructorHelpers::FObjectFinder<UBlueprint> blueprint_finder_cartpole(TEXT("Blueprint'/Game/Blueprints/BP_Cartpole.BP_Cartpole'"));
	//if (blueprint_finder_cartpole.Succeeded())
	//	mBCCartpole = (UClass*)blueprint_finder_cartpole.Object->GeneratedClass;


}

void AServer::delete_elem(client* clientobj)
{
	double num = clientobj->agent->YLocationActor;
	auto it = std::find(ListOfAgentPos.begin(), ListOfAgentPos.end(), num);
	ListOfAgentPos.erase(it);
	clientobj->close();
	clientobj->slet = true;
	///*auto cl = std::find(clients.begin(), clients.end(), clientobj);
	//*/clients.erase(cl);
}

// Called when the game starts or when spawned
void AServer::BeginPlay()
{
	Open_Connection();
	Super::BeginPlay();

}

// Called every frame
void AServer::Tick(float DeltaTime)
{
	Conduct_Connection();
	while (joblist.size() > 0)
	{
		job todo = joblist.front();
		todo.run();
		joblist.pop();
	}
	Super::Tick(DeltaTime);

}

void AServer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Close_Connection();
	Super::EndPlay(EndPlayReason);
}


void AServer::Open_Connection()
{
	if (!IsConnectionOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("Openning Connection"));
		IsConnectionOpen = true;
		WaitingForConnection = true;

		//setup IP
		FIPv4Address IP; 
		FIPv4Address::Parse(FString("127.0.0.1"), IP);
		FIPv4Endpoint Endpoint(IP, (uint16)8000);

		// Make TCP
		ListenSocket = FTcpSocketBuilder(TEXT("TcpSocket")).AsReusable().WithReceiveBufferSize(1024).WithSendBufferSize(1024);

		// setup for socket 
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
		auto dummy = SocketSubsystem->CreateInternetAddr();
		dummy->SetIp(Endpoint.Address.Value);
		dummy->SetPort(Endpoint.Port);
		ListenSocket->Bind(*dummy);
		ListenSocket->Listen(NumberOfListen);

		UE_LOG(LogTemp, Warning, TEXT("Listening"));
	}
}

void AServer::Close_Connection()
{
	if (IsConnectionOpen) {
		UE_LOG(LogTemp, Warning, TEXT("Closing Connection"));
		IsConnectionOpen = false;

		ListenSocket->Close();
	}

}

void AServer::Conduct_Connection()
{
	// Accept Connection
	if (WaitingForConnection)
	{
		TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
		bool hasConnection = false;
		//Do anyone want to join the server
		if (ListenSocket->HasPendingConnection(hasConnection) && hasConnection)
		{
			client newcon;
			newcon.tcp_con = ListenSocket->Accept(*RemoteAddress, TEXT("Connection"));
			newcon.last_activ = FPlatformTime::Seconds();
			clients.push_back(newcon);
			if (clients.size() == NumberOfListen) // max number of clients reach?
			{
				WaitingForConnection = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("incoming connection"));

			//Starting async recv thread
			if (!RecvThreadStarted)
			{
				RecvThreadStarted = true;
				RecvTheard = Async(EAsyncExecution::LargeThreadPool, [&]()
					{ //lambda func
						UE_LOG(LogTemp, Warning, TEXT("recv thread started"));
						// is server running
						while (IsConnectionOpen)
						{
							uint32 size;
							TArray<uint8> ReceivedData;
							for (size_t i = 0; i < clients.size(); i++)
							{
								// is client connected and active
								if (clients.at(i).tcp_con->GetConnectionState() == SCS_Connected && ((clients.at(i).last_activ + TimeOutConnection) >= FPlatformTime::Seconds()))
								{
									//do client want to say something
									if (clients.at(i).tcp_con->HasPendingData(size))
									{
										ReceivedData.Init(0, 1024);
										int32 Read = 0;
										clients.at(i).tcp_con->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
										Message(ReceivedData, &clients.at(i));
										clients.at(i).last_activ = FPlatformTime::Seconds();
									}
									else // something to send???
									{
										clients.at(i).SendNewState();// send state if it is the newest
										//clients.at(i).last_activ = FPlatformTime::Seconds();
									}
								}
								else // Delete inactiv client
								{
									// NEED TO BE UPDATED FOR DELETING THE ADDED AGENT
									if(clients.at(i).slet)
									{
										clients.erase(clients.begin() + i);
									}
									else if(!clients.at(i).delete_agent) {
										clients.at(i).delete_agent = true;
										job jobobj;
									client* clientobj =  &clients.at(i);
									//delete_elem(i);
									jobobj.func = std::bind(&AServer::delete_elem, this, clientobj);
									joblist.push(jobobj);
									WaitingForConnection = true;
									}
								}
							}
						}
					});
			}
		}
	}
}

void AServer::Message(TArray<uint8> msg, client* clientobj)
{
	// get from a Tarray of bytes to a string and then to a protobuf
	std::string message;
	for (size_t i = 0; i < msg.Num(); i++)
	{
		message.push_back(msg[i]);
	}
	MessageTCP inbox;
	inbox.ParseFromString(message); // decode messsage
	std::vector<float> inputvec;
	std::copy(inbox.agent_input().begin(), inbox.agent_input().end(), std::back_inserter(inputvec)); // copy array to vector
	int id = inbox.agent_id();
	std::string func = inbox.function_call();
	std::string debug = inbox.debug_msg();

	// What do the message tell me to do
	job jobobj;
	// Add agent if client tell me to do it or the client dont have a agent

	if ((func == "addactor") || (clientobj->agent == nullptr))
	{
		jobobj.func = std::bind(&AServer::AddActor, this, clientobj);
		joblist.push(jobobj);
	}
	// if input vector is set, send it to the agent of the client
	if (inputvec.size() > 0)
	{
		jobobj.func = std::bind(&AServer::SetInputActor, this, clientobj, inputvec); 
		joblist.push(jobobj);
	}
	if(func == "getstate")
	{
		jobobj.func = std::bind(&AServer::GetStateActor, this, clientobj);
	}
	if (func == "reset")
	{
		jobobj.func = std::bind(&AServer::ResetActor, this, clientobj);
		joblist.push(jobobj);
	}
}


// ONLY CALL THIS FUNTION IN THE MAIN THREAD
void AServer::AddActor(client* client)
{
	float y = GetValidPositionForAgent();
	const FVector spawn_point = FVector(0, y, 0.1);
	const FRotator spawn_rotation = FRotator();
	client->agent = GetWorld()->SpawnActor<ACartpole>(YourBlueprintClass,spawn_point,spawn_rotation);
	client->agent->YLocationActor = y; 
}

void AServer::SetInputActor(client* client, std::vector<float> in)
{
	client->agent->SetInput(in);
}

void AServer::GetStateActor(client* client)
{
	if(client->agent != nullptr)
	{
		MessageTCP protomsg;
		protomsg.set_agent_id(client->id);
		std::vector<float> state = client->agent->GetState();
		protomsg.mutable_env_state()->Add(state.begin(), state.end());
		protomsg.set_done(client->agent->Done);
		std::string msg = protomsg.SerializeAsString();
		client->SendMSG(msg);
	}
}

float AServer::GetValidPositionForAgent()
{
	float Position = 0;
	bool same = true;
	while (same)
	{
		if (std::find(ListOfAgentPos.begin(), ListOfAgentPos.end(), Position) != ListOfAgentPos.end())
		{
			Position += 200;
		}
		else
		{
			same = false;
		}
	}
	ListOfAgentPos.push_back(Position);
	return Position;
}

void AServer::ResetActor(client* client)
{
	client->agent->ResetEnv();
}