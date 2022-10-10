// Fill out your copyright notice in the Description page of Project Settings.


#include "client.h"
THIRD_PARTY_INCLUDES_START

#include "MessageTCP.pb.h"

THIRD_PARTY_INCLUDES_END

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
	agent->Destroy();
}


void client::SendNewState()
{
	if (agent != nullptr)
	{
		if (agent->IsNewState())
		{
			MessageTCP sendbox;
			sendbox.set_agent_id(id);
			std::vector<float> state = agent->GetState();
			sendbox.mutable_env_state()->Add(state.begin(), state.end()); // instead of a for loop
			if (agent->Done)
			{
				sendbox.set_done(true);
				sendbox.set_reward(agent->Reward);
			}
			else
			{
				sendbox.set_done(false);
			}
			std::string sendstr = sendbox.SerializeAsString();
			TArray<uint8> senddata;
			senddata.SetNumUninitialized(sendstr.size());
			for (size_t k = 0; k < sendstr.size(); k++)
			{
				senddata[k] = sendstr.at(k);
			}
			int32 NumberOfBytesSend = 0;
			tcp_con->Send(senddata.GetData(), senddata.Num(), NumberOfBytesSend);
		}
	}
}

void client::SendMSG(std::string msg)
{
	if (msg.size() > 0)
	{
		TArray<uint8> senddata;
		senddata.SetNumUninitialized(msg.size());
		for (size_t k = 0; k < msg.size(); k++)
		{
			senddata[k] = msg.at(k);
		}
		int32 NumberOfBytesSend = 0;
		tcp_con->Send(senddata.GetData(), senddata.Num(), NumberOfBytesSend);
	}
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