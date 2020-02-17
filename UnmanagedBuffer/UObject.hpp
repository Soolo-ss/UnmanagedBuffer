#pragma once

#include "../Common/Common.hpp"
#include "../Common/MemoryPool.hpp"

#include "UType.hpp"

namespace UnmanagedBuffer
{
	class MemoryStream;

	using UObjectPtr = std::shared_ptr<UObject>;

	class UObject 
	{
	public:
		UObject(UType* utype)
			: m_Type(utype), m_RefCount(0)
		{
			
		}

		~UObject()
		{
			m_Type = nullptr;
		}

		UType* GetType() const
		{
			return m_Type;
		}

		void SetUType(UType* utype)
		{
			m_Type = utype;
		}

		void SetRefCount(UInt32 count)
		{
			m_RefCount = count;
		}

		UInt32 GetRefCount() const
		{
			return m_RefCount;
		}
		
		static UInt64 UObjectCount;
		static std::unordered_map<UInt64, UObject*> UObjects;
		static std::unordered_map<UObject*, UInt64> UObjectsMap;

		static void RegisterObject(UObject* uObj);
		static void UnRegisterObject(UObject* uObj);

		static char* Allocate(int bytes);
		static void Dellocate(char* ptr, int bytes);
		static int GetUsedSize();
	private:
		static BufferPool m_ObjectMemoryPool;

	private:
		UType* m_Type;
		UInt32 m_RefCount;
	};
}
