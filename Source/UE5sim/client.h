// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Cartpole.h"
#include <functional>
//#include <mutex>

/**
 * 
 */
class UE5SIM_API client
{
public:
	//std::mutex mutex;
	double id;
	FSocket* tcp_con;
	double last_activ;
	ACartpole* agent = nullptr;
	client();
	~client();
	void close();
	// checks if agent have new state and send it to client if true
	void SendNewState();
	void SendMSG(std::string msg);
	bool slet = false;
	bool delete_agent = false;
};


class UE5SIM_API job
{
public:
	job();
	~job();
	//client* agent;
	std::function<void(void)> func = nullptr;
	std::function<void(int)> func_int = nullptr;
	void run();
private:

};
