// Copyright Epic Games, Inc. All Rights Reserved.

#include "R1.h"
#include "Modules/ModuleManager.h"

#include "R1LogChannels.h"

class FR1Module : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		UE_LOG(LogR1, Display, TEXT("R1 Module started"));
	}
	virtual void ShutdownModule() override;
};

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, R1, "R1" );
