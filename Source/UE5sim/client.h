// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Cartpole.h"
#include <functional>

/**
 * 
 */
class UE5SIM_API client
{
public:
	double id;
	FSocket* tcp_con;
	double last_activ;
	ACartpole* agent;
	client();
	~client();
	void close();
};


class UE5SIM_API job
{
public:
	job();
	~job();

	std::function<void(void)> func = nullptr;
	std::function<void(int)> func_int = nullptr;
	
private:

};
