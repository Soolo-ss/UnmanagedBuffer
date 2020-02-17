#pragma once

#include "UObject.hpp"

namespace UnmanagedBuffer
{
	class UClassObject : public UObject
	{
	public:
		UClassObject(UType* uType);

		~UClassObject();

		void InitFields();

		UObject* GetField(std::string name);

		UObject* GetFieldByIndex(Int32 index);

		bool SetField(std::string name, UObject* field);

		bool IsFieldExits(std::string name);
	private:
		void AddField(Int32 index, UObject* uFieldObj);

	private:
		UObject** m_Fields;
	};
}
