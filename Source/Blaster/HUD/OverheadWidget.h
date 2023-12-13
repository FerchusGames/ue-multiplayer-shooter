// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DisplayText;

	void SetDisplayText(const FString& TextToDisplay) const;

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(const APawn* InPawn) const;

	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APawn* InPawn);
	
protected:
	virtual void NativeDestruct() override;

private:
	UPROPERTY(EditAnywhere, Category="Overhead Widget Properties", meta=(AllowPrivateAccess=true, Units="Seconds"))
	float GetPlayerNameTimeout = 30.f;
	
	UPROPERTY(EditAnywhere, Category="Overhead Widget Properties", meta=(AllowPrivateAccess=true, Units="Seconds"))
	float GetPlayerNameInterval = 0.1f;
	
	float TotalTime = -0.1f;
};
