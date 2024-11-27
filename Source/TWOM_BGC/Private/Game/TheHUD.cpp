// Created by Neko Creative Technologies


#include "Game/TheHUD.h"

#include "Blueprint/UserWidget.h"
#include "UserInterface/Controllers/InventoryWidgetController.h"
#include "UserInterface/UserWidgetWithController.h"

void ATheHUD::BeginPlay()
{
	Super::BeginPlay();
}

void ATheHUD::InitInventory(APawn* P, APlayerController* PC)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),InventoryWidgetClass);
	InventoryWidget = Cast<UUserWidgetWithController>(Widget);

	const FWidgetControllerParams WidgetControllerParams(P,PC);
	UInventoryWidgetController* WidgetController = GetInventoryWidgetController(WidgetControllerParams);

	InventoryWidget->SetWidgetController(InventoryWidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}

UInventoryWidgetController* ATheHUD::GetInventoryWidgetController(
	const FWidgetControllerParams& InWidgetControllerParams)
{
	if (InventoryWidgetController == nullptr)
	{
		InventoryWidgetController = NewObject<UInventoryWidgetController>(this, InventoryWidgetControllersClass);
		InventoryWidgetController->SetWidgetControllerParams(InWidgetControllerParams);
		InventoryWidgetController->BindCallbacksToDependencies();
	}
	return InventoryWidgetController;
}




