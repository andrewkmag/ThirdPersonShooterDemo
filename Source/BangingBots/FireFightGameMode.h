// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BangingBotsGameModeBase.h"
#include "EngineUtils.h"
#include "FireFightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BANGINGBOTS_API AFireFightGameMode : public ABangingBotsGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

	// Returns the number of remaining enemies in world
	int getRemainingEnemies() const;
private:
	void EndGame(bool bIsPlayerWinner);
};
