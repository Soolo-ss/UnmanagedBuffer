#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	UObject* UObject_GC_New(std::shared_ptr<UType> uType)
	{
		if (uType == nullptr)
			return nullptr;

		UObject* uObj = uType->New();
		UObject_Add_RefCount(uObj);

		if (uObj == nullptr)
			return nullptr;

		return uObj;
	}

	void UObject_GC_Delete(UObject* uObj)
	{
		if (uObj == nullptr)
			return;

		UInt32 refCount = uObj->GetRefCount();
		refCount--;
		uObj->SetRefCount(refCount);

		if (refCount > 0)
			return;

		UType* uType = uObj->GetType();

		if (uType == nullptr)
			return;

		uType->Delete(uObj);

		uObj = nullptr;

		return;
	}

	void UObject_Add_RefCount(UObject* uObj)
	{
		if (uObj == nullptr)
			return;

		UInt32 refCount = uObj->GetRefCount();
		refCount++;
		uObj->SetRefCount(refCount);
	}

	bool UObject_Check_Int8(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_INT8)
			return false;

		return true;
	}

	bool UObject_Check_UInt8(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_UINT8)
			return false;

		return true;
	}

	bool UObject_Check_Int16(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_INT16)
			return false;

		return true;
	}

	bool UObject_Check_UInt16(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_UINT16)
			return false;

		return true;
	}

	bool UObject_Check_Int32(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_INT32)
			return false;

		return true;
	}

	bool UObject_Check_UInt32(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_UINT32)
			return false;

		return true;
	}

	bool UObject_Check_Int64(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_INT64)
			return false;

		return true;
	}
	
	bool UObject_Check_UInt64(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_UINT64)
			return false;

		return true;
	}

	bool UObject_Check_Float(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_FLOAT)
			return false;

		return true;
	}

	bool UObject_Check_String(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_STRING)
			return false;

		return true;
	}

	bool UObject_Check_Unicode(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_WSTRING)
			return false;

		return true;
	}

	bool UObject_Check_List(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_LIST)
			return false;

		return true;
	}

	bool UObject_Check_Dict(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_DICT)
			return false;

		return true;
	}

	bool UObject_Check_Class(UObject* uObj)
	{
		if (uObj == nullptr)
			return false;

		if (uObj->GetType()->GetTypeType() != UTypeType::UTYPE_CLASS)
			return false;

		return true;
	}
}