#pragma once

#include "UObject.hpp"

#include "UObjectInt.hpp"
#include "UObjectString.hpp"
#include "UObjectList.hpp"

namespace UnmanagedBuffer
{
	struct UDictKeyHash
	{
		std::size_t operator()(const UObject* k) const
		{
			using std::size_t;
			using std::hash;

			auto type = k->GetType(); 

			return type->Hash(k);
		}
	};

	struct UDictKeyComparer
	{
		bool operator()(const UObject* lhs, const UObject* rhs) const
		{
			UType* lhsType = lhs->GetType();
			UType* rhsType = rhs->GetType();
			
			if (lhsType != rhsType)
				return false;

			UTypeType lhsTypeType = lhsType->GetTypeType();

			if (lhsTypeType == UTypeType::UTYPE_INT8)
			{
				UInt8Object* uilhs = (UInt8Object*)lhs;
				UInt8Object* uirhs = (UInt8Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_UINT8)
			{
				UUInt8Object* uilhs = (UUInt8Object*)lhs;
				UUInt8Object* uirhs = (UUInt8Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_INT16)
			{
				UInt16Object* uilhs = (UInt16Object*)lhs;
				UInt16Object* uirhs = (UInt16Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_UINT16)
			{
				UUInt16Object* uilhs = (UUInt16Object*)lhs;
				UUInt16Object* uirhs = (UUInt16Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_INT32)
			{
				UInt32Object* uilhs = (UInt32Object*)lhs;
				UInt32Object* uirhs = (UInt32Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;
				
				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_UINT32)
			{
				UUInt32Object* uilhs = (UUInt32Object*)lhs;
				UUInt32Object* uirhs = (UUInt32Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_INT64)
			{
				UInt64Object* uilhs = (UInt64Object*)lhs;
				UInt64Object* uirhs = (UInt64Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_UINT64)
			{
				UUInt64Object* uilhs = (UUInt64Object*)lhs;
				UUInt64Object* uirhs = (UUInt64Object*)rhs;

				if (uilhs->GetVal() == uirhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_STRING)
			{
				UStringObject* uslhs = (UStringObject*)lhs;
				UStringObject* usrhs = (UStringObject*)rhs;

				if (uslhs->GetVal() == usrhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_WSTRING)
			{
				UWStringObject* uwslhs = (UWStringObject*)lhs;
				UWStringObject* uwsrhs = (UWStringObject*)rhs;

				if (uwslhs->GetVal() == uwsrhs->GetVal())
					return true;

				return false;
			}
			else if (lhsTypeType == UTypeType::UTYPE_LIST || lhsTypeType == UTypeType::UTYPE_DICT)
			{
				return false;
			}
			else
			{
				return lhs == rhs;
			}

			return false;
		}
	};

	class UDictObject : public UObject
	{
	public:
		UDictObject(UType* uType);

		~UDictObject();

		Int32 Size();

		Int32 SetItem(UObject* key, UObject* value);

		UObject* GetItem(UObject* key);

		bool RemoveItem(UObject* key);

		bool Contains(UObject* key);

		void Clear();

		void BeginLoop();

		bool MoveNext();

		UObject* Current();

		void EndLoop();

		UListObject* AllKeys();
	private:
		std::unordered_map<UObject*, UObject*, UDictKeyHash, UDictKeyComparer> dict_;
		//google::dense_hash_map<UObject*, UObject*, UDictKeyHash, UDictKeyComparer> dict_;
		std::vector<UObject*> iterator_;
		Int32 index_;
	};
}
