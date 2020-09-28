// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickupActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAmmoPickupActor::AAmmoPickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(Root);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AAmmoPickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoPickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoPickupActor::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}

