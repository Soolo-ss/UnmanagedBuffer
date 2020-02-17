#include "UType.hpp"

#include "UListType.hpp"
#include "UDictType.hpp"

namespace UnmanagedBuffer
{
	UType::UType(UTypeType type)
		: m_Type(type)
	{
	}

	std::unordered_map<std::string, std::shared_ptr<UType>> UType::GlobalTypes;

	void UType::CreateNewType(std::string name, std::shared_ptr<UType> type)
	{
		if (GlobalTypes.find(name) != GlobalTypes.end())
			return;

		type->SetName(name);

		GlobalTypes[name] = type;
	}

	void UType::CreateNewListType(std::string typeName)
	{
		size_t bpos = typeName.find("List<");
		if (bpos == typeName.npos)
			return;

		std::string valuename;
		size_t epos = typeName.find_last_of(">");
		valuename = typeName.substr(bpos + 1, epos - bpos - 1);

		if (valuename.empty())
			return;

		std::shared_ptr<UType> valueType = GetUTypeByName(valuename);
		if (valueType)
		{
			std::shared_ptr<ListType> listType = std::make_shared<ListType>(valueType);
			CreateNewType(typeName, listType);
		}
	}

	void UType::CreateNewDictType(std::string typeName)
	{
		size_t bpos = typeName.find("Dict<");
		if (bpos == typeName.npos)
			return;

		std::string keyname;

		size_t epos = typeName.find(",");
		keyname = typeName.substr(bpos + 5, epos - bpos - 5);
		if (keyname.empty())
			return;

		std::string valuename;
		bpos = epos;
		epos = typeName.find_last_of(">");
		valuename = typeName.substr(bpos + 1, epos - bpos - 1);
		if (valuename.empty())
			return;

		std::shared_ptr<UType> keytype = GetUTypeByName(keyname);
		std::shared_ptr<UType> valuetype = GetUTypeByName(valuename);

		if (!keytype || !valuetype)
			return;

		std::shared_ptr<DictType> dictType = std::make_shared<DictType>(keytype, valuetype);
		if (dictType)
			CreateNewType(typeName, dictType);
	}

	void UType::ClearAllTypes()
	{
		GlobalTypes.clear();
	}

	std::shared_ptr<UType> UType::GetUTypeByName(std::string name)
	{
		if (GlobalTypes.find(name) == GlobalTypes.end())
			return nullptr;

		return GlobalTypes[name];
	}

}