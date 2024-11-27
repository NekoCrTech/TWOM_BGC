// Created by Neko Creative Technologies


#include "Game/Twom_Pawn.h"

#include "Game/TheHUD.h"
#include "Game/ThePlayerController.h"
#include "Item/ItemsDataAsset.h"


ATwom_Pawn::ATwom_Pawn(): ItemsDataAsset(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATwom_Pawn::BeginPlay()
{
	Super::BeginPlay();
	InitInventory();
	
}

bool ATwom_Pawn::GetUseMax() const
{
	return SettingsData.bUseMaxQuantity;
}

void ATwom_Pawn::InitInventory()
{
	if (AThePlayerController* ThePlayerController = Cast<AThePlayerController>(GetController()))
	{
		if (ATheHUD* TheHUD = Cast<ATheHUD>(ThePlayerController->GetHUD()))
		{
			TheHUD->InitInventory(this, ThePlayerController);
		}
	}
}


//Inventory Interface

bool ATwom_Pawn::CanAddItem_Implementation(const EItemNames Name)
{
	if (GetUseMax())
	{
		if (OwnedItems.Contains(Name))
		{
			int32 Max = ItemsDataAsset->GetItemMaxQuantity(Name);
			if (Max > 0)
			{
				int32 OwnedQuantity = OwnedItems.FindRef(Name);
				if (OwnedQuantity == Max)
				{
					return false;
				}
				return true;
			}
			// Must Never Happen
			UE_LOG(LogTemp,Error,TEXT("ATwom_Pawn: Cannot get Item Max Quantity"));
			return false;
		}
	}
	return true;
}
bool ATwom_Pawn::CanRemoveItem_Implementation(EItemNames Name)
{
	if (OwnedItems.FindRef(Name)>0)
	{
		return true;
	}
	return false;
}
void ATwom_Pawn::AddItem_Implementation(const EItemNames Name)
{
	if (Execute_CanAddItem(this,Name))
	{
		if (OwnedItems.Num()>0 && OwnedItems.Contains(Name))
		{
			const int32 OwnedQuantity = OwnedItems.FindRef(Name);
			OwnedItems.Add(Name,OwnedQuantity+1);
			OnItemsChanged.Broadcast(Name,OwnedItems.FindRef(Name));
			return;
		}
		
		OwnedItems.Emplace(Name,1);
		GEngine->AddOnScreenDebugMessage(1,5.f,FColor::Red,"Adding Item");
		OnItemsChanged.Broadcast(Name,OwnedItems.FindRef(Name));
	}
}
void ATwom_Pawn::RemoveItem_Implementation(EItemNames Name)
{
	if (Execute_CanRemoveItem(this,Name))
	{
		const int32 OwnedQuantity = OwnedItems.FindRef(Name);
		OwnedItems.Add(Name,OwnedQuantity-1);
		OnItemsChanged.Broadcast(Name,OwnedItems.FindRef(Name));
	}
}


bool ATwom_Pawn::CanAddResource_Implementation(EResources Name)
{
	if (GetUseMax())
	{
		if (OwnedItems.Num()>0 && OwnedResources.Contains(Name))
		{
			int32 Max = ItemsDataAsset->GetResourceMaxQuantity(Name);
			if (Max > 0)
			{
				int32 OwnedQuantity = OwnedResources.FindRef(Name);
				if (OwnedQuantity == Max)
				{
					return false;
				}
				return true;
			}
			// Must Never Happen
			UE_LOG(LogTemp,Error,TEXT("ATwom_Pawn: Cannot get Resource Max Quantity"));
			return false;
		}
	}
	return true;
}
bool ATwom_Pawn::CanRemoveResource_Implementation(EResources Name)
{
	if (OwnedResources.FindRef(Name)>0)
	{
		return true;
	}
	return false;
}
void ATwom_Pawn::AddResource_Implementation(EResources Name)
{
	if (Execute_CanAddResource(this, Name))
	{
		if (OwnedResources.Contains(Name))
		{
			const int32 OwnedQuantity = OwnedResources.FindRef(Name);
			OwnedResources.Add(Name,OwnedQuantity+1);
			OnResourcesChanged.Broadcast(Name,OwnedResources.FindRef(Name));
			return;
		}
		OwnedResources.Add(Name,1);
		OnResourcesChanged.Broadcast(Name,1);
	}
}
void ATwom_Pawn::RemoveResource_Implementation(EResources Name)
{
	if (Execute_CanRemoveResource(this, Name))
	{
		const int32 OwnedQuantity = OwnedResources.FindRef(Name);
		OwnedResources.Add(Name,OwnedQuantity-1);
		OnResourcesChanged.Broadcast(Name,OwnedResources.FindRef(Name));
	}
}

FItemData* ATwom_Pawn::GetDefaultsOfItem(EItemNames Name)
{
	return ItemsDataAsset->GetItemData(Name);
}






