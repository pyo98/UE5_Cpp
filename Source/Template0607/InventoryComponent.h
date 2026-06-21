// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEMPLATE0607_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION()
	void OnPressPickup();
	UFUNCTION()
	void OnPressDrop();
	UFUNCTION(BlueprintCallable)
	void AddItem(AActor* InActor);
	void DropItem(AActor* InActor);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AWeapon*> Weapons;
		
};
