// Created by Neko Creative Technologies


#include "UserInterface/Widgets/InventoryItem.h"

#include "UserInterface/Controllers/InventoryWidgetController.h"

void UInventoryItem::SetWidgetController(UObject* InWidgetController)
{
	Super::SetWidgetController(InWidgetController);
	if (UInventoryWidgetController* InventoryWidgetController = Cast<UInventoryWidgetController>(WidgetController))
	{
		ItemData = InventoryWidgetController->GetDataFromPawn(Name);
		InventoryWidgetController->GetBoolData(Name,bCanAdd,bCanRemove);
		UpdateVisualData(GetItemData(),bCanAdd,bCanRemove);
	}
}

void UInventoryItem::RemoveFromParent()
{
	if (UInventoryWidgetController* InventoryWidgetController = Cast<UInventoryWidgetController>(WidgetController))
	{
		InventoryWidgetController->InventoryItemRemoved(Name);
	}
	
	Super::RemoveFromParent();
}

void UInventoryItem::SetNameAndQuantity(const EItemNames NameIn, const int32 QuantityIn)
{
	Name = NameIn;
	Quantity = QuantityIn;
}

void UInventoryItem::UpdateQuantity(int32 QuantityIn)
{
	Quantity = QuantityIn;
	if (UInventoryWidgetController* InventoryWidgetController = Cast<UInventoryWidgetController>(WidgetController))
	{
		InventoryWidgetController->GetBoolData(Name,bCanAdd,bCanRemove);
	}
	UpdateVisualData(GetItemData(),bCanAdd,bCanRemove);
}


FItemData UInventoryItem::GetItemData() const
{
	return FItemData(Name,ItemData->Category,ItemData->Cost,ItemData->Weight,Quantity);
}

