// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BlasterHUD.generated.h"

USTRUCT(BlueprintType)
struct FHUDPackage
{
	GENERATED_BODY()

public:
	UTexture2D* CrosshairsCenter;
	UTexture2D* CrosshairsLeft;
	UTexture2D* CrosshairsRight;
	UTexture2D* CrosshairsTop;
	UTexture2D* CrosshairsBottom;
	float CrosshairSpread;
};

/**
 * 
 */
UCLASS()
class BLASTER_API ABlasterHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	FHUDPackage HUDPackage;

	void DrawCrosshair(UTexture2D* Texture, FVector2d ViewportCenter, FVector2d Spread);

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadMax = 16.f;

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadFalling = 2.25f;

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadFallingInterpSpeed = 2.25f;

	UPROPERTY(EditAnywhere)
	float CrosshairSpreadLandingInterpSpeed = 30.f;
	
public:
	FORCEINLINE void SetHUDPackage(const FHUDPackage& Package) { HUDPackage = Package; }
	
	FORCEINLINE float GetCrosshairSpreadFalling() const { return CrosshairSpreadFalling; }
	FORCEINLINE float GetCrosshairSpreadFallingInterpSpeed() const { return CrosshairSpreadFallingInterpSpeed; }
	FORCEINLINE float GetCrosshairSpreadLandingInterpSpeed() const { return CrosshairSpreadLandingInterpSpeed; }
};
