#include "UObjectDict.hpp"

#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	UDictObject::UDictObject(UType* uType) 
		: UObject(uType)
	{
	}

	UDictObject::~UDictObject()
	{
		for (auto& ele : dict_)
		{
			UObject_GC_Delete(ele.first);
			UObject_GC_Delete(ele.second);
		}

		dict_.clear();
		
		for (auto& ele : iterator_)
		{
			UObject_GC_Delete(ele);
		}

		iterator_.clear();
		index_ = 0;
	}

	Int32 UDictObject::Size()
	{
		return (Int32)dict_.size();
	}

	Int32 UDictObject::SetItem(UObject* key, UObject* value)
	{
		auto old = dict_.find(key);

		if (old == dict_.end())
		{
			dict_[key] = value;
		}
		else
		{
			UObject* oldKey = old->first;
			UObject* oldValue = old->second;

			dict_.erase(old);
			UObject_GC_Delete(oldKey);
			UObject_GC_Delete(oldValue);

			dict_[key] = value;
		}

		UObject_Add_RefCount(key);
		UObject_Add_RefCount(value);

		return 0;
	}

	UObject* UDictObject::GetItem(UObject* key)
	{
		if (dict_.find(key) == dict_.end())
			return nullptr;

		auto valueObj = dict_[key];
		UObject_Add_RefCount(valueObj);

		return valueObj;
	}

	bool UDictObject::RemoveItem(UObject* key)
	{
		auto old = dict_.find(key);

		if (old == dict_.end())
			return false;

		UObject* oldKey = old->first;
		UObject* oldValue = old->second;

		dict_.erase(oldKey);

		UObject_GC_Delete(oldKey);
		UObject_GC_Delete(oldValue);

		return true;
	}

	bool UDictObject::Contains(UObject* key)
	{
		return dict_.find(key) != dict_.end();
	}

	void UDictObject::Clear()
	{
		for (auto& ele : dict_)
		{
			UObject_GC_Delete(ele.first);
			UObject_GC_Delete(ele.second);
		}

		dict_.clear();
	}

	void UDictObject::BeginLoop()
	{
		index_ = 0;

		for (auto& ele : dict_)
		{
			iterator_.push_back(ele.first);
			UObject_Add_RefCount(ele.first);
		}
	}

	UObject* UDictObject::Current()
	{
		UObject* key = iterator_[index_ - 1];
		UObject_Add_RefCount(key);

		return key;
	}

	bool UDictObject::MoveNext()
	{
		if (index_ < iterator_.size())
		{
			index_++;
			return true;
		}

		return false;
	}

	void UDictObject::EndLoop()
	{
		index_ = -1;

		for (auto& ele : iterator_)
		{
			UObject_GC_Delete(ele);
		}

		iterator_.clear();
	}

	UListObject* UDictObject::AllKeys()
	{
		UListObject* keys = (UListObject*)UObject_GC_New(UType::GetUTypeByName("List"));

		for (const auto& pair : dict_)
		{
			keys->Append(pair.first);
		}

		return keys;
	}
}
