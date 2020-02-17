#pragma once

#include "../Common/Common.hpp"
#include "UObjectInt.hpp"
#include "UObjectFloat.hpp"
#include "UObjectString.hpp"
#include "UObjectList.hpp"
#include "UObjectDict.hpp"
#include "UObjectClass.hpp"

namespace UnmanagedBuffer
{
	class IntType : public UType
	{
	public:
		IntType() : UType(UTypeType::UTYPE_INT)
		{

		}

		virtual UObject* New() override
		{
#if IS_USE_POOL == 1
			char* buf = UObject::Allocate(m_ObjSize);
			UIntObject* uObj = new(buf) UIntObject(this);
			UObject::RegisterObject(uObj);
			return uObj;
#else
			UIntObject* uObj = new UIntObject(this);
			UObject::RegisterObject(uObj);

			return uObj;
#endif
		}

		virtual void Delete(UObject* uObj) override
		{
#if IS_USE_POOL == 1
			((UIntObject*)uObj)->~UIntObject();
			UObject::Dellocate((char*)uObj, m_ObjSize);
			UObject::UnRegisterObject(uObj);
#else
			UObject::UnRegisterObject(uObj);
			delete (UIntObject*)uObj;
#endif
		}

		virtual size_t Hash(const UObject* uObj) override
		{
			return std::hash<Int64>{}(((UIntObject*)uObj)->GetVal());
		}

		int Copy(UObject* lhs, UObject* rhs) override
		{
			if (lhs->GetType() != rhs->GetType())
				return -1;

			UIntObject* ilhs = (UIntObject*)lhs;
			UIntObject* irhs = (UIntObject*)rhs;

			ilhs->SetVal(irhs->GetVal());

			return 0;
		}

	private:
		const static size_t m_ObjSize = sizeof(UIntObject);
	};

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
			m_FieldName2Index[name] = m_FieldName2Index.size();
			m_FieldIndex2Type[m_FieldName2Index.size() - 1] = type;
			m_FieldIndex2Name[m_FieldName2Index.size() - 1] = name;
		}

		Int32 GetFieldSize()
		{
			return m_FieldTypes.size();
		}

		std::shared_ptr<UType> LookupFieldTypeByIndex(Int32 index)
		{
			if (m_FieldIndex2Type.find(index) == m_FieldIndex2Type.end())
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
			if (m_FieldIndex2Name.find(index) == m_FieldIndex2Name.end())
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
		std::map<Int32, std::string> m_FieldIndex2Name;
		std::map<Int32, std::shared_ptr<UType>> m_FieldIndex2Type;
		std::string m_Name;
	};
}
