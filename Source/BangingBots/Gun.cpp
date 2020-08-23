// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	
	// Adjust the PlayerViewPoint to be that of Player's Camera
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Pawn is Null!"));
		return;
	}
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Controller is Null!"));
		return;
	}
	FVector StartLocation;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(StartLocation, Rotation);

	// Calculate end point for line tracing and spawn particle if collision occurs
	FVector EndLocation = StartLocation + Rotation.Vector() * BulletRange;
	FHitResult Hit;

	// Ignoring AI Hitbox when attacking they attack
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	bool HitSuccess = GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_GameTraceChannel1, Params);
	if (HitSuccess) {
		// Get Direction of where bullet came from and spawn particle at end location
		FVector ShotDirection = -Rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		
		// Create DamageEvent and deal damage to any actor that was hit
		AActor* HitActor = Hit.GetActor();
		if (HitActor == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Actor is Null!"));
			return;
		}
		FPointDamageEvent DamageEvent(DamageAmount, Hit, ShotDirection, nullptr);
		HitActor->TakeDamage(DamageAmount, DamageEvent, OwnerController, this);
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

