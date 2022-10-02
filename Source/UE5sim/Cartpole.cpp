// Fill out your copyright notice in the Description page of Project Settings.


#include "Cartpole.h"

// Sets default values
ACartpole::ACartpole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACartpole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACartpole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACartpole::SetInput(std::vector<float> in)
{
	if (!InputFlag)
	{
		Input = in;
		InputFlag = true;
	}
}

void ACartpole::UseInput(TArray<float> &a_out)
{
	if(InputFlag)
	{
		a_out.SetNumUninitialized(Input.size());
		for (size_t i = 0; i < Input.size(); i++)
		{
			a_out[i] = Input.at(i);
		}
		InputFlag = false;
		UpdateFlag = true;
	}
}

void ACartpole::UpdateState(TArray<float> a_in)
{
	if (!StateFlag && UpdateFlag)
	{
		State.clear();
		for (size_t i = 0; i < a_in.Num(); i++)
		{
			State.push_back(a_in[i]);
		}
		StateFlag = true;
		UpdateFlag = false;
	}
}

std::vector<float> ACartpole::GetState()
{
	if(StateFlag)
	{
		StateFlag = false;
	}
	return State;
}

bool ACartpole::IsNewState()
{
	return StateFlag;
}