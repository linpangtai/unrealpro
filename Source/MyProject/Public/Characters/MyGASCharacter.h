// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "MyGASCharacter.generated.h"

class UMyAttributeSet;
class UMyGameplayAbility;

UCLASS()
class MYPROJECT_API AMyGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMyGASCharacter();

	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* IAbilitySystemInterface::GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UMyAttributeSet* AttributeSet;

	// 默认能力
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	// 初始化能力
	virtual void InitializeAbilities();

	// 初始化属性
	virtual void InitializeAttributes();
};
