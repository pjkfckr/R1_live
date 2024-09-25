#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FR1EditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
