// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Settings/SettingsData.h"
#include "GameFramework/Pawn.h"
#include "Inventory/InventoryInterface.h"
#include "Delegates/DelegateCombinations.h" 
#include "Twom_Pawn.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnItemsChanged, EItemNames, int32);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnResourcesChanged, EResources,int32);

enum class EResources : uint8;
enum class EItemNames : uint8;
class UItemsDataAsset;

UCLASS(Blueprintable, BlueprintType)
class TWOM_BGC_API ATwom_Pawn : public APawn, public IInventoryInterface
{
	GENERATED_BODY()

public:
	
	FOnItemsChanged OnItemsChanged;
	FOnResourcesChanged OnResourcesChanged;
	
	FORCEINLINE FOnItemsChanged& GetItemDelegate() {return OnItemsChanged;}
	FORCEINLINE FOnResourcesChanged& GetResourcesDelegate() {return OnResourcesChanged;}
	
	ATwom_Pawn();

	/*Inventory Interface*/
	virtual bool CanAddItem_Implementation(EItemNames Name) override;
	virtual bool CanRemoveItem_Implementation(EItemNames Name) override;
	virtual void AddItem_Implementation(EItemNames Name) override;
	virtual void RemoveItem_Implementation(EItemNames Name) override;
	
	virtual bool CanAddResource_Implementation(EResources Name) override;
	virtual bool CanRemoveResource_Implementation(EResources Name) override;
	virtual void AddResource_Implementation(EResources Name) override;
	virtual void RemoveResource_Implementation(EResources Name) override;

	virtual FItemData* GetDefaultsOfItem(EItemNames Name) override;
	/*------------------*/
	
	FORCEINLINE TMap<EItemNames,int32>& GetItems() { return OwnedItems; }
	FORCEINLINE TMap<EResources,int32>& GetResources() { return OwnedResources; }

protected:
	
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditDefaultsOnly, Category = "Data|Settings")
	FSettingsData SettingsData;
	
	UPROPERTY(EditDefaultsOnly, Category = "Data|Items")
	UItemsDataAsset* ItemsDataAsset;

	UPROPERTY()
	TMap<EItemNames,int32> OwnedItems;

	UPROPERTY()
	TMap<EResources,int32> OwnedResources;

	UFUNCTION()
	bool GetUseMax() const;

	void InitInventory();
	
};

