// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class USkeletalMeshComponent;

UCLASS()
class BANGINGBOTS_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// VisibleAnywhere = Dont want to edit the pointer, allows viewing of properties
	// of the pointer
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffect;
	
	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
		float BulletRange = 1000;

	UPROPERTY(EditAnywhere)
		float DamageAmount = 10;

	bool GunLineTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
