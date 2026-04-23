#include "TaskGameMode.h"
#include "ItemManager.h"

void ATaskGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("-- Item Manager System Test --"));
	
	ItemManager = NewObject<UItemManager>(this);
	
	if (ItemManager)
	{
		ItemManager->ObtainItem(101);
		ItemManager->ObtainItem(102);
		
		UE_LOG(LogTemp, Log, TEXT("-- First attempt to use --"));
		
		ItemManager->UseItem(101);
		ItemManager->UseItem(102);
		
		UE_LOG(LogTemp, Log, TEXT("-- Event of obtaining title --"));
		
		ItemManager->AddTitle(TEXT("LINK"));
		
		UE_LOG(LogTemp, Log, TEXT("-- Second attempt to use --"));
		
		ItemManager->UseItem(102);
	}
}