// Fill out your copyright notice in the Description page of Project Settings.


#include "Server.h"
THIRD_PARTY_INCLUDES_START

#include "MyMessage.pb.h"

THIRD_PARTY_INCLUDES_END

// Sets default values
AServer::AServer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UBlueprint> blueprint_finder_test(TEXT("Blueprint'/Game/Blueprints/cartpoletest.cartpoletest'"));
	if (blueprint_finder_test.Succeeded())
		mBCTest = (UClass*)blueprint_finder_test.Object->GeneratedClass;
	static ConstructorHelpers::FObjectFinder<UBlueprint> blueprint_finder_cartpole(TEXT("Blueprint'/Game/Blueprints/BP_Cartpole.BP_Cartpole'"));
	if (blueprint_finder_cartpole.Succeeded())
		mBCCartpole = (UClass*)blueprint_finder_cartpole.Object->GeneratedClass;
	

}

// Called when the game starts or when spawned
void AServer::BeginPlay()
{
	Open_Connection();
	AddActor();
	Super::BeginPlay();
	
}

// Called every frame
void AServer::Tick(float DeltaTime)
{
	Conduct_Connection();
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
			ConnectionSockets.push_back(ListenSocket->Accept(*RemoteAddress, TEXT("Connection")));
			LastActivitySockets.push_back(FPlatformTime::Seconds());
			if(ConnectionSockets.size() == NumberOfListen)
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
							for (size_t i = 0; i < ConnectionSockets.size(); i++)
							{
								if ((ConnectionSockets.at(i)->GetConnectionState() == SCS_Connected)&&((LastActivitySockets.at(i)+TimeOutConnection) >= FPlatformTime::Seconds()))
								{
									if (ConnectionSockets.at(i)->HasPendingData(size))
									{
										ReceivedData.Init(0, 10);
										int32 Read = 0;
										ConnectionSockets.at(i)->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
										Message(ReceivedData);
										LastActivitySockets.at(i) = FPlatformTime::Seconds();
										if (ReceivedData.Num() > 0)
										{
											if (ReceivedData[0] != 0) {
												UE_LOG(LogTemp, Warning, TEXT("GOT MAIL"));
												int32 bytesend = 0;
												ConnectionSockets.at(i)->Send(ReceivedData.GetData(), ReceivedData.Num(), bytesend);
											}
										}
									}
								}
								else 
								{
									// NEED TO BE UPDATED FOR DELETING THE ADDED AGENT
									ConnectionSockets.at(i)->Close();
									ConnectionSockets.erase(ConnectionSockets.begin() + i);
									LastActivitySockets.erase(LastActivitySockets.begin() + i);
									WaitingForConnection = true;
								}
							}
						}
					});
			}
		}
	}
}

void AServer::Message(TArray<uint8> msg)
{
// get from a Tarray of bytes to a string and then to a protobuf
	std::string message;
	for (size_t i = 0; i < msg.Num(); i++)
	{
		message.push_back(msg[i]);
	}
	MyMessage inbox;
	inbox.ParseFromString(message);
	double num = inbox.mynumber();
	std::string st = inbox.mystring();
	//AddActor();
	// add func to add agent and set input
}

void AServer::AddActor()
{
	const FVector spawn_point = FVector(0, 4, 7);
	const FRotator spawn_rotation = FRotator();
	ListOfActors.push_back(GetWorld()->SpawnActor<ACartpole>(mBCCartpole, spawn_point, spawn_rotation));
	double test = ListOfActors.at(0)->GameTestCart;
}

void AServer::SetInputActor()
{

}