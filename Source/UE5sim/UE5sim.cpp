// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5sim.h"
#include "Modules/ModuleManager.h"
#include "Wakefield/Print.h"

THIRD_PARTY_INCLUDES_START

#include "MyMessage.pb.h"

THIRD_PARTY_INCLUDES_END


void FUE5sim::StartupModule()
{
    Print("Starting up UE5sim module");

    Print("Serializing test protobuf...");
    MyMessage MyMessage1;
    MyMessage1.set_mynumber(42);
    MyMessage1.set_mystring("foo");

    std::string MyMessageSerialized;
    MyMessage1.SerializeToString(&MyMessageSerialized);

    MyMessage MyMessage2;

    Print("Deserializing test protobuf...");
    MyMessage2.ParseFromString(MyMessageSerialized);

    Print(FromStd(MyMessage2.DebugString()));
    check(MyMessage1.mynumber() == MyMessage2.mynumber());
    check(MyMessage1.mystring() == MyMessage2.mystring());
}

void FUE5sim::ShutdownModule()
{
    Print("Shutting down UE5sim module");
}

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, UE5sim, "UE5sim" );
