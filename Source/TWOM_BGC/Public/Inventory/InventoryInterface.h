// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryInterface.generated.h"

struct FItemData;
enum class EResources : uint8;
enum class EItemNames : uint8;

UINTERFACE(MinimalAPI)
class UInventoryInterface : public UInterface
{
	GENERATED_BODY()
};


class TWOM_BGC_API IInventoryInterface
{
	GENERATED_BODY()

public:

	// Items
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Items")
	bool CanAddItem(EItemNames Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Items")
	bool CanRemoveItem(EItemNames Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Items")
	void AddItem(EItemNames Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Items")
	void RemoveItem(EItemNames Name);

	virtual FItemData* GetDefaultsOfItem(EItemNames Name) = 0;


	//Resources
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Resources")
	bool CanAddResource(EResources Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Resources")
	bool CanRemoveResource(EResources Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Resources")
	void AddResource(EResources Name);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Resources")
	void RemoveResource(EResources Name);


	
};
