// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "Item/ItemData.h"
#include "UserInterface/UserWidgetWithController.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class TWOM_BGC_API UInventoryItem : public UUserWidgetWithController
{
	GENERATED_BODY()

public:
	
	FItemData* ItemData = nullptr;

	virtual void SetWidgetController(UObject* InWidgetController) override;
	virtual void RemoveFromParent() override;

	void SetNameAndQuantity(EItemNames NameIn, int32 QuantityIn);
	void UpdateQuantity(int32 QuantityIn);
	
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisualData(FItemData Data,bool bCanAddOut, bool bCanRemoveOut);

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	EItemNames Name = EItemNames::None;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	int32 Quantity = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	bool bCanAdd = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Data", meta = (AllowPrivateAccess = "true"))
	bool bCanRemove = false;

	FItemData GetItemData() const;
		
};



