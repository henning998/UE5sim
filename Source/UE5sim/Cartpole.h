// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>

#include "Cartpole.generated.h"

UCLASS()
class UE5SIM_API ACartpole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACartpole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool InputFlag = false;
	bool StateFlag = false;
	std::vector<double> Input;
	std::vector<double> State;
	double GameTestCart = 420.69;

	void SetInput(std::vector<double> in);
	UFUNCTION(BlueprintCallable)
	void UseInput(float &a_out);
	void SetState();
	std::vector<double> GetState();


};
