// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PMultiPlayerGISubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PMULTIPLAYER_API UPMultiPlayerGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPMultiPlayerGISubsystem();

	void CreateSession(int32 MaxNumPlayers, FString MatchType);
	void FindSession(int32 MaxSearchResults);
	void DestroySession();
	void JoinSession(const FOnlineSessionSearchResult& FindSessionResult);
	void StartSession();
	


 
protected:
	void  OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);

 
private:
	IOnlineSessionPtr SessionInterface;

    FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
};
