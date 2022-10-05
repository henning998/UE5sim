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
	bool StateFlag = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void UseInput(TArray<float> &a_out);
	UFUNCTION(BlueprintCallable)
	void UpdateState(TArray<float> a_in);
	UFUNCTION(BlueprintCallable)
	void SetRandomStartRotation(FRotator& rot_out);
	UFUNCTION(BlueprintImplementableEvent)
		void ResetEnv();
	UFUNCTION(BlueprintImplementableEvent)
		void Pause();
	UFUNCTION(BlueprintImplementableEvent)
		void Resume();
	UFUNCTION(BlueprintCallable)
		void CallPause();
	UFUNCTION(BlueprintCallable)
		void CallResume();
	UFUNCTION(BlueprintCallable)
		void SetReward(float Reward);
	UFUNCTION(BlueprintCallable)
		void SetDone(bool Done);
	UFUNCTION(BlueprintCallable)
		void GetDone(bool& Done);
	UFUNCTION(BlueprintCallable)
		void GetYLocation(float &y);

	double YLocationActor = 0;

	void SetInput(std::vector<float> in);
	std::vector<float> GetState();
	bool IsNewState();
	bool Done = false;
	float Reward = 0;

private:
	bool InputFlag = false;
	bool UpdateFlag = true; // true to set the first state
	std::vector<float> Input;
	std::vector<float> State;

};
