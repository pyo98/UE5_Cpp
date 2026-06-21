// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "InventoryComponent.h"
#include "InputCoreTypes.h"


// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	APawn* Pawn = Cast<APawn>(GetOwner());
	if (Pawn)
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
		if (PC)
		{
			Pawn->EnableInput(PC);

			if (Pawn->InputComponent)
			{
				Pawn->InputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &UWeaponComponent::RequestFire);
				Pawn->InputComponent->BindKey(EKeys::P, IE_Pressed, this, &UWeaponComponent::RequestUnEquipWeapon);
				Pawn->InputComponent->BindKey(EKeys::O, IE_Pressed, this, &UWeaponComponent::RequestEquipWeapon);

			}
		}
	}
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::RequestFire()
{
	if (WeaponRef)
	{
		WeaponRef->Fire();
	}
}

void UWeaponComponent::RequestUnEquipWeapon()
{
	if (WeaponRef)
	{
		UnEquipWeapon(WeaponRef);
	}
}

void UWeaponComponent::RequestEquipWeapon()
{
	UInventoryComponent* Inventory = GetOwner()->GetComponentByClass<UInventoryComponent>();
	AWeapon* Weapon = Inventory->Weapons[0];
	if (Weapon)
	{
		EquipWeapon(Weapon);
	}
}

void UWeaponComponent::EquipWeapon(AWeapon* InWeapon)
{
	if (InWeapon)
	{
		WeaponRef = InWeapon;
		USkeletalMeshComponent* SkeletalMesh = GetOwner()->GetComponentByClass<USkeletalMeshComponent>();
		if (SkeletalMesh)
		{
			WeaponRef->SetActorHiddenInGame(false);
			WeaponRef->AttachToComponent(SkeletalMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Socket_Weapon"));
			WeaponRef->SetActorEnableCollision(false);
			WeaponRef->SetActorScale3D(FVector(0.1f));
		}
	}


}

void UWeaponComponent::UnEquipWeapon(AWeapon* InWeapon)
{
	if (InWeapon)
	{
		InWeapon->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		InWeapon->SetActorHiddenInGame(true);
		WeaponRef = nullptr;
	}
}

