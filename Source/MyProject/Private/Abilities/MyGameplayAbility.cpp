// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/MyGameplayAbility.h"
#include "AbilitySystemComponent.h"

UMyGameplayAbility::UMyGameplayAbility()
{
	// 默认能力设置
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;

	// 能力标签
	AbilityTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability")));

	// 阻止标签（当此能力激活时，阻止其他能力）
	BlockAbilitiesWithTag.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability")));
}

void UMyGameplayAbility::ActivateAbility(
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

	// 在这里编写你的能力逻辑
	UE_LOG(LogTemp, Log, TEXT("Ability Activated: %s"), *GetName());

	// 模拟能力执行
	// 你可以在这里播放动画、应用GameplayEffect、生成物体等

	// 完成能力
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
