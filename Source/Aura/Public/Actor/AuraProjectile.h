// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Actor.h"
#include "AuraProjectile.generated.h"
class UProjectileMovementComponent;
class USphereComponent;
class UNiagaraSystem;

UCLASS()
class AURA_API AAuraProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraProjectile();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, meta=(ExposeOnSpawn = true))
	FGameplayEffectSpecHandle DamageEffectSpecHandle;
protected:
	virtual void BeginPlay() override;

	virtual void Destroyed() override;
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY()
	TObjectPtr<UAudioComponent> LoopingSoundComponent;
private:
	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 15.f;

	bool bHit = false;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> LoopingSound;
};
