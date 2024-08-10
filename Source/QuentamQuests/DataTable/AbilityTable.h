// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "AbilityTable.generated.h"

class UQQGameplayAbility;
/**
 * 
 */
USTRUCT()
struct FAbilityData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// TODO : Need To Add Additional Property for Combine Ability
	FGameplayTag AbilityGroupTag;

	TSoftClassPtr<UQQGameplayAbility> Ability = nullptr;

	FGameplayTag InputTag;

	TSoftObjectPtr<UAnimMontage> Montage = nullptr;
};


UCLASS()
class QUENTAMQUESTS_API UAbilityTable : public UDataTable
{
	GENERATED_BODY()

public:
	static UDataTable* Get();

	FAbilityData AbilityData;
};
