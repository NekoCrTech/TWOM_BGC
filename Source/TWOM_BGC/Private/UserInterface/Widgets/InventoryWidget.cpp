// Created by Neko Creative Technologies


#include "UserInterface/Widgets/InventoryWidget.h"
#include "UserInterface/Widgets/InventoryItem.h"
#include "Blueprint/UserWidget.h"
#include "UserInterface/Controllers/InventoryWidgetController.h"


void UInventoryWidget::SetWidgetController(UObject* InWidgetController)
{
	Super::SetWidgetController(InWidgetController);
	if (UInventoryWidgetController* InventoryWidgetController = Cast<UInventoryWidgetController>(WidgetController))
	{
		InventoryWidgetController->OnInventoryItemDestroyed.AddUniqueDynamic(this,UInventoryWidget::RemoveInventoryItemWidget);
	}
}

UInventoryItem* UInventoryWidget::CreateInventoryItemWidget(EItemNames Name, int32 Quantity)
{
	if (InventoryItemToWidget.Contains(Name))
	{
		UInventoryItem* InventoryItem = InventoryItemToWidget[Name];
		InventoryItem->UpdateQuantity(Quantity);
		return nullptr;
	}
	//create new widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),InventoryItemClass,FName("InventoryItem"));
	UInventoryItem* InventoryItem = Cast<UInventoryItem>(Widget);
	InventoryItem->SetNameAndQuantity(Name, Quantity);
	InventoryItem->SetWidgetController(WidgetController);
	InventoryItemToWidget.Emplace(Name, InventoryItem);
	return InventoryItem;
}

void UInventoryWidget::RemoveInventoryItemWidget(EItemNames Name)
{
	InventoryItemToWidget.Remove(Name);
}
