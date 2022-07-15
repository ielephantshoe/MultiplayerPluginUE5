// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

#include "PMultiPlayerGISubsystem.h"
#include "Components/Button.h"
 
void UMenu::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	UWorld* World = GetWorld();
	if(World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if(PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(this->TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
	UGameInstance* GameInstance = GetGameInstance();
	if(GameInstance)
	{
	  GISubsystem  =	GameInstance->GetSubsystem<UPMultiPlayerGISubsystem>();
	}
}

void UMenu::MenuTearDown()
{
	RemoveFromParent();
	 UWorld* World = GetWorld();
	
	if(World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if(PlayerController)
		{
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}

bool UMenu::Initialize()
{
	if(!Super::Initialize())
	{
		return false;
	}
	if(HostButton)
	{
		HostButton->OnClicked.AddDynamic(this, &ThisClass::HostButtonPressed);
	}
	if(JoinButton)
	{
		JoinButton->OnClicked.AddDynamic(this, &ThisClass::JoinButtonPressed);
	}
	return true;
}

void UMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	MenuTearDown();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}

void UMenu::HostButtonPressed()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Hosting"));
	
	}
	 if(GISubsystem)
	 {
		 GISubsystem->CreateSession(4,FString("FreeForAll"));
	 	UWorld* World = GetWorld();
	 			if(World)
	 			{
	 				World->ServerTravel("/Game/Maps/Lobby?listen");
	 			}
	 }
}

 
void UMenu::JoinButtonPressed()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Joining"));
	}
}

 