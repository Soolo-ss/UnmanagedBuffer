#include "UTypeDefine.hpp"

#include "UnmanagedBuffer.hpp"
#include "UClassType.hpp"
#include "../Common/StringUtils.hpp"

namespace UnmanagedBuffer
{
	static std::vector<std::string> Integer = {
		"bool", "byte", "sbyte", "short", "ushort", "uint", "int", "ulong", "long", "char"
	};

	static std::string GetTypeName(rapidxml::xml_node<>* node)
	{
		std::string str_value = node->name();
		if (str_value.empty())
			return std::string();
		StringUtils::trim(str_value);

		return str_value;
	}

	static int GetTypeFromDescription(rapidxml::xml_node<>* node, std::pair<std::string, std::shared_ptr<UType>>& type)
	{
		if (node->value_size() == 0 || node->name_size() == 0)
			return SUNNY_PARSE_TYPES_ERROR;

		std::string typeName = node->name();
		std::string typeTypeName = node->value();

		StringUtils::trim(typeName);
		StringUtils::trim(typeTypeName);

		type.first = typeName;

		if (typeTypeName == "List")
		{
			rapidxml::xml_node<>* element = node->first_node("of");

			if (!element)
				type.second = UType::GetUTypeByName("List");
			else
			{
				if (element->value_size() == 0)
					return SUNNY_PARSE_TYPES_ERROR;

				std::pair<std::string, std::shared_ptr<UType>> elementTypeInfo;

				if (GetTypeFromDescription(element, elementTypeInfo) != SUNNY_NO_ERROR)
					return SUNNY_PARSE_TYPES_ERROR;

				if (elementTypeInfo.second == nullptr)
					return SUNNY_PARSE_TYPES_ERROR;

				type.second = UType::GetUTypeByName("List<" + elementTypeInfo.second->Name()+ ">");

				if (type.second == nullptr)
				{
					UTypeList_New(elementTypeInfo.second->Name().c_str());
					type.second = UType::GetUTypeByName("List<" + elementTypeInfo.second->Name() + ">");
				}
			}
		}
		else if (typeTypeName == "char")
		{
			type.second = UType::GetUTypeByName("Int8");
		}
		else if (typeTypeName == "bool")
		{
			type.second = UType::GetUTypeByName("Int8");
		}
		else if (typeTypeName == "byte")
		{
			type.second = UType::GetUTypeByName("Int8");
		}
		else if (typeTypeName == "sbyte")
		{
			type.second = UType::GetUTypeByName("UInt8");
		}
		else if (typeTypeName == "short")
		{
			type.second = UType::GetUTypeByName("Int16");
		}
		else if (typeTypeName == "ushort")
		{
			type.second = UType::GetUTypeByName("UInt16");
		}
		else if (typeTypeName == "int")
		{
			type.second = UType::GetUTypeByName("Int32");
		}
		else if (typeTypeName == "uint")
		{
			type.second = UType::GetUTypeByName("UInt32");
		}
		else if (typeTypeName == "long")
		{
			type.second = UType::GetUTypeByName("Int64");
		}
		else if (typeTypeName == "ulong")
		{
			type.second = UType::GetUTypeByName("UInt64");
		}
		else if (typeTypeName == "string")
		{
			type.second = UType::GetUTypeByName("String");
		}
		else if (typeTypeName == "unicode")
		{
			type.second = UType::GetUTypeByName("Unicode");
		}
		else if (typeTypeName == "float")
		{
			type.second = UType::GetUTypeByName("Float");
		}
		else
		{
			type.second = UType::GetUTypeByName(typeTypeName);
			if (type.second == nullptr)
				return SUNNY_PARSE_TYPES_ERROR;
		}

		return SUNNY_NO_ERROR;
	}

	int LoadTypesFromXml(std::string xmlpath)
	{
		try
		{
			rapidxml::file<> file(xmlpath.c_str());

			rapidxml::xml_document<> document;
			document.parse<rapidxml::parse_declaration_node>(file.data());

			auto rootNode = document.first_node("root");
			if (rootNode == nullptr)
				return SUNNY_PARSE_TYPES_ERROR;

			auto preDefinedNode = rootNode->first_node("PreDefine");
			if (preDefinedNode)
			{
				if (LoadPreDefinedTypesFromXml(preDefinedNode) != SUNNY_NO_ERROR)
					return SUNNY_PARSE_TYPES_ERROR;
			}

			auto userDefinedNode = rootNode->first_node("UserDefine");
			if (userDefinedNode)
			{
				if (LoadUserDefinedTypesFromXml(userDefinedNode) != SUNNY_NO_ERROR)
					return SUNNY_PARSE_TYPES_ERROR;
			}
		}
		catch (std::runtime_error& e)
		{
			return SUNNY_FILE_NOT_FOUND_ERROR;
		}

		return 0;
	}

	int LoadPreDefinedTypesFromXml(rapidxml::xml_node<>* node)
	{
		rapidxml::xml_node<>* current = node->first_node();

		while (current != nullptr)
		{
			std::string uTypeName = GetTypeName(current);
			if (uTypeName.empty())
				return SUNNY_PARSE_TYPES_ERROR;

			std::pair<std::string, std::shared_ptr<UType>> typeInfo;

			rapidxml::xml_node<>* properties = current->first_node("Properties");
			if (properties == nullptr)
			{
				if (GetTypeFromDescription(current, typeInfo) != SUNNY_NO_ERROR)
					return SUNNY_PARSE_TYPES_ERROR;

				UType::CreateNewType(uTypeName, typeInfo.second);
			}
			else
			{
				std::shared_ptr<ClassType> uType = std::make_shared<ClassType>(uTypeName);

				rapidxml::xml_node<>* property = properties->first_node();

				while (property != nullptr)
				{
					std::pair<std::string, std::shared_ptr<UType>> propertyTypeInfo;

					if (GetTypeFromDescription(property, propertyTypeInfo) != SUNNY_NO_ERROR)
						return SUNNY_PARSE_TYPES_ERROR;

					uType->AddField(propertyTypeInfo.first, propertyTypeInfo.second);

					property = property->next_sibling();
				}

				UType::CreateNewType(uTypeName, uType);
			}

			current = current->next_sibling();
		}
	
		return SUNNY_NO_ERROR;
	}

	int LoadUserDefinedTypesFromXml(rapidxml::xml_node<>* node)
	{
		auto current = node->first_node();
		if (current == nullptr)
			return -1;

		while (current != nullptr)
		{
			std::string uTypeName = GetTypeName(current);
			
			std::shared_ptr<ClassType> type = std::make_shared<ClassType>();

			rapidxml::xml_node<>* properties = current->first_node("Properties");

			if (properties != nullptr)
			{
				auto property = properties->first_node();

				while (property != nullptr)
				{
					std::pair<std::string, std::shared_ptr<UType>> propertyTypeInfo;

					if (GetTypeFromDescription(property, propertyTypeInfo) != SUNNY_NO_ERROR)
						return SUNNY_PARSE_TYPES_ERROR;

					type->AddField(propertyTypeInfo.first, propertyTypeInfo.second);

					property = property->next_sibling();
				}
			}
			else
			{
				return SUNNY_PARSE_TYPES_ERROR;
			}

			UType::CreateNewType(uTypeName, type);

			current = current->next_sibling();
		}

		return SUNNY_NO_ERROR;
	}
}