#include "UObjectList.hpp"

#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	UListObject::UListObject(UType* uType)
		: UObject(uType)
	{

	}

	UListObject::~UListObject()
	{
		for (auto& ele : list_)
		{
			UObject_GC_Delete(ele);
		}

		list_.clear();
	}

	void UListObject::Clear()
	{
		for (auto& ele : list_)
		{
			UObject_GC_Delete(ele);
		}

		list_.clear();
	}

	Int32 UListObject::Size()
	{
		return (Int32)list_.size();
	}

	UObject* UListObject::GetItem(Int32 index)
	{
		if (list_.size() <= index || index < 0)
			return nullptr;

		auto item = list_[index];
		UObject_Add_RefCount(item);

		return item;
	}

	Int32 UListObject::SetItem(UObject* newItem, Int32 index)
	{
		if (newItem == nullptr)
			return -1;

		if (list_.size() <= index || index < 0)
			return -1;

		auto oldItem = list_[index];
		UObject_GC_Delete(oldItem);
		UObject_Add_RefCount(newItem);

		list_[index] = newItem;

		return 0;
	}

	Int32 UListObject::Insert(UObject* newItem, Int32 index)
	{
		if (newItem == nullptr)
			return -1;

		UObject_Add_RefCount(newItem);
		list_.insert(list_.begin() + index, newItem);

		return 0;
	}

	Int32 UListObject::Append(UObject* newItem)
	{
		if (newItem == nullptr)
			return -1;

		UObject_Add_RefCount(newItem);
		list_.push_back(newItem);

		return 0;
	}
}
