// Copyright Stefan Oancea 2017

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "OpenDoor.generated.h"
#include "GameFramework/Actor.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPEPR_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	AActor* Owner;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	
	float DoorCloseDelay = 1.f;

	
	float doorLastOpenTime;

	AActor* ActorThatOpens; // Remember pawn inherits from Actor

	//

};
