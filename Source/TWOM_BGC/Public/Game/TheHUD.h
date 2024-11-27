// Created by Neko Creative Technologies

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TheHUD.generated.h"

class UUserWidgetWithController;
struct FWidgetControllerParams;
class UInventoryWidgetController;
class UInventoryWidget;

UCLASS()
class TWOM_BGC_API ATheHUD : public AHUD
{
	GENERATED_BODY()
public:
	UInventoryWidgetController* GetInventoryWidgetController(const FWidgetControllerParams& InWidgetControllerParams);

	void InitInventory(APawn* P, APlayerController* PC);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidgetWithController> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets|Controllers")
	TSubclassOf<UInventoryWidgetController> InventoryWidgetControllersClass;

	UPROPERTY()
	TObjectPtr<UUserWidgetWithController> InventoryWidget;

	UPROPERTY()
	TObjectPtr<UInventoryWidgetController> InventoryWidgetController;
	
};
