// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "UserInterface/WidgetController.h"
#include "InventoryWidgetController.generated.h"

struct FItemData;
enum class EItemNames : uint8;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemChangedSignature, EItemNames, ItemChanged, int32, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResourceChangedSignature, EResources, ResourceChanged, int32, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryItemDestroyed, EItemNames, Name);

UCLASS(BlueprintType, Blueprintable)
class TWOM_BGC_API UInventoryWidgetController : public UWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable,Category = "Inventory")
	FOnItemChangedSignature OnItemChanged;
	UPROPERTY(BlueprintAssignable,Category = "Inventory")
	FOnResourceChangedSignature OnResourceChanged;
	UPROPERTY(BlueprintAssignable,Category = "Inventory")
	FOnInventoryItemDestroyed OnInventoryItemDestroyed;
	

	FItemData* GetDataFromPawn(EItemNames Name) const;

	void GetBoolData( EItemNames Name, bool& bCanAddIn, bool& bCanRemoveIn);

	UFUNCTION(BlueprintCallable)
	void InventoryItemRemoved(EItemNames Name);
	
};
