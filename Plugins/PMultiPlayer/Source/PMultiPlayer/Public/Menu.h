// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"
 
UCLASS()
class PMULTIPLAYER_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup();

	UFUNCTION(BlueprintCallable)
	void MenuTearDown();

protected:
	virtual bool Initialize() override;
    virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;
	
	UPROPERTY(meta = (BindWidget))
	 UButton* HostButton;

	UFUNCTION()
	 void HostButtonPressed();

	UFUNCTION()
	void JoinButtonPressed();

	// THe Subsystem that handles the online multiplayer tasks
	class UPMultiPlayerGISubsystem* GISubsystem;


	
};
