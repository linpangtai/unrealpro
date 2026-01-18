// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameplayAbility.h"
#include "HealAbility.generated.h"

UCLASS()
class MYPROJECT_API UHealAbility : public UMyGameplayAbility
{
	GENERATED_BODY()

public:
	UHealAbility();

protected:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Heal")
	float HealAmount = 20.0f;
};
