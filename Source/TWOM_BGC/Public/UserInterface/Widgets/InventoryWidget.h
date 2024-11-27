// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "UserInterface/UserWidgetWithController.h"
#include "InventoryWidget.generated.h"


class UInventoryItem;
enum class EItemNames : uint8;

UCLASS()
class TWOM_BGC_API UInventoryWidget : public UUserWidgetWithController
{
	GENERATED_BODY()
	
public:

	virtual void SetWidgetController(UObject* InWidgetController) override;

	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	UInventoryItem* CreateInventoryItemWidget(EItemNames Name, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void RemoveInventoryItemWidget(EItemNames Name);

	

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TMap<EItemNames,int32> Items;

private:

	UPROPERTY(EditAnywhere, Category = "InventoryWidgets")
	TSubclassOf<UInventoryItem> InventoryItemClass;

	UPROPERTY()
	TObjectPtr<UInventoryItem> InventoryItemWidget;

	UPROPERTY()
	TMap<EItemNames,UInventoryItem*> InventoryItemToWidget;
	
};
