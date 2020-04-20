#include "UnmanagedBuffer.hpp"

#include "UType.hpp"
#include "UIntType.hpp"
#include "UFloatType.hpp"
#include "UStringType.hpp"
#include "UListType.hpp"
#include "UDictType.hpp"
#include "UClassType.hpp"
#include "UObjectDefine.hpp"
#include "UTypeDefine.hpp"
#include "UObjectInt.hpp"
#include "UObjectString.hpp"
#include "UObjectList.hpp"
#include "UObjectDict.hpp"

#include "../Common/StringUtils.hpp"

using namespace UnmanagedBuffer;

int Initialise(const char* path)
{
	int initResult = SUNNY_NO_ERROR;

	if (UObject::UObjectCount != 0)
		return SUNNY_MEMORY_LEAK_ERROR;

	UType::ClearAllTypes();

	UType::CreateNewType("Int8", std::make_shared<Int8Type>());
	UType::CreateNewType("UInt8", std::make_shared<UInt8Type>());
	UType::CreateNewType("Int16", std::make_shared<Int16Type>());
	UType::CreateNewType("UInt16", std::make_shared<UInt16Type>());
	UType::CreateNewType("Int32", std::make_shared<Int32Type>());
	UType::CreateNewType("UInt32", std::make_shared<UInt32Type>());
	UType::CreateNewType("Int64", std::make_shared<Int64Type>());
	UType::CreateNewType("UInt64", std::make_shared<UInt64Type>());
	UType::CreateNewType("Float", std::make_shared<FloatType>());
	UType::CreateNewType("String", std::make_shared<StringType>());
	UType::CreateNewType("Unicode", std::make_shared<WStringType>());
	UType::CreateNewType("List", std::make_shared<ListType>());
	UType::CreateNewType("Dict", std::make_shared<DictType>());

	initResult = LoadTypesFromXml(path);

	if (initResult != SUNNY_NO_ERROR)
		UType::ClearAllTypes();

	return initResult;
}

void* UObject_New(const char* ctype)
{
	std::shared_ptr<UType> uType = UType::GetUTypeByName(ctype);
	if (uType == nullptr)
		return nullptr;

	auto uObj = UObject_GC_New(uType);

	return (void*)(uObj); 
}

void UObject_Delete(void* uObj)
{
	UObject_GC_Delete((UObject*)uObj);
}

Int32 UObject_RefCount(void* uObj)
{
	if (uObj == nullptr)
		return 0;

	return ((UObject*)uObj)->GetRefCount();
}

UInt64 UObject_AllCount()
{
	return UObject::UObjectCount;
}

Int8 UInt8Object_AsByte(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_Int8(uObj))
		return -1;

	auto uIntObj = (UInt8Object*)uObj;

	return uIntObj->GetVal();
}

