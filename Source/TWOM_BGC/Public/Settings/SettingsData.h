// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "SettingsData.generated.h"

USTRUCT(BlueprintType)
struct FSettingsData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseMaxQuantity = true;
};
