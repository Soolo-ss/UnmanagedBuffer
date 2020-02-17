#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectInt.hpp"

namespace UnmanagedBuffer
{
	class Int8Type : public UType
	{
	public :
		Int8Type() : UType(UTypeType::UTYPE_INT8)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UInt8Object* uObj = new(buf) UInt8Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UInt8Object* uObj = new UInt8Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UInt8Object*)uObj)->~UInt8Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UInt8Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Int8>{}(((UInt8Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UInt8Object* ilhs = (UInt8Object*)lhs;
			UInt8Object* irhs = (UInt8Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UInt8Object);
	};

	class UInt8Type : public UType
	{
	public :
		UInt8Type() : UType(UTypeType::UTYPE_UINT8)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UUInt8Object* uObj = new(buf) UUInt8Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UUInt8Object* uObj = new UUInt8Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UUInt8Object*)uObj)->~UUInt8Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UUInt8Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<UInt8>{}(((UUInt8Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UUInt8Object* ilhs = (UUInt8Object*)lhs;
			UUInt8Object* irhs = (UUInt8Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UUInt8Object);
	};

	class Int16Type : public UType
	{
	public :
		Int16Type() : UType(UTypeType::UTYPE_INT16)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UInt16Object* uObj = new(buf) UInt16Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UInt16Object* uObj = new UInt16Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UInt16Object*)uObj)->~UInt16Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UInt16Object*)uObj;
#endif
		}


		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Int16>{}(((UInt16Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UInt16Object* ilhs = (UInt16Object*)lhs;
			UInt16Object* irhs = (UInt16Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UInt16Object);
	};

	class UInt16Type : public UType
	{
	public :
		UInt16Type() : UType(UTypeType::UTYPE_UINT16)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UUInt16Object* uObj = new(buf) UUInt16Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UUInt16Object* uObj = new UUInt16Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UUInt16Object*)uObj)->~UUInt16Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UUInt16Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<UInt16>{}(((UUInt16Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UUInt16Object* ilhs = (UUInt16Object*)lhs;
			UUInt16Object* irhs = (UUInt16Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UUInt16Object);
	};

	class Int32Type : public UType
	{
	public :
		Int32Type() : UType(UTypeType::UTYPE_INT32)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UInt32Object* uObj = new(buf) UInt32Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UInt32Object* uObj = new UInt32Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UInt32Object*)uObj)->~UInt32Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UInt32Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Int32>{}(((UInt32Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UInt32Object* ilhs = (UInt32Object*)lhs;
			UInt32Object* irhs = (UInt32Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UInt32Object);
	};

	class UInt32Type : public UType
	{
	public :
		UInt32Type() : UType(UTypeType::UTYPE_UINT32)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UUInt32Object* uObj = new(buf) UUInt32Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UUInt32Object* uObj = new UUInt32Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UUInt32Object*)uObj)->~UUInt32Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UUInt32Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<UInt32>{}(((UUInt32Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UUInt32Object* ilhs = (UUInt32Object*)lhs;
			UUInt32Object* irhs = (UUInt32Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UUInt32Object);
	};

	class Int64Type : public UType
	{
	public :
		Int64Type() : UType(UTypeType::UTYPE_INT64)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UInt64Object* uObj = new(buf) UInt64Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UInt64Object* uObj = new UInt64Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UInt64Object*)uObj)->~UInt64Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UInt64Object*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Int64>{}(((UInt64Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UInt64Object* ilhs = (UInt64Object*)lhs;
			UInt64Object* irhs = (UInt64Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UInt64Object);
	};

	class UInt64Type : public UType
	{
	public :
		UInt64Type() : UType(UTypeType::UTYPE_UINT64)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UUInt64Object* uObj = new(buf) UUInt64Object(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UInt64Object* uObj = new UInt64Object(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UUInt64Object*)uObj)->~UUInt64Object();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UUInt64Object*)uObj;
#endif
		}


		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<UInt64>{}(((UUInt64Object*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UUInt64Object* ilhs = (UUInt64Object*)lhs;
			UUInt64Object* irhs = (UUInt64Object*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}
	private:
		const static size_t m_ObjSize = sizeof(UUInt64Object);
	};
}
