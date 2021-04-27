


#include "PlayerControllerPadle.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddles.h"

// #include "Ball.h"

APlayerControllerPadle::APlayerControllerPadle()
{

}


void APlayerControllerPadle::BeginPlay()
{

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;

	//shows camera for the player at the zero index
	SetViewTarget(CameraActors[0], Params);
}

void APlayerControllerPadle::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Enables this movement on player controller I created
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APlayerControllerPadle::MoveHorizontal);

}
//AxisValue is for scale parameter in movement
void APlayerControllerPadle::MoveHorizontal(float AxisValue)
{
	//auto will detect value on the right side as the same type
	//auto MyPawn = Cast<APlayerControllerPadle>(GetPawn());
	auto MyPawn = Cast<APaddles>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(AxisValue);
	}
	}