#pragma once

#include "UObjectClass.hpp"

#include "UClassType.hpp"
#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	UClassObject::UClassObject(UType* uType)
		: UObject(uType)
	{

	}

	UClassObject::~UClassObject()
	{
		ClassType* uType = (ClassType*)GetType();
		if (uType == nullptr)
			return;

		Int32 uFieldIndex = uType->GetFieldSize();

		for (int i = 0; i != uFieldIndex; ++i)
		{
			UObject_GC_Delete(m_Fields[i]);
		}

		delete[] m_Fields;
	}

	void UClassObject::InitFields()
	{
		ClassType* uType = (ClassType*)GetType();

		if (uType == nullptr)
			return;

		Int32 fieldSize = uType->GetFieldSize();

		m_Fields = new UObject*[fieldSize];

		for (int i = 0; i != fieldSize; ++i)
		{
			auto fieldType = uType->LookupFieldTypeByIndex(i);
			if (fieldType)
			{
				UObject* uFieldObj = UObject_GC_New(fieldType);
				AddField(i, uFieldObj);
			}
		}
	}

	void UClassObject::AddField(Int32 index, UObject* uFieldObj)
	{
		m_Fields[index] = uFieldObj;
	}

	UObject* UClassObject::GetField(std::string name)
	{
		ClassType* uType = (ClassType*)GetType();

		Int32 uFieldIndex = uType->LookupFieldIndexByName(name);

		if (uFieldIndex == -1)
			return nullptr;

		auto field = m_Fields[uFieldIndex];
		UObject_Add_RefCount(field);

		return field;
	}

	UObject* UClassObject::GetFieldByIndex(Int32 index)
	{
		ClassType* uType = (ClassType*)GetType();

		if (index >= (uType->GetFieldSize()))
			return nullptr;

		auto field = m_Fields[index];

		UObject_Add_RefCount(field);

		return field;
	}

	bool UClassObject::SetField(std::string name, UObject* field)
	{
		ClassType* uType = (ClassType*)GetType();

		Int32 uFieldIndex = uType->LookupFieldIndexByName(name);
		if (uFieldIndex == -1)
			return false;

		auto uold = m_Fields[uFieldIndex];
		if (uold == nullptr || field == nullptr)
			return false;

		//释放掉老的对象
		UObject_GC_Delete(uold);
		UObject_Add_RefCount(field);

		m_Fields[uFieldIndex] = field;

		return true;
	}

	bool UClassObject::IsFieldExits(std::string name)
	{
		ClassType* uType = (ClassType*)GetType();

		Int32 uFieldIndex = uType->LookupFieldIndexByName(name);
		if (uFieldIndex == -1)
			return false;

		auto uField = m_Fields[uFieldIndex];
		if (!uField)
			return false;

		return true;
	}

}
