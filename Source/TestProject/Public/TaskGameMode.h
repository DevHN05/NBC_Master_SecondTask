#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TaskGameMode.generated.h"

class UItemManager;

UCLASS()
class TESTPROJECT_API ATaskGameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY()
	UItemManager* ItemManager;
};
