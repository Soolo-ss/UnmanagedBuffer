#pragma once

#include "UObject.hpp"

namespace UnmanagedBuffer
{
	//创建一个新的UObject
	//这个新的UObject会被存入UObject的池中
	//并且引用计数默认为1 
	//也就是说 如果不调用UObject_GC_Delete  这个UObject永远不会被销毁
	UObject* UObject_GC_New(std::shared_ptr<UType> utype);

	//删除一个UObject
	//引用计数减一
	//为零则销毁对象
	void UObject_GC_Delete(UObject* uObj);

	void UObject_Add_RefCount(UObject* uObk);

	bool UObject_Check_Int8(UObject* uObj);
	bool UObject_Check_UInt8(UObject* uObj);
	bool UObject_Check_Int16(UObject* uObj);
	bool UObject_Check_UInt16(UObject* uObj);
	bool UObject_Check_Int32(UObject* uObj);
	bool UObject_Check_UInt32(UObject* uObj);
	bool UObject_Check_Int64(UObject* uObj);
	bool UObject_Check_UInt64(UObject* uObj);
	bool UObject_Check_Float(UObject* uObj);
	bool UObject_Check_String(UObject* uObj);
	bool UObject_Check_Unicode(UObject* uObj);
	bool UObject_Check_List(UObject* uObj);
	bool UObject_Check_Dict(UObject* uObj);
	bool UObject_Check_Class(UObject* uObj);
}


