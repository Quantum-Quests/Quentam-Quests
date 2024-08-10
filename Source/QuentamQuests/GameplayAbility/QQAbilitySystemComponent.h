// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "QQAbilitySystemComponent.generated.h"

struct FAbilityData;
/**
 * 
 */
UCLASS()
class QUENTAMQUESTS_API UQQAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
protected:
	// GameplayTasksComponent Interface
	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	// ~GameplayTasksComponent Interface
public:
	bool BuildAbilityFromAbilityData(const FAbilityData& InAbilityData);
};
