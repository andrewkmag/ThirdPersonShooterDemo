// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Gun.h"
#include "Engine/World.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class BANGINGBOTS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called to calculate Damage taken
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Called to deal damage
	void Shoot();

	// Called to check if character is dead; health = 0
	UFUNCTION(BlueprintPure)
		bool IsDead() const;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	

	// Property to adjust the look sensitivity (pitch & yaw)
	UPROPERTY(EditAnywhere)
		float RotationRate = 75; // Seperate this into Y-axis and X-axis??

	// Configure class to be pointing to appropriate blueprint class
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGun> GunClass;

	// Stores Actual Gun
	UPROPERTY()
		AGun* Gun;

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health;
};
