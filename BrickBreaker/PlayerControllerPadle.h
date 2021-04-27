

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPadle.generated.h"


/**
 * 
 */
UCLASS()
class BRICKBREAKER_API APlayerControllerPadle : public APlayerController
{
	GENERATED_BODY()
		APlayerControllerPadle();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);

	//ball references below



};
