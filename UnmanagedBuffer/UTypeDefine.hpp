#pragma once

#include "UType.hpp"
#include "../rapidxml/rapidxml.hpp"

namespace UnmanagedBuffer
{
	int LoadPreDefinedTypesFromXml(rapidxml::xml_node<>* node);

	int LoadUserDefinedTypesFromXml(rapidxml::xml_node<>* node);

	int LoadTypesFromXml(std::string xmlpath);
}
