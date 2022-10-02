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

void AServer::delete_elem(size_t i)
{
	//ConnectionSockets.at(i)->Close();
	//ConnectionSockets.erase(ConnectionSockets.begin() + i);
	//LastActivitySockets.erase(LastActivitySockets.begin() + i);
	clients.at(i).close();
	clients.erase(clients.begin() + i);
}

// Called when the game starts or when spawned
void AServer::BeginPlay()
{
	Open_Connection();
	//AddActor();
	Super::BeginPlay();
	
}

// Called every frame
void AServer::Tick(float DeltaTime)
{
	Conduct_Connection();
	if (joblist.size()>0)
	{
	job todo = joblist.front();
	todo.run();
	joblist.pop();
	}
	//if(spawn)
	//{
		//AddActor();
		//spawn = false;
	//}
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

		FIPv4Address IP;
		FIPv4Address::Parse(FString("127.0.0.1"), IP);
		FIPv4Endpoint Endpoint(IP, (uint16)8000);

		ListenSocket = FTcpSocketBuilder(TEXT("TcpSocket")).AsReusable().WithReceiveBufferSize(1024).WithSendBufferSize(1024);

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
		if (ListenSocket->HasPendingConnection(hasConnection) && hasConnection)
		{
			
			//ConnectionSockets.push_back(ListenSocket->Accept(*RemoteAddress, TEXT("Connection")));
			//LastActivitySockets.push_back(FPlatformTime::Seconds());
			//if(ConnectionSockets.size() == NumberOfListen)
			client newcon;
			newcon.tcp_con = ListenSocket->Accept(*RemoteAddress, TEXT("Connection"));
			newcon.last_activ = FPlatformTime::Seconds();
			clients.push_back(newcon);
			if(clients.size() == NumberOfListen)
			{
				WaitingForConnection = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("incoming connection"));

			//Starting async recv thread
			if(!RecvThreadStarted)
			{
				RecvThreadStarted = true;
				ClientConnectionFinishedFuture = Async(EAsyncExecution::LargeThreadPool, [&]() 
					{ //lambda func
						UE_LOG(LogTemp, Warning, TEXT("recv thread started"));
						while (IsConnectionOpen)
						{
							uint32 size;
							TArray<uint8> ReceivedData;
							//for (size_t i = 0; i < ConnectionSockets.size(); i++)
							for(size_t i = 0; i < clients.size(); i++)
							{
								//if ((ConnectionSockets.at(i)->GetConnectionState() == SCS_Connected)&&((LastActivitySockets.at(i)+TimeOutConnection) >= FPlatformTime::Seconds()))
								if(clients.at(i).tcp_con->GetConnectionState() == SCS_Connected && ((clients.at(i).last_activ + TimeOutConnection) >= FPlatformTime::Seconds()))
								{
									//if (ConnectionSockets.at(i)->HasPendingData(size))
									if(clients.at(i).tcp_con->HasPendingData(size))
									{
										ReceivedData.Init(0, 1024);
										int32 Read = 0;
										//ConnectionSockets.at(i)->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
										clients.at(i).tcp_con->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);

										Message(ReceivedData, &clients.at(i));
										//LastActivitySockets.at(i) = FPlatformTime::Seconds();
										clients.at(i).last_activ = FPlatformTime::Seconds();
										if (ReceivedData.Num() > 0)
										{
											if (ReceivedData[0] != 0) {
												UE_LOG(LogTemp, Warning, TEXT("GOT MAIL"));
												int32 bytesend = 0;
												//ConnectionSockets.at(i)->Send(ReceivedData.GetData(), ReceivedData.Num(), bytesend);
												clients.at(i).tcp_con->Send(ReceivedData.GetData(), ReceivedData.Num(), bytesend);
											}
										}
									}
								}
								else 
								{
									// NEED TO BE UPDATED FOR DELETING THE ADDED AGENT
									delete_elem(i);
									WaitingForConnection = true;
								}
							}
						}
					});
			}
		}
	}
}

void AServer::Message(TArray<uint8> msg,client* clientobj)
{
// get from a Tarray of bytes to a string and then to a protobuf
	std::string message;
	for (size_t i = 0; i < msg.Num(); i++)
	{
		message.push_back(msg[i]);
	}
	MessageTCP inbox;

	// TEST FUNC
	inbox.ParseFromString(message);
	std::vector<float> inputvec;
	std::copy(inbox.agent_input().begin(), inbox.agent_input().end(), std::back_inserter(inputvec));
	int id = inbox.agent_id();
	std::string func = inbox.function_call();
	std::string debug = inbox.debug_msg();
	// TEST FUNC
	job jobobj;
	if ((func == "addactor") || (clientobj->agent == nullptr))
	{
		jobobj.func = std::bind(&AServer::AddActor,this,clientobj);
		joblist.push(jobobj);
	}
	if (inputvec.size() > 0)
	{
		jobobj.func = std::bind(&AServer::SetInputActor, this, clientobj, inputvec); // check if u can reuse the same jobobj
		joblist.push(jobobj);
	}
}


// ONLY CALL THIS FUNTION IN THE MAIN THREAD
void AServer::AddActor(client* client)
{
	const FVector spawn_point = FVector(0, 4, 7);
	const FRotator spawn_rotation = FRotator();
	client->agent = GetWorld()->SpawnActor<ACartpole>(YourBlueprintClass);
	//ListOfActors.push_back(GetWorld()->SpawnActor<ACartpole>(YourBlueprintClass)); //GetWorld()->SpawnActor<ACartpole>(mBCCartpole , spawn_point, spawn_rotation));
	//double test = ListOfActors.at(0)->GameTestCart;
}

void AServer::SetInputActor(client* client,std::vector<float> in)
{
	client->agent->SetInput(in);
}