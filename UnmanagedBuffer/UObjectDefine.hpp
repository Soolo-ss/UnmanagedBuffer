#pragma once

#include "UObject.hpp"

namespace UnmanagedBuffer
{
	//����һ���µ�UObject
	//����µ�UObject�ᱻ����UObject�ĳ���
	//�������ü���Ĭ��Ϊ1 
	//Ҳ����˵ ���������UObject_GC_Delete  ���UObject��Զ���ᱻ����
	UObject* UObject_GC_New(std::shared_ptr<UType> utype);

	//ɾ��һ��UObject
	//���ü�����һ
	//Ϊ�������ٶ���
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


