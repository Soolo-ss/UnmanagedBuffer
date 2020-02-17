#pragma once

#include "../Common/Common.hpp"

#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_utils.hpp"
#include "../rapidxml/rapidxml_print.hpp"

#include <functional>

namespace UnmanagedBuffer
{
	class UObject;
	using UObjectPtr = std::shared_ptr<UObject>;

	enum UTypeType
	{
		UTYPE_INT8,
		UTYPE_UINT8,
		UTYPE_INT16,
		UTYPE_UINT16,
		UTYPE_INT32,
		UTYPE_UINT32,
		UTYPE_INT64,
		UTYPE_UINT64,
		UTYPE_FLOAT,
		UTYPE_STRING,
		UTYPE_WSTRING,
		UTYPE_LIST,
		UTYPE_DICT,
		UTYPE_CLASS
	};

	class UType
	{
	public:
		UType(UTypeType type);

		inline UTypeType GetTypeType() const 
		{
			return m_Type;
		}

		std::string Name() const
		{
			return m_Name;
		}

		void SetName(std::string name)
		{
			m_Name = name;
		}

		virtual UObject* New() = 0;
		virtual void Delete(UObject* uObj) = 0;
		virtual size_t Hash(const UObject* uObj) = 0;
		virtual int Copy(UObject* lhs, UObject* rhs) = 0;
	public:
		static std::unordered_map<std::string, std::shared_ptr<UType>> GlobalTypes;

		static void CreateNewType(std::string name, std::shared_ptr<UType> type);

		static void CreateNewListType(std::string typeName);
		
		static void CreateNewDictType(std::string typeName);

		static void ClearAllTypes();
		
		static std::shared_ptr<UType> GetUTypeByName(std::string name);
		
	private:
		UTypeType m_Type;
		std::string m_Name;
	};
}