void* UInt8Object_FromByte(Int8 value)
{
	auto uObj = (UInt8Object*)UObject_GC_New(UType::GetUTypeByName("Int8"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UInt8Object_SetByte(void* uObj, Int8 value)
{
	if (!UObject_Check_Int8((UObject*)uObj))
		return;

	auto intObj = (UInt8Object*)uObj;

	intObj->SetVal(value);

}

UInt8 UUInt8Object_AsSByte(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_UInt8(uObj))
		return -1;

	auto uIntObj = (UUInt8Object*)uObj;

	return uIntObj->GetVal();
}

void* UUInt8Object_FromSByte(UInt8 value)
{
	auto uObj = (UUInt8Object*)UObject_GC_New(UType::GetUTypeByName("UInt8"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UUInt8Object_SetSByte(void* uObj, UInt8 value)
{
	if (!UObject_Check_UInt8((UObject*)uObj))
		return;

	auto intObj = (UUInt8Object*)uObj;

	intObj->SetVal(value);
}

Int16 UInt16Object_AsShort(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_Int16(uObj))
		return -1;

	auto uIntObj = (UInt16Object*)uObj;

	return uIntObj->GetVal();
}

void* UInt16Object_FromShort(Int16 value)
{
	auto uObj = (UInt16Object*)UObject_GC_New(UType::GetUTypeByName("Int16"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UInt16Object_SetShort(void* uObj, Int16 value)
{
	if (!UObject_Check_Int16((UObject*)uObj))
		return;

	auto intObj = (UInt16Object*)uObj;

	intObj->SetVal(value);
}

UInt16 UUInt16Object_AsUShort(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_UInt16(uObj))
		return -1;

	auto uIntObj = (UUInt16Object*)uObj;

	return uIntObj->GetVal();
}

void* UUInt16Object_FromUShort(UInt16 value)
{
	auto uObj = (UUInt16Object*)UObject_GC_New(UType::GetUTypeByName("UInt16"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UUInt16Object_SetUShort(void* uObj, UInt16 value)
{
	if (!UObject_Check_UInt16((UObject*)uObj))
		return;

	auto intObj = (UUInt16Object*)uObj;

	intObj->SetVal(value);
}

Int32 UInt32Object_AsInt(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_Int32(uObj))
		return -1;

	auto uIntObj = (UInt32Object*)uObj;

	return uIntObj->GetVal();
}

void* UInt32Object_FromInt(Int32 value)
{
	auto uObj = (UInt32Object*)UObject_GC_New(UType::GetUTypeByName("Int32"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UInt32Object_SetInt(void* uObj, Int32 value)
{
	if (!UObject_Check_Int32((UObject*)uObj))
		return;

	auto intObj = (UInt32Object*)uObj;

	intObj->SetVal(value);
}

UInt32 UUInt32Object_AsUInt(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_UInt32(uObj))
		return -1;

	auto uIntObj = (UUInt32Object*)uObj;

	return uIntObj->GetVal();
}

void* UUInt32Object_FromUInt(UInt32 value)
{
	auto uObj = (UUInt32Object*)UObject_GC_New(UType::GetUTypeByName("UInt32"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UUInt32Object_SetUInt(void* uObj, UInt32 value)
{
	if (!UObject_Check_UInt32((UObject*)uObj))
		return;

	auto intObj = (UUInt32Object*)uObj;

	intObj->SetVal(value);
}

Int64 UInt64Object_AsLong(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_Int64(uObj))
		return -1;

	auto uIntObj = (UInt64Object*)uObj;

	return uIntObj->GetVal();
}

void* UInt64Object_FromLong(Int64 value)
{
	auto uObj = (UInt64Object*)UObject_GC_New(UType::GetUTypeByName("Int64"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UInt64Object_SetLong(void* uObj, Int64 value)
{
	if (!UObject_Check_Int64((UObject*)uObj))
		return;

	auto intObj = (UInt64Object*)uObj;

	intObj->SetVal(value);
}

UInt64 UUInt64Object_AsULong(void* puObj)
{
	auto uObj = (UObject*)puObj;

	if (!UObject_Check_UInt64(uObj))
		return -1;

	auto uIntObj = (UUInt64Object*)uObj;

	return uIntObj->GetVal();
}

void* UUInt64Object_FromULong(UInt64 value)
{
	auto uObj = (UUInt64Object*)UObject_GC_New(UType::GetUTypeByName("UInt64"));

	if (uObj)
		uObj->SetVal(value);

	return uObj;
}

void UUInt64Object_SetULong(void* uObj, UInt64 value)
{
	if (!UObject_Check_UInt64((UObject*)uObj))
		return;

	auto intObj = (UUInt64Object*)uObj;

	intObj->SetVal(value);
}

Float UFloatObject_AsFloat(void* uObj)
{
	if (!UObject_Check_Float((UObject*)uObj))
		return 0;

	auto floatObj = (UFloatObject*)uObj;

	return floatObj->GetVal();
}

void* UFloatObject_FromFloat(Float value)
{
	std::shared_ptr<UType> uType = UType::GetUTypeByName("Float");

	if (uType == nullptr)
		return nullptr;

	auto uObj = (UFloatObject*)UObject_GC_New(uType);
	uObj->SetVal(value);

	return uObj;
}

void UFloatObject_SetFloat(void* uObj, Float value)
{
	if (!UObject_Check_Float((UObject*)uObj))
		return;

	auto floatObj = (UFloatObject*)uObj;
	floatObj->SetVal(value);
}

void UStringObject_AsString(void* uObj, void** str)
{
	if (!UObject_Check_String((UObject*)uObj))
		return;

	auto stringObj = (UStringObject*)uObj;

	(*str) = (void*)stringObj->GetValStr();
}

void UUnicodeObject_AsUnicode(void* uObj, void** str)
{
	if (!UObject_Check_Unicode((UObject*)uObj))
		return;

	auto unicodeObj = (UWStringObject*)uObj;

	(*str) = (void*)unicodeObj->GetValStr();
}

void* UStringObject_FromString(const char* str)
{
	std::shared_ptr<UType> uType = UType::GetUTypeByName("String");

	if (uType == nullptr)
		return nullptr;

	auto uObj = (UStringObject*)UObject_GC_New(uType);

	if (uObj)
		uObj->SetVal(str);

	return (void*)uObj;
}

void* UUnicodeObject_FromUnicode(const char16_t* str)
{
	std::shared_ptr<UType> uType = UType::GetUTypeByName("Unicode");
	
	if (uType == nullptr)
		return nullptr;

	auto uObj = (UWStringObject*)UObject_GC_New(uType);

	uObj->SetVal(str);

	return (void*)uObj;
}

void UStringObject_SetString(void* uObj, const char* str)
{
	if (!UObject_Check_String((UObject*)uObj))
		return;

	auto stringObj = (UStringObject*)uObj;

	stringObj->SetVal(str);
}

void UUnicodeObject_SetUnicode(void* uObj, const char16_t* str)
{
	if (!UObject_Check_String((UObject*)uObj))
		return;

	auto unicodeObj = (UWStringObject*)uObj;

	unicodeObj->SetVal(str);
}

void UClassObject_SetField(void* uObj, const char* field, void* uField)
{
	if (!UObject_Check_Class((UObject*)uObj))
		return;

	if (uField == nullptr)
		return;

	auto classObj = (UClassObject*)uObj;

	if (!classObj->IsFieldExits(field))
		return;

	if (!classObj->SetField(field, (UObject*)uField))
		return;
}

void* UClassObject_GetField(void* uObj, const char* field)
{
	if (!UObject_Check_Class((UObject*)uObj))
		return nullptr;

	if (field == nullptr)
		return nullptr;

	auto classObj = (UClassObject*)uObj;

	return classObj->GetField(field);
}

Int32 UTypeList_New(const char* elementType)
{
	auto childType = UType::GetUTypeByName(elementType);
	if (!childType)
		return -1;

	std::string uTypeName = std::string("List<") + elementType + ">";

	std::shared_ptr<UType> uType = UType::GetUTypeByName(uTypeName);
	if (uType)
		return 0;

	uType = std::make_shared<ListType>(childType);
	UType::CreateNewType(uTypeName, uType);

	return 0;
}

Int32 UObjectList_Count(void* uObj)
{
	if (!UObject_Check_List((UObject*)uObj))
		return -1;

	auto list = (UListObject*)uObj;

	if (!list)
		return -1;

	return list->Size();
}

void* UObjectList_GetItem(void* uObj, Int32 index)
{
	if (!UObject_Check_List((UObject*)uObj))
		return nullptr;

	auto list = (UListObject*)uObj;

	if (!list)
		return nullptr;

	auto item = list->GetItem(index);

	return (void*)(item);
}

void UObjectList_SetItem(void* uObj, void* value, Int32 index)
{
	if (!UObject_Check_List((UObject*)uObj))
		return;

	auto list = (UListObject*)uObj;

	if (!list || !value)
		return;

	list->SetItem((UObject*)value, index);
}

void UObjectList_Append(void* uObj, void* value)
{
	if (!UObject_Check_List((UObject*)uObj))
		return;

	auto list = (UListObject*)uObj;

	if (!list || !value)
		return;

	list->Append((UObject*)value);
}

void UObjectList_Clear(void* uObj)
{
	if (!UObject_Check_List((UObject*)uObj))
		return;

	auto list = (UListObject*)uObj;

	if (!list)
		return;

	list->Clear();
}

Int32 UTypeDict_New(const char* keyType, const char* valueType)
{
	auto uKeyType = UType::GetUTypeByName(keyType);
	if (!uKeyType)
		return -1;

	auto uValueType = UType::GetUTypeByName(valueType);
	if (!uValueType)
		return -1;

	std::string uDictTypeName = "Dict<";
	uDictTypeName = uDictTypeName + keyType + "," + valueType + ">";

	std::shared_ptr<UType> uType = UType::GetUTypeByName(uDictTypeName);
	if (uType)
		return 0;

	std::shared_ptr<DictType> uDictType = std::make_shared<DictType>(uKeyType, uValueType);
	UType::CreateNewType(uDictTypeName, uDictType);

	return 0;
}

Int32 UObjectDict_Count(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return -1;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return -1;

	return dict->Size();
}

void* UObjectDict_GetItem(void* uObj, void* keyObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return nullptr;

	auto dict = (UDictObject*)uObj;

	if (!dict || !keyObj)
		return nullptr;

	return dict->GetItem((UObject*)keyObj);
}

void UObjectDict_SetItem(void* uObj, void* keyObj, void* valueObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return;

	auto dict = (UDictObject*)uObj;

	if (!dict || !keyObj || !valueObj)
		return;

	dict->SetItem((UObject*)keyObj, (UObject*)valueObj);
}

bool UObjectDict_RemoveItem(void* uObj, void* keyObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return false;

	auto dict = (UDictObject*)uObj;

	if (!dict || !keyObj)
		return false;

	return dict->RemoveItem((UObject*)keyObj);
}

bool UObjectDict_Contains(void* uObj, void* uKey)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return false;

	auto dict = (UDictObject*)uObj;

	if (!dict || !uKey)
		return false;

	return dict->Contains((UObject*)uKey);
}

void UObjectDict_Clear(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return;

	dict->Clear();
}

bool UObjectDict_MoveNext(void* uObj)
{
	//return true
	//over the loop
	if (!UObject_Check_Dict((UObject*)uObj))
		return true;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return true;

	return dict->MoveNext();
}

void* UObjectDict_Current(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return nullptr;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return nullptr;

	return (void*)dict->Current();
}

void UObjectDict_BeginLoop(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return;

	dict->BeginLoop();
}

void UObjectDict_EndLoop(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return;

	dict->EndLoop();
}

void* UObjectDict_AllKeys(void* uObj)
{
	if (!UObject_Check_Dict((UObject*)uObj))
		return nullptr;

	auto dict = (UDictObject*)uObj;

	if (!dict)
		return nullptr;

	return dict->AllKeys();
}

bool UObject_Check()
{
	auto& uObjs = UObject::UObjects;

	return true;
}

bool UObject_CheckInt8(void* uObj)
{
	return UObject_Check_Int8((UObject*)uObj);
}

bool UObject_CheckUInt8(void* uObj)
{
	return UObject_Check_UInt8((UObject*)uObj);
}

bool UObject_CheckInt16(void* uObj)
{
	return UObject_Check_Int16((UObject*)uObj);
}

bool UObject_CheckUInt16(void* uObj)
{
	return UObject_Check_UInt16((UObject*)uObj);
}

bool UObject_CheckInt32(void* uObj)
{
	return UObject_Check_Int32((UObject*)uObj);
}

bool UObject_CheckUInt32(void* uObj)
{
	return UObject_Check_UInt32((UObject*)uObj);
}

bool UObject_CheckInt64(void* uObj)
{
	return UObject_Check_Int64((UObject*)uObj);
}

bool UObject_CheckUInt64(void* uObj)
{
	return UObject_Check_UInt64((UObject*)uObj);
}

bool UObject_CheckFloat(void* uObj)
{
	return UObject_Check_Float((UObject*)uObj);
}

bool UObject_CheckString(void* uObj)
{
	return UObject_Check_String((UObject*)uObj);
}

bool UObject_CheckUnicode(void* uObj)
{
	return UObject_Check_Unicode((UObject*)uObj);
}

bool UObject_CheckClass(void* uObj)
{
	return UObject_Check_Class((UObject*)uObj);
}

bool UObject_CheckList(void* uObj)
{
	return UObject_Check_List((UObject*)uObj);
}

bool UObject_CheckDict(void* uObj)
{
	return UObject_Check_Dict((UObject*)uObj);
}

void* UObject_GetUTypeName(void* uObj)
{
	UType* uType = ((UObject*)uObj)->GetType();

	if (!uType)
		return nullptr;

	UObject* uTypeName = UObject_GC_New(UType::GetUTypeByName("Unicode"));
	std::string typeName = uType->Name();
	((UWStringObject*)uTypeName)->SetVal(std::u16string(typeName.begin(), typeName.end()));

	return uTypeName;
}

