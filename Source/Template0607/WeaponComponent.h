// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEMPLATE0607_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION()
	void RequestFire();
	UFUNCTION()
	void RequestUnEquipWeapon();
	UFUNCTION()
	void RequestEquipWeapon();

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(AWeapon* InWeapon);

	void UnEquipWeapon(AWeapon* InWeapon);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AWeapon* WeaponRef;
};
