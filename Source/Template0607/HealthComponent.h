// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HealthComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (FPS), meta = (BlueprintSpawnableComponent))
class TEMPLATE0607_API UHealthComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UHealthComponent();

public:
	UFUNCTION(BlueprintCallable)
	void SetDamaged(float InDamage);
	void OnDeath();
	void UpdateHealthWidget();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

};
