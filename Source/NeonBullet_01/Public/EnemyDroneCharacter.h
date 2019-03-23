// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeonBullet_01.h"
#include "NeonBullet_01GameModeBase.h"
#include "GameFramework/Character.h"
#include "EnemyDroneCharacter.generated.h"

UCLASS()
class NEONBULLET_01_API AEnemyDroneCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float Speed = 20.f;

	UPROPERTY(EditAnywhere)
		float TurnDelayMax = 3.f;

	/*How long min till turn towards player*/
	UPROPERTY(EditAnywhere)
		float TurnDelayMin = 1.f;

	float CurrentTurnDelay = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AEnemyDroneCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector MoveDirection = FVector(1.f, 0.f, 0.f);

	void isHit();

	int enemyHealth{ 3 };

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "DroneChar", meta = (AllowPrivateAccess = "true"))
		AActor *character_01;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		Category = "DroneChar", meta = (AllowPrivateAccess = "true"))
		FVector character_01_location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "DroneChar", meta = (AllowPrivateAccess = "true"))
		FVector start_location_01 = FVector(0, 0, 20);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "DroneChar", meta = (AllowPrivateAccess = "true"))
		FVector goal_location_01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "DroneChar", meta = (AllowPrivateAccess = "true"))
		AActor *goal_actor_location_01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "General", meta = (AllowPrivateAccess = "true"))
		float speed1 = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,
		Category = "General", meta = (AllowPrivateAccess = "true"))
		float accuracy;
};
