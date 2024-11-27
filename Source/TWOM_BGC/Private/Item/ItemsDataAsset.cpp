// Created by Neko Creative Technologies


#include "Item/ItemsDataAsset.h"


int32 UItemsDataAsset::GetItemMaxQuantity(EItemNames Name) const
{
	const FName EnumAsName = FName(*StaticEnum<EItemNames>()->GetNameStringByValue((int64)Name));
	if (const FItemData* ItemData = Items->FindRow<FItemData>(EnumAsName,TEXT("")))
	{
		return ItemData->Quantity;
	}
	return -1;
}

int32 UItemsDataAsset::GetResourceMaxQuantity(EResources Name) const
{
	const FName EnumAsName = FName(*StaticEnum<EResources>()->GetNameStringByValue((int64)Name));
	if (const FItemData* ItemData = Resources->FindRow<FItemData>(EnumAsName,TEXT("")))
	{
		return ItemData->Quantity;
	}
	return -1;
}

FItemData* UItemsDataAsset::GetItemData(EItemNames Name) const
{
	const FName EnumAsName = FName(*StaticEnum<EItemNames>()->GetNameStringByValue((int64)Name));
	if (FItemData* ItemData = Items->FindRow<FItemData>(EnumAsName,TEXT("")))
	{
		return ItemData;
	}
	return nullptr;
}
