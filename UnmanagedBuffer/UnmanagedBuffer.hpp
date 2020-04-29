#pragma once

#include "../Common/Common.hpp"


/*
* @brief 初始化UnmanagedBuffer
* @param path types.xml绝对路径
*/
EXPORT int Initialise(const char* path);

/*
* @brief 创建一个UObject
* @param uType 类型名称
*/
EXPORT void* UObject_New(const char* uType);

/*
* @brief 删除一个UObject(减小引用计数)
* @param uObj 
*/
EXPORT void UObject_Delete(void* uObj);
/*
* @brief 返回UObject的引用计数
* @param uObj
*/
EXPORT Int32 UObject_RefCount(void* uObj);
/*
* @brief 获取UObject的Count
*/
EXPORT UInt64 UObject_AllCount();

/*
* @brief UInObject的函数簇
*/
EXPORT Int8 UInt8Object_AsByte(void* uObj);
EXPORT void* UInt8Object_FromByte(Int8 value);
EXPORT void UInt8Object_SetByte(void* uObj, Int8 value);

EXPORT UInt8 UUInt8Object_AsSByte(void* uObj);
EXPORT void* UUInt8Object_FromSByte(UInt8 value);
EXPORT void UUInt8Object_SetSByte(void* uObj, UInt8 value);

EXPORT Int16 UInt16Object_AsShort(void* uObj);
EXPORT void* UInt16Object_FromShort(Int16 value);
EXPORT void UInt16Object_SetShort(void* uObj, Int16 value);

EXPORT UInt16 UUInt16Object_AsUShort(void* uObj);
EXPORT void* UUInt16Object_FromUShort(UInt16 value);
EXPORT void UUInt16Object_SetUShort(void* uObj, UInt16 value);

EXPORT Int32 UInt32Object_AsInt(void* uObj);
EXPORT void* UInt32Object_FromInt(Int32 value);
EXPORT void UInt32Object_SetInt(void* uObj, Int32 value);

EXPORT UInt32 UUInt32Object_AsUInt(void* uObj);
EXPORT void* UUInt32Object_FromUInt(UInt32 value);
EXPORT void UUInt32Object_SetUInt(void* uObj, UInt32 value);

EXPORT Int64 UInt64Object_AsLong(void* uObj);
EXPORT void* UInt64Object_FromLong(Int64 value);
EXPORT void UInt64Object_SetLong(void* uObj, Int64 value);

EXPORT UInt64 UUInt64Object_AsULong(void* uObj);
EXPORT void* UUInt64Object_FromULong(UInt64 value);
EXPORT void UUInt64Object_SetULong(void* uObj, UInt64 value);

/*
* @brief UFloatObject的函数簇
*/
EXPORT Float UFloatObject_AsFloat(void* uObj);
EXPORT void* UFloatObject_FromFloat(Float value);
EXPORT void UFloatObject_SetFloat(void* uObj, Float value);

/*
* @brief UStringObject的函数簇
*/
EXPORT void UStringObject_AsString(void* uOb, void** str);
EXPORT void* UStringObject_FromString(const char* str);
EXPORT void UStringObject_SetString(void* uObj, const char* str);

/*
* @brief UUnicodeObject的函数簇
*/
EXPORT void UUnicodeObject_AsUnicode(void* uObj, void** str);
EXPORT void* UUnicodeObject_FromUnicode(const char16_t* str);
EXPORT void UUnicodeObject_SetUnicode(void* uObj, const char16_t* str);

/*
* @brief UClassObject的函数簇
*/
EXPORT void UClassObject_SetField(void* uObj, const char* field, void* uField);
EXPORT void* UClassObject_GetField(void* uObj, const char* field);

/*
* @brief UListObject的函数簇
*/
EXPORT Int32 UObjectList_Count(void* uObj);
EXPORT void* UObjectList_GetItem(void* uObj, Int32 index);
EXPORT void UObjectList_SetItem(void* uObj, void* value, Int32 index);
EXPORT void UObjectList_Append(void* uObj, void* value);
EXPORT void UObjectList_Clear(void* uObj);

/*
* @brief UDictObject的函数簇
*/
EXPORT Int32 UObjectDict_Count(void* uObj);
EXPORT void* UObjectDict_GetItem(void* uObj, void* keyObj);
EXPORT void UObjectDict_SetItem(void* uObj, void* keyObj, void* valueObj);
EXPORT bool UObjectDict_RemoveItem(void* uObj, void* keyObj);
EXPORT bool UObjectDict_Contains(void* uObj, void* keyObj);
EXPORT void UObjectDict_Clear(void* uObj);
EXPORT void UObjectDict_BeginLoop(void* uObj);
EXPORT bool UObjectDict_MoveNext(void* uObj);
EXPORT void* UObjectDict_Current(void* uObj);
EXPORT void UObjectDict_EndLoop(void* uObj);
EXPORT void* UObjectDict_AllKeys(void* uObj);

/*
* @brief 检查UObject的类型的函数簇
*/
EXPORT bool UObject_CheckInt8(void* uObj);
EXPORT bool UObject_CheckUInt8(void* uObj);
EXPORT bool UObject_CheckInt16(void* uObj);
EXPORT bool UObject_CheckUInt16(void* uObj);
EXPORT bool UObject_CheckInt32(void* uObj);
EXPORT bool UObject_CheckUInt32(void* uObj);
EXPORT bool UObject_CheckInt64(void* uObj);
EXPORT bool UObject_CheckUInt64(void* uObj);
EXPORT bool UObject_CheckFloat(void* uObj);
EXPORT bool UObject_CheckString(void* uObj);
EXPORT bool UObject_CheckUnicode(void* uObj);
EXPORT bool UObject_CheckClass(void* uObj);
EXPORT bool UObject_CheckList(void* uObj);
EXPORT bool UObject_CheckDict(void* uObj);

/*
* @brief 获取UObject的UType名称
*/
EXPORT void* UObject_GetUTypeName(void* uObj);

/*
* @brief UnmanagedBuffer的释放
* 
* Release 不会释放掉所有UObject
* 调用Relase前确保所有UObject已经被正确释放
* 没有释放的UObject会泄露 使用此类UObject的行为未定义
*/
EXPORT void Release();
