#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectDict.hpp"

namespace UnmanagedBuffer
{
	class DictType : public UType
	{
	public:
		DictType()
			: UType(UTypeType::UTYPE_DICT), m_KeyType(nullptr), m_ValueType(nullptr)
		{

		}

		DictType(std::shared_ptr<UType> uKeyType, std::shared_ptr<UType> uValueType) : UType(UTypeType::UTYPE_DICT), m_KeyType(uKeyType), m_ValueType(uValueType)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UDictObject* uObj = new(buf) UDictObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UDictObject* uObj = new UDictObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj)override
		{
#if IS_USE_POOL == 1
			((UDictObject*)uObj)->~UDictObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UDictObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return 0;
		}

		std::shared_ptr<UType> GetKeyType()
		{
			return m_KeyType;
		}

		std::shared_ptr<UType> GetValueType()
		{
			return m_ValueType;
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			return -1;
		}

	private:
		const static size_t m_ObjSize = sizeof(UDictObject);

	private:
		std::shared_ptr<UType> m_KeyType;
		std::shared_ptr<UType> m_ValueType;
	};


}
