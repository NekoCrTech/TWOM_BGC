// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	None	UMETA(DisplayName = "None"),
	Green	UMETA(DisplayName = "Green"),
	Gray	UMETA(DisplayName = "Gray"),
	Red		UMETA(DisplayName = "Red"),
	Yellow	UMETA(DisplayName = "Yellow"),
	Custom	UMETA(DisplayName = "Custom")
};

UENUM(BlueprintType)
enum class EItemNames : uint8
{
	None				UMETA(DisplayName = "None"),
	Ammo				UMETA(DisplayName = "Ammo")/*9*/,
	AssaultRifle		UMETA(DisplayName = "Assault Rifle")/*2*/,
	BrokenAssaultRifle	UMETA(DisplayName = "Broken Assault Rifle")/*1*/,
	BrokenPistol		UMETA(DisplayName = "Broken Pistol")/*1*/,
	BrokenShotgun		UMETA(DisplayName = "Broken Shotgun")/*1*/,
	Hatchet				UMETA(DisplayName = "Hatchet")/*2*/,
	Knife				UMETA(DisplayName = "Knife")/*3*/,
	Pistol				UMETA(DisplayName = "Pistol")/*2*/,
	Shell				UMETA(DisplayName = "Shell")/*3*/,
	Shotgun				UMETA(DisplayName = "Shotgun")/*2*/,
	WeaponPart			UMETA(DisplayName = "Weapon Part")/*4*/,
	Book				UMETA(DisplayName = "Book")/*3*/,
	BrokenGuitar		UMETA(DisplayName = "Broken Guitar")/*1*/,
	ElectricalPart		UMETA(DisplayName = "Electrical Part")/*4*/,
	Filter				UMETA(DisplayName = "Filter")/*3*/,
	Guitar				UMETA(DisplayName = "Guitar")/*1*/,
	Jewelry				UMETA(DisplayName = "Jewelry")/*2*/,
	Lockpick			UMETA(DisplayName = "Lockpick")/*2*/,
	MechanicalPart		UMETA(DisplayName = "Mechanical Part")/*4*/,
	Sawblade			UMETA(DisplayName = "Sawblade")/*1*/,
	Shovel				UMETA(DisplayName = "Shovel")/*2*/,
	Bandages			UMETA(DisplayName = "Bandages")/*3*/,
	Chems				UMETA(DisplayName = "Chems")/*6*/,
	Herb				UMETA(DisplayName = "Herb")/*3*/,
	HerbalMeds			UMETA(DisplayName = "Herbal Meds")/*3*/,
	Meds				UMETA(DisplayName = "Meds")/*3*/,
	Alcohol				UMETA(DisplayName = "Alcohol")/*3*/,
	CannedFood			UMETA(DisplayName = "Canned Food")/*3*/,
	Cigarette			UMETA(DisplayName = "Cigarette")/*6*/,
	Coffe				UMETA(DisplayName = "Coffe")/*3*/,
	Moonshine			UMETA(DisplayName = "Moonshine")/*3*/,
	RawFood				UMETA(DisplayName = "Raw Food")/*6*/,
	Sugar				UMETA(DisplayName = "Sugar")/*3*/,
	Vegetables			UMETA(DisplayName = "Vegetables")/*6*/
	
};


UENUM(BlueprintType)
enum class EResources : uint8
{
	None		 UMETA(DisplayName = "None"),
	Components   UMETA(DisplayName = "Components")/*14*/,
	Water        UMETA(DisplayName = "Water")/*6*/,
	Wood         UMETA(DisplayName = "Wood")/*12*/
};

USTRUCT(BlueprintType)
struct FResourcesData : public FTableRowBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EResources Resource = EResources::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity = 0;	
};


USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemNames Name = EItemNames::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemCategory Category = EItemCategory::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Cost = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Weight = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity = 1;

	// Default constructor
	FItemData()
		: Name(EItemNames::None),
		  Category(EItemCategory::None),
		  Cost(0),
		  Weight(0),
		  Quantity(1)
	{}

	// Parameterized constructor
	FItemData(EItemNames InName, EItemCategory InCategory, int32 InCost, int32 InWeight, int32 InQuantity)
		: Name(InName),
		  Category(InCategory),
		  Cost(InCost),
		  Weight(InWeight),
		  Quantity(InQuantity)
	{}
};



