// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BangingBotsGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "EnemyAIController.h"
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

private:
	void EndGame(bool bIsPlayerWinner);
};
