// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"

#include "Server.generated.h"

UCLASS()
class UE5SIM_API AServer : public AActor
{
	GENERATED_BODY()
	FSocket* ListenSocket;
	FSocket* ConnectionSocket;
	bool IsConnectionOpen = false;
	bool WaitingForConnection = false;

	TFuture<void> ClientConnectionFinishedFuture;

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
};