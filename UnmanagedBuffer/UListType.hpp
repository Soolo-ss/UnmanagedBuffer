#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectList.hpp"

namespace UnmanagedBuffer
{
	class ListType : public UType
	{
	public:
		ListType() : UType(UTypeType::UTYPE_LIST), m_ChildType(nullptr)
		{

		}

		ListType(std::shared_ptr<UType> childType) : UType(UTypeType::UTYPE_LIST), m_ChildType(childType)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UListObject* uObj = new(buf) UListObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UListObject* uObj = new UListObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UListObject*)uObj)->~UListObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UListObject*)uObj;
#endif
		}

		std::shared_ptr<UType> GetChildType()
		{
			return m_ChildType;
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return 0;
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			return -1;
		}
	
	private:
		const static size_t m_ObjSize = sizeof(UListObject);

	private:
		std::shared_ptr<UType> m_ChildType;
	};
}
