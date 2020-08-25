// Fill out your copyright notice in the Description page of Project Settings.


#include "FireFightGameMode.h"


void AFireFightGameMode::PawnKilled(APawn* PawnKilled) 
{
    Super::PawnKilled(PawnKilled);
    
    // Check Lose condition (player is killed)
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    // Check if there are any remaining AI controllers left in world:
    for(AEnemyAIController* EnemyController : TActorRange<AEnemyAIController>(GetWorld()))
    {
        if(!EnemyController->IsDead())
        {
            return;
        }
    }

    EndGame(true);
}

void AFireFightGameMode::EndGame(bool bIsPlayerWinner) 
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
