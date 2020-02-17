#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectString.hpp"

namespace UnmanagedBuffer
{
	class StringType : public UType
	{
	public:
		StringType() : UType(UTypeType::UTYPE_STRING)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UStringObject* uObj = new(buf) UStringObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UStringObject* uObj = new UStringObject(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UStringObject*)uObj)->~UStringObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UStringObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<std::string>{}(((UStringObject*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UStringObject* lstr = (UStringObject*)lhs;
			UStringObject* rstr = (UStringObject*)rhs;

			lstr->SetVal(rstr->GetVal());

			return 0;
		}

	private:
		const static size_t m_ObjSize = sizeof(UStringObject);
	};
	
	class WStringType : public UType
	{
	public:
		WStringType() : UType(UTypeType::UTYPE_WSTRING)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UWStringObject* uObj = new(buf) UWStringObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else 
			UWStringObject* uObj = new UWStringObject(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UWStringObject*)uObj)->~UWStringObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UWStringObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<std::u16string>{}(((UWStringObject*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UWStringObject* lstr = (UWStringObject*)lhs;
			UWStringObject* rstr = (UWStringObject*)rhs;

			lstr->SetVal(rstr->GetVal());

			return 0;
		}

	private:
		const static size_t m_ObjSize = sizeof(UWStringObject);
	};


}
