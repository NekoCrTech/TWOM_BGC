// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.h"
#include "ItemsDataAsset.generated.h"


UCLASS()
class TWOM_BGC_API UItemsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Item Data")
	int32 GetItemMaxQuantity(EItemNames Name) const;

	UFUNCTION(BlueprintCallable, Category = "Item Data")
	int32 GetResourceMaxQuantity(EResources Name) const;

	FItemData* GetItemData(EItemNames Name) const;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTables")
	UDataTable* Items;

	UPROPERTY(EditDefaultsOnly, Category = "DataTables")
	UDataTable* Resources;	
};
