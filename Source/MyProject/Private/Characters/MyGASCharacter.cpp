// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/MyGASCharacter.h"
#include "Attributes/MyAttributeSet.h"
#include "Abilities/MyGameplayAbility.h"

AMyGASCharacter::AMyGASCharacter()
{
	// 创建 AbilitySystemComponent
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// 设置复制模式
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// 创建 AttributeSet
	AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));
}

void AMyGASCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		// 初始化能力信息
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		// 初始化属性
		InitializeAttributes();

		// 初始化能力
		InitializeAbilities();
	}
}

UAbilitySystemComponent* AMyGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMyGASCharacter::InitializeAbilities()
{
	if (AbilitySystemComponent)
	{
		for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
		{
			if (AbilityClass)
			{
				// 为每个能力创建一个能力规范
				FGameplayAbilitySpec AbilitySpec(AbilityClass, 1, 0, this);
				AbilitySystemComponent->GiveAbility(AbilitySpec);
			}
		}
	}
}

void AMyGASCharacter::InitializeAttributes()
{
	// 属性已在 AttributeSet 构造函数中初始化
	// 如果需要使用 GameplayEffect 初始化属性，可以在这里添加
}
