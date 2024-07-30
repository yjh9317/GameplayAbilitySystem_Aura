// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraAbilityTypes.h"
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

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	FDamageEffectParams DamageEffectParams;

	UPROPERTY()
	TObjectPtr<USceneComponent> HomingTargetSceneComponent;
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void OnHit();
	virtual void Destroyed() override;
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> Sphere;
	
	bool IsValidOverlap(AActor* OtherActor);
	bool bHit = false;
	
	UPROPERTY()
	TObjectPtr<UAudioComponent> LoopingSoundComponent;
private:
	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 15.f;

	
	UPROPERTY(EditAnywhere, meta= (AllowPrivateAccess="true"))
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere, meta= (AllowPrivateAccess="true"))
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere, meta= (AllowPrivateAccess="true"))
	TObjectPtr<USoundBase> LoopingSound;
};

