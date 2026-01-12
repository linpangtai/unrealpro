// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject/Public/Interact/InteractableActor.h"


// Sets default values
AInteractableActor::AInteractableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AInteractableActor::OnInteracted_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("C++ 基础互动逻辑被触发"));
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	OnInteracted();
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

