// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FUE5sim : public IModuleInterface
{
public:
    static inline FUE5sim& Get()
    {
        return FModuleManager::LoadModuleChecked<FUE5sim>("UE5sim");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("UE5sim");
    }

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
