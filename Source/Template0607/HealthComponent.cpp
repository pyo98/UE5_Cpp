// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "HealthWidget.h"

UHealthComponent::UHealthComponent()
{
	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;
}

void UHealthComponent::SetDamaged(float InDamage)
{
	// InDamage에 들어온 값을 CurrentHealth에 빼주고 다시
	// CurrentHealth를 업데이트
	CurrentHealth = CurrentHealth - InDamage;
	UpdateHealthWidget();

	if (CurrentHealth <= 0)
	{
		OnDeath();
	}
}

void UHealthComponent::OnDeath()
{
	if (GetOwner())
	{
		USkeletalMeshComponent* SkeletalMesh = GetOwner()->GetComponentByClass<USkeletalMeshComponent>();
		if (SkeletalMesh)
		{
			SkeletalMesh->SetSimulatePhysics(true);
			SkeletalMesh->SetPhysicsBlendWeight(1.0f);
			SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}
	}
}

void UHealthComponent::UpdateHealthWidget()
{
	if (GetWidget())
	{
		UHealthWidget* HealthWidget = Cast<UHealthWidget>(GetWidget());
		if (HealthWidget)
		{
			HealthWidget->UpdateHealthWidget(FMath::GetMappedRangeValueClamped(
			FVector2D(0.0f, MaxHealth), // 입력 범위
			FVector2D(0.0f, 1.0f), // 출력 범위
			CurrentHealth // 현재 값
			));
		}
	}
}
