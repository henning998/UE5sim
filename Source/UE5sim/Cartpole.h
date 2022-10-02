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
	UFUNCTION(BlueprintCallable)
	void UseInput(TArray<float> &a_out);
	UFUNCTION(BlueprintCallable)
	void UpdateState(TArray<float> a_in);


	void SetInput(std::vector<float> in);
	std::vector<float> GetState();
	bool IsNewState();

private:
	bool InputFlag = false;
	bool StateFlag = false;
	bool UpdateFlag = true; // true to set the first state
	std::vector<float> Input;
	std::vector<float> State;
	//double GameTestCart = 420.69;

};
