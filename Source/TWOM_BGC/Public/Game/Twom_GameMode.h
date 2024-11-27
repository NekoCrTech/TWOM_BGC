// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingsInterface.h"
#include "GameFramework/GameModeBase.h"
#include "Item/ItemsDataAsset.h"
#include "Settings/SettingsData.h"
#include "Twom_GameMode.generated.h"


struct FSettingsData;

UCLASS()
class TWOM_BGC_API ATwom_GameMode : public AGameModeBase , public ISettingsInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

};
