// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/HealAbility.h"
#include "Attributes/MyAttributeSet.h"
#include "AbilitySystemComponent.h"

UHealAbility::UHealAbility()
{
	// 能力标签
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Heal")));

	// 输入类型 - 可以通过按键激活
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UHealAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
	if (ASC)
	{
		// 获取当前生命值
		float CurrentHealth = ASC->GetNumericAttribute(UMyAttributeSet::GetHealthAttribute());
		float MaxHealth = ASC->GetNumericAttribute(UMyAttributeSet::GetMaxHealthAttribute());

		// 计算新生命值
		float NewHealth = FMath::Min(CurrentHealth + HealAmount, MaxHealth);

		// 应用治疗
		ASC->SetNumericAttributeBase(UMyAttributeSet::GetHealthAttribute(), NewHealth);

		UE_LOG(LogTemp, Log, TEXT("Healed: %.1f HP (%.1f -> %.1f)"), HealAmount, CurrentHealth, NewHealth);
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
