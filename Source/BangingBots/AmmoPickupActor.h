// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoPickupActor.generated.h"

class USphereComponent;
class USkeletalMeshComponent;

UCLASS()
class BANGINGBOTS_API AAmmoPickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoPickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* PickupFX;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
