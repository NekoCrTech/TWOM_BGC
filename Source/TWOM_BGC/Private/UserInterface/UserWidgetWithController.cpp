// Created by Neko Creative Technologies


#include "UserInterface/UserWidgetWithController.h"

void UUserWidgetWithController::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
