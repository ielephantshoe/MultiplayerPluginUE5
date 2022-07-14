// Fill out your copyright notice in the Description page of Project Settings.


#include "PMultiPlayerGISubsystem.h"
#include "PMultiPlayerGISubsystem.h"

#include "OnlineSubsystem.h"

UPMultiPlayerGISubsystem::UPMultiPlayerGISubsystem() :
OnCreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)),
OnDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete)),
OnFindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionsComplete)),
OnJoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
OnStartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete))
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if(OnlineSubsystem)
	{
		SessionInterface = OnlineSubsystem->GetSessionInterface();
		if(!SessionInterface.IsValid())
		{
			return;
		}
		
	}
}

void UPMultiPlayerGISubsystem::CreateSession(int32 MaxNumPlayers, FString MatchType)
{
}

void UPMultiPlayerGISubsystem::FindSession(int32 MaxSearchResults)
{
}

void UPMultiPlayerGISubsystem::DestroySession()
{
}

void UPMultiPlayerGISubsystem::JoinSession(const FOnlineSessionSearchResult& FindSessionResult)
{
}

void UPMultiPlayerGISubsystem::StartSession()
{
}

void UPMultiPlayerGISubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UPMultiPlayerGISubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UPMultiPlayerGISubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UPMultiPlayerGISubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{
}

void UPMultiPlayerGISubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
 