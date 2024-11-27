// Created by Neko Creative Technologies


#include "UserInterface/Controllers/InventoryWidgetController.h"
#include "Game/Twom_Pawn.h"
#include "Item/ItemData.h"
#include "Inventory/InventoryInterface.h"

void UInventoryWidgetController::BroadcastInitialValues()
{
	ATwom_Pawn* TwomPawn = CastChecked<ATwom_Pawn>(PlayerPawn);

	if (TwomPawn->GetItems().Num()>0)
	{
		for (TTuple<EItemNames, int> Item : TwomPawn->GetItems())
		{
			OnItemChanged.Broadcast(Item.Key, Item.Value);			
		}
	}
	if (TwomPawn->GetResources().Num()>0)
	{
		for (TTuple<EResources, int> Item : TwomPawn->GetResources())
		{
			OnResourceChanged.Broadcast(Item.Key, Item.Value);			
		}
	}
			
	
}

void UInventoryWidgetController::BindCallbacksToDependencies()
{
	ATwom_Pawn* TwomPawn = CastChecked<ATwom_Pawn>(PlayerPawn);
	
	TwomPawn->OnItemsChanged.AddLambda		([this](const EItemNames ItemChanged, const int32 NewQuantity)	{OnItemChanged.Broadcast(ItemChanged,NewQuantity);});
	TwomPawn->OnResourcesChanged.AddLambda	([this](const EResources ResourceChanged,const int32 NewQuantity)	{OnResourceChanged.Broadcast(ResourceChanged,NewQuantity);});
}

FItemData* UInventoryWidgetController::GetDataFromPawn(const EItemNames Name) const
{
	IInventoryInterface* Inventory = CastChecked<IInventoryInterface>(PlayerPawn);

	
	return Inventory->GetDefaultsOfItem(Name);
}

void UInventoryWidgetController::GetBoolData(EItemNames Name, bool& bCanAddIn, bool& bCanRemoveIn)
{
	bCanAddIn = IInventoryInterface::Execute_CanAddItem(PlayerPawn,Name);
	bCanRemoveIn = IInventoryInterface::Execute_CanRemoveItem(PlayerPawn,Name);
}

void UInventoryWidgetController::InventoryItemRemoved(EItemNames Name)
{
	OnInventoryItemDestroyed.Broadcast(Name);
}

