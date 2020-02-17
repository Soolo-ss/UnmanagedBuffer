#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectFloat.hpp"

namespace UnmanagedBuffer
{
	class FloatType : public UType
	{
	public:
		FloatType() : UType(UTypeType::UTYPE_FLOAT)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UFloatObject* uObj = new(buf) UFloatObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UFloatObject* uObj = new UFloatObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UFloatObject*)uObj)->~UFloatObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UFloatObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Float>{}(((UFloatObject*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UFloatObject* flhs = (UFloatObject*)lhs;
			UFloatObject* frhs = (UFloatObject*)rhs;

			flhs->SetVal(frhs->GetVal());

			return 0;
		}

	private:
		const static size_t m_ObjSize = sizeof(UFloatObject);
	};

}
