// Fill out your copyright notice in the Description page of Project Settings.


#include "client.h"

client::client()
{
}

client::~client()
{
	//tcp_con->Close();
}

void client::close()
{
	tcp_con->Close();
}




job::job()
{
}

job::~job()
{
}
void job::run()
{
	
	func();
}