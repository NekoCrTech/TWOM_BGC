// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SettingsInterface.generated.h"


UINTERFACE(MinimalAPI)
class USettingsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TWOM_BGC_API ISettingsInterface
{
	GENERATED_BODY()

	
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Settings")
	bool GetUseMaxQuantity();
};
