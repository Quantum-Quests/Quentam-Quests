// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "QQGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class QUENTAMQUESTS_API UQQGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

private:
	// TODO : Need To Add Additional Property for Combine Ability
	UPROPERTY()
	FGameplayTag InputTag = FGameplayTag();

	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage;

public:
	void SetInputTag(const FGameplayTag& NewInputTag) { InputTag = NewInputTag; }
	void SetAnimMontage(const TObjectPtr<UAnimMontage>& NewAnimMontage) { Montage = NewAnimMontage; }
	
};
