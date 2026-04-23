#pragma once

#include "CoreMinimal.h"
#include "ItemManager.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RequiredTitle;
	
	FItemData() : ItemName(TEXT("Unknown")), RequiredTitle(TEXT("")) {}
	FItemData(FString InName, FString InRequiredTitle) : ItemName(InName), RequiredTitle(InRequiredTitle) {}
};

UCLASS()
class TESTPROJECT_API UItemManager : public UObject
{
	GENERATED_BODY()
	
public:
	UItemManager();
	
	UPROPERTY()
	TArray<int32> Bag;
	
	UPROPERTY()
	TMap<int32, FItemData> ItemDatabase;
	
	UPROPERTY()
	TSet<FString> AcquiredTitles;
	
	void InitializeItemDB();
	void AddTitle(FString NewTitle);
	void ObtainItem(int32 ItemID);
	bool UseItem(int32 ItemID);
};
