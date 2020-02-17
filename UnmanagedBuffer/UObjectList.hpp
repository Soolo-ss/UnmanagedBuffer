#pragma once

#include "UObject.hpp"

namespace UnmanagedBuffer
{
	class UListObject : public UObject
	{
	public:
		UListObject(UType* uType);

		~UListObject();

		Int32 Size();

		UObject* GetItem(Int32 index);

		Int32 SetItem(UObject* newItem, Int32 index);

		Int32 Insert(UObject* newItem, Int32 index);

		Int32 Append(UObject* newItem);

		void Clear();

	private:
		std::vector<UObject*> list_;
	};
}
