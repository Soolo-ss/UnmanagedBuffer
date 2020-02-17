#include "UObject.hpp"

namespace UnmanagedBuffer
{
	UInt64 UObject::UObjectCount = 0;
	std::unordered_map<UInt64, UObject*> UObject::UObjects;
	std::unordered_map<UObject*, UInt64> UObject::UObjectsMap;
	BufferPool UObject::m_ObjectMemoryPool = BufferPool(2, 64 * 1024 * 1024);

	char* UObject::Allocate(int bytes)
	{
		return m_ObjectMemoryPool.Allocate(bytes);
	}

	void UObject::Dellocate(char* ptr, int btyes)
	{
		m_ObjectMemoryPool.Deallocate(ptr, btyes);
	}

	int UObject::GetUsedSize()
	{
		return m_ObjectMemoryPool.GetUsedSize();
	}

	void UObject::RegisterObject(UObject* uObj)
	{
		UObjectCount++;
		/*
		UObjects[UObjects.size()] = uObj;
		UObjectsMap[uObj] = UObjects.size() - 1;
		UObjectCount++;
		*/
	}
	
	void UObject::UnRegisterObject(UObject* uObj)
	{
		/*
		auto index = UObjectsMap.find(uObj);
		UObjects.erase(index->second);
		UObjectsMap.erase(index);
		UObjectCount--;
		*/
		UObjectCount--;
	}
}