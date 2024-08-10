// Fill out your copyright notice in the Description page of Project Settings.


#include "QQAbilitySystemComponent.h"
#include "QQGameplayAbility.h"
#include "QuentamQuests/DataTable/AbilityTable.h"

void UQQAbilitySystemComponent::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UQQAbilitySystemComponent::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}

bool UQQAbilitySystemComponent::BuildAbilityFromAbilityData(const FAbilityData& InAbilityData)
{
	FGameplayAbilitySpec NewAbilitySpec = BuildAbilitySpecFromClass(InAbilityData.Ability.Get());
	
	FGameplayAbilitySpecHandle Handle = GiveAbility(NewAbilitySpec);

	if (!Handle.IsValid())
	{
		ensureAlwaysMsgf(false, TEXT("Ability Wasn't Given to GAS While Building"));
		return false;
	}
	
	if (NewAbilitySpec.GetAbilityInstances().IsEmpty())
	{
		ensure(false);
		return false;
	}
	
	UQQGameplayAbility* NewAbility = Cast<UQQGameplayAbility>(NewAbilitySpec.GetAbilityInstances()[0]);
	NewAbility->SetInputTag(InAbilityData.InputTag);
	UAnimMontage* AnimMontage = InAbilityData.Montage.Get();
	if (!AnimMontage)
	{
		ensure(false);
		return false;
	}
	NewAbility->SetAnimMontage(AnimMontage);
	return true;
}
