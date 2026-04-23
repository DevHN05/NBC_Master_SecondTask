#include "ItemManager.h"

UItemManager::UItemManager()
{
	InitializeItemDB();
}

void UItemManager::InitializeItemDB()
{
	ItemDatabase.Add(101, FItemData(TEXT("Basic Potion"), TEXT("")));
	ItemDatabase.Add(102, FItemData(TEXT("Master Sword"), TEXT("LINK")));
}

void UItemManager::AddTitle(FString NewTitle)
{
	AcquiredTitles.Add(NewTitle);
}

void UItemManager::ObtainItem(int32 ItemID)
{
	if (ItemDatabase.Contains(ItemID))
	{
		Bag.Add(ItemID);
	}
}

bool UItemManager::UseItem(int32 ItemID)
{
	if (!Bag.Contains(ItemID)) return false;
	
	FItemData* Info = ItemDatabase.Find(ItemID);
	
	if (Info)
	{
		if (Info->RequiredTitle.IsEmpty() || AcquiredTitles.Contains(Info->RequiredTitle))
		{
			Bag.RemoveSingle(ItemID);
			return true;
		}
	}
	return false;
}
