// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include "Cartpole.h"
#include "client.h"
#include <queue>

#include "Server.generated.h"


UCLASS()
class UE5SIM_API AServer : public AActor
{
	GENERATED_BODY()
	FSocket* ListenSocket;
	std::vector<client> clients;
	std::queue<job> joblist;
	//std::vector<FSocket*> ConnectionSockets;
	//std::vector<double> LastActivitySockets;
	bool IsConnectionOpen = false;
	bool WaitingForConnection = false;
	bool RecvThreadStarted = false;
	//bool SendingTheardStarted = false;
	int NumberOfListen = 10;
	double TimeOutConnection = 60; // seconds


	TFuture<void> RecvTheard;
	//TFuture<void> SendingTheard;

	void delete_elem(size_t i);
	float GetValidPositionForAgent();

public:	
	// Sets default values for this actor's properties
	AServer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void Open_Connection();
	void Close_Connection();
	void Conduct_Connection();
	void Message(TArray<uint8> msg,client* client);
	void AddActor(client* client);
	void SetInputActor(client* client, std::vector<float> in);
	void GetStateActor(client* client);
	void ResetActor(client* client);

	//UClass* mBCTest = nullptr;
	//UClass* mBCCartpole = nullptr;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> YourBlueprintClass;
	std::vector<float> ListOfAgentPos;
};
