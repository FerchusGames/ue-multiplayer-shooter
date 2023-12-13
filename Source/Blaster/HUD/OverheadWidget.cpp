// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"


void UOverheadWidget::SetDisplayText(const FString& TextToDisplay) const
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(const APawn* InPawn) const
{
	const ENetRole RemoteRole = InPawn->GetRemoteRole();
	
	FString Role;
	
	switch (RemoteRole)
	{
	case ROLE_Authority:
		Role = FString("Authority");
		break;

	case ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;

	case ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;

	case ENetRole::ROLE_None:
		Role = FString("None");
		break;

	case ENetRole::ROLE_MAX:
		Role = FString("Max");
		break;
	}

	const FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);

	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	const APlayerState* PlayerState = InPawn->GetPlayerState();
	if(!PlayerState || !*PlayerState->GetPlayerName() && TotalTime < GetPlayerNameTimeout)
	{
		FTimerHandle GetPlayerStateTimer;
		FTimerDelegate TryAgainDelegate;
		TryAgainDelegate.BindUFunction(this, FName("ShowPlayerName"), InPawn);
		GetWorld()->GetTimerManager().SetTimer(GetPlayerStateTimer, TryAgainDelegate, GetPlayerNameInterval, false, 0.1f);
		TotalTime += GetPlayerNameInterval;
		return;
	}
	const FString PlayerName = InPawn->GetPlayerState()->GetPlayerName();
	SetDisplayText(PlayerName);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
