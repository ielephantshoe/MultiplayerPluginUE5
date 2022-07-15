// Fill out your copyright notice in the Description page of Project Settings.


#include "PMultiPlayerGISubsystem.h"
#include "PMultiPlayerGISubsystem.h"

#include "OnlineSubsystem.h"

UPMultiPlayerGISubsystem::UPMultiPlayerGISubsystem() :
OnCreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)),
OnJoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
OnDestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete)),
OnFindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionsComplete)),
OnStartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete))
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if(OnlineSubsystem)
	{
		SessionInterface = OnlineSubsystem->GetSessionInterface();
		
	}
}

void UPMultiPlayerGISubsystem::CreateSession(int32 MaxNumPlayers, FString MatchType)
{
	if(!SessionInterface.IsValid())
	{
		return;
	}
	auto ExistingSession = SessionInterface->GetNamedSession(NAME_GameSession);
	if(ExistingSession != nullptr)
	{
		SessionInterface->DestroySession(NAME_GameSession);
	}
	 
	OnCreateSessionCompleteDelegateHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);
		
	LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	LastSessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	LastSessionSettings->NumPublicConnections = MaxNumPlayers;
	LastSessionSettings->bAllowJoinInProgress = true;
	LastSessionSettings->bAllowInvites = true;
	LastSessionSettings->bAllowJoinViaPresence = true;
	LastSessionSettings->bShouldAdvertise = true;
	LastSessionSettings->bUsesPresence = true;
	LastSessionSettings->Set("MatchType", FString(MatchType), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if(!SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings))
	{
		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
	}
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
 