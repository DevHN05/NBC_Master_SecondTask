#include "ItemManager.h"

UItemManager::UItemManager()
{
	InitializeItemDB();
}

void UItemManager::InitializeItemDB()
{
	ItemDatabase.Add(101, FItemData(TEXT("Basic Potion"), TEXT("")));
	ItemDatabase.Add(102, FItemData(TEXT("Master Sword"), TEXT("LINK")));

	UE_LOG(LogTemp, Log, TEXT("→ Item Database Initialized. %d items added."), ItemDatabase.Num());
}

void UItemManager::AddTitle(FString NewTitle)
{
	AcquiredTitles.Add(NewTitle);
	
	UE_LOG(LogTemp, Log, TEXT("→ You obtained '%s' title!"), *NewTitle);
}

void UItemManager::ObtainItem(int32 ItemID)
{
	if (ItemDatabase.Contains(ItemID))
	{
		Bag.Add(ItemID);
		
		UE_LOG(LogTemp, Log, TEXT("→ You put your item (ID: %d) to your bag."), ItemID);
	} else
	{
		UE_LOG(LogTemp, Warning, TEXT("→ You tried to put ID(%d) which is not existed."), ItemID);
	}
}

bool UItemManager::UseItem(int32 ItemID)
{
	if (!Bag.Contains(ItemID))
	{
		UE_LOG(LogTemp, Warning, TEXT("→ You don't have item (ID: %d)."), ItemID);
		return false;
	}
	
	FItemData* Info = ItemDatabase.Find(ItemID);
	
	if (Info)
	{
		if (Info->RequiredTitle.IsEmpty() || AcquiredTitles.Contains(Info->RequiredTitle))
		{
			Bag.RemoveSingle(ItemID);
			UE_LOG(LogTemp, Log, TEXT("→ You successfully used %s."), *Info->ItemName);
			return true;
		} else
		{
			UE_LOG(LogTemp, Log, TEXT("→ You need %s title to use %s."), *Info->RequiredTitle, *Info->ItemName);
			return false;
		}
	}
	return false;
}
