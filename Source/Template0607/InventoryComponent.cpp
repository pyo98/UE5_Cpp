// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "InputCoreTypes.h"
#include "Weapon.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	APawn* Pawn = Cast<APawn>(GetOwner());
	if (Pawn)
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
		if (PC)
		{
			Pawn->EnableInput(PC);

			if (Pawn->InputComponent)
			{
				Pawn->InputComponent->BindKey(EKeys::Z, IE_Pressed, this, &UInventoryComponent::OnPressPickup);
				Pawn->InputComponent->BindKey(EKeys::X, IE_Pressed, this, &UInventoryComponent::OnPressDrop);
			}
		}
	}
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::OnPressPickup()
{
	if (GetOwner())
	{
		TArray<AActor*> ReturnOverlapActors;
		GetOwner()->GetOverlappingActors(ReturnOverlapActors, AWeapon::StaticClass());
		if (ReturnOverlapActors.IsValidIndex(0))
		{
			AddItem(ReturnOverlapActors[0]);
			GEngine->AddOnScreenDebugMessage(-1, 2.0F, FColor::Blue, TEXT("OnPressPickup"));
		}
	}
}

void UInventoryComponent::OnPressDrop()
{
	if (Weapons.IsValidIndex(0))
	{
		DropItem(Weapons[0]);
		GEngine->AddOnScreenDebugMessage(-1, 2.0F, FColor::Blue, TEXT("OnPressDrop"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0F, FColor::Red, TEXT("Failed"));
	}
}

void UInventoryComponent::AddItem(AActor* InActor)
{
	AWeapon* NewWeapon = Cast<AWeapon>(InActor);
	if (NewWeapon)
	{
		Weapons.Add(NewWeapon);
		NewWeapon->SetActorHiddenInGame(true);
		NewWeapon->SetActorEnableCollision(false);
	}
}

void UInventoryComponent::DropItem(AActor* InActor)
{
	FVector NewLocation = GetOwner()->GetActorLocation() + FVector(50, 0, 0);
	FVector2D NewLocation2D = FVector2D(NewLocation.X, NewLocation.Y);
	if (InActor)
	{
		AWeapon* Weapon = Cast<AWeapon>(InActor);
		FVector WeaponLocation = Weapon->GetActorLocation();
		FVector FinalLocation = FVector(NewLocation2D, WeaponLocation.Z);
		if (Weapon)
		{
			Weapons.Remove(Weapon);
			Weapon->SetActorHiddenInGame(false);
			Weapon->SetActorEnableCollision(true);
			Weapon->SetActorLocation(FinalLocation);
		}

		/*Weapons.Remove(Cast<AWeapon>(InActor));
		InActor->SetActorHiddenInGame(false);
		InActor->SetActorEnableCollision(true);
		InActor->SetActorLocation(GetOwner()->GetActorLocation() + FVector(50, 0, -50);*/

	}
}

