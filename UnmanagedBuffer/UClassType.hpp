#pragma once

#include "UType.hpp"
#include "UObject.hpp"
#include "UObjectClass.hpp"

namespace UnmanagedBuffer
{
	class ClassType : public UType
	{
	public:
		ClassType() : UType(UTypeType::UTYPE_CLASS)
		{
		
		}

		ClassType(std::string name) : UType(UTypeType::UTYPE_CLASS), m_Name(name)
		{

		}

		~ClassType()
		{
			m_FieldTypes.clear();
			m_FieldName2Index.clear();
			m_FieldIndex2Type.clear();
			m_FieldIndex2Name.clear();
		}

		void AddField(std::string name, std::shared_ptr<UType> type)
		{
			if (type == nullptr)
				return;

			if (m_FieldTypes.find(name) != m_FieldTypes.end())
				return;

			m_FieldTypes[name] = type;
			m_FieldName2Index[name] = (Int32)m_FieldName2Index.size();
			m_FieldIndex2Type.push_back(type);
			m_FieldIndex2Name.push_back(name);
		}

		Int32 GetFieldSize()
		{
			return (Int32)m_FieldTypes.size();
		}

		std::shared_ptr<UType> LookupFieldTypeByIndex(Int32 index)
		{
			if (m_FieldIndex2Type.size() <= (size_t)index)
				return nullptr;

			return m_FieldIndex2Type[index];
		}

		std::shared_ptr<UType> LookupFieldTypeByName(std::string name)
		{
			if (m_FieldTypes.find(name) == m_FieldTypes.end())
				return nullptr;

			return m_FieldTypes[name];
		}

		Int32 LookupFieldIndexByName(std::string name)
		{
			if (m_FieldName2Index.find(name) == m_FieldName2Index.end())
				return -1;

			return m_FieldName2Index.at(name);
		}

		std::string LookupFieldNameByIndex(Int32 index)
		{
			if (m_FieldIndex2Name.size() <= index)
				return std::string();

			return m_FieldIndex2Name[index];
		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UClassObject* uObj = new(buf) UClassObject(this);
			UObject::RegisterObject(uObj);
			uObj->InitFields();
			return uObj;
#else
			UClassObject* uObj = new UClassObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UClassObject*)uObj)->~UClassObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UClassObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			std::hash<const UObject*> hash_t;
			return hash_t(uObj);
		}

		const std::map <std::string, std::shared_ptr<UType>> & GetFieldTypes()
		{
			return m_FieldTypes;
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			return -1;
		}
	private:
		const static size_t m_ObjSize = sizeof(UClassObject);

	private:
		std::map<std::string, std::shared_ptr<UType> > m_FieldTypes;
		std::map<std::string, Int32> m_FieldName2Index;
		std::vector<std::string> m_FieldIndex2Name;
		std::vector<std::shared_ptr<UType>> m_FieldIndex2Type;
		std::string m_Name;
	};
}
