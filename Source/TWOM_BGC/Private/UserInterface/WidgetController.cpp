// Created by Neko Creative Technologies


#include "UserInterface/WidgetController.h"

void UWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerPawn = WidgetControllerParams.PlayerPawn;
}

void UWidgetController::BroadcastInitialValues()
{
}

void UWidgetController::BindCallbacksToDependencies()
{
}
