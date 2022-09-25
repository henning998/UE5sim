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

void ACartpole::SetInput(std::vector<double> in)
{
	Input = in;
	InputFlag = true;
}

void ACartpole::UseInput(float &a_out)
{ 
	a_out = GameTestCart;
}

void ACartpole::SetState()
{
	
}

std::vector<double> ACartpole::GetState()
{
	StateFlag = false;
	return State;
}

