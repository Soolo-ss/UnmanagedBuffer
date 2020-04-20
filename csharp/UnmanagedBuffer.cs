using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace SunnyMobile.UnmanagedBuffer
{
    public static class UnmanagedBuffer
    {
#if UNITY_ANDRIOD
        public const string LibName = "SunnyMobile2";
#else
        public const string LibName = "SunnyMobile2";
#endif
        [DllImport(LibName)]
        public extern static int Initialise(string path);

        [DllImport(LibName)]
        private extern static IntPtr UObject_New(string type);

        [DllImport(LibName)]
        private extern static void UObject_Delete(IntPtr uObj);

        [DllImport(LibName)]
        public extern static UInt64 UObject_AllCount();

        [DllImport(LibName)]
        public extern static byte UInt8Object_AsByte(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UInt8Object_FromByte(byte value);

        [DllImport(LibName)]
        public extern static void UInt8Object_SetByte(IntPtr uObj, byte value);

        [DllImport(LibName)]
        public extern static sbyte UUInt8Object_AsSByte(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UUInt8Object_FromSByte(sbyte value);

        [DllImport(LibName)]
        public extern static void UUInt8Object_SetSByte(IntPtr uObj, sbyte value);

        [DllImport(LibName)]
        public extern static short UInt16Object_AsShort(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UInt16Object_FromShort(short value);

        [DllImport(LibName)]
        public extern static void UInt16Object_SetShort(IntPtr uObj, short value);

        [DllImport(LibName)]
        public extern static ushort UUInt16Object_AsUShort(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UUInt16Object_FromUShort(ushort value);

        [DllImport(LibName)]
        public extern static void UUInt16Object_SetUShort(IntPtr uObj, ushort value);

        [DllImport(LibName)]
        public extern static int UInt32Object_AsInt(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UInt32Object_FromInt(int value);

        [DllImport(LibName)]
        public extern static void UInt32Object_SetInt(IntPtr uObj, int value);

        [DllImport(LibName)]
        public extern static uint UUInt32Object_AsUInt(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UUInt32Object_FromUInt(uint value);

        [DllImport(LibName)]
        public extern static void UUInt32Object_SetUInt(IntPtr uObj, uint value);

        [DllImport(LibName)]
        public extern static long UInt64Object_AsLong(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UInt64Object_FromLong(long value);

        [DllImport(LibName)]
        public extern static void UInt64Object_SetLong(IntPtr uObj, long value);

        [DllImport(LibName)]
        public extern static ulong UUInt64Object_AsULong(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UUInt64Object_FromULong(ulong value);

        [DllImport(LibName)]
        public extern static void UUInt64Object_SetULong(IntPtr uObj, ulong value);

        [DllImport(LibName)]
        public extern static float UFloatObject_AsFloat(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UFloatObject_FromFloat(float value);

        [DllImport(LibName)]
        public extern static void UFloatObject_SetFloat(IntPtr uObj, float value);

        [DllImport(LibName)]
        public extern static void UStringObject_AsString(IntPtr uObj, ref IntPtr str);

        [DllImport(LibName)]
        public extern static IntPtr UStringObject_FromString(string str);

        [DllImport(LibName)]
        public extern static void UStringObject_SetString(IntPtr uObj, string str);

        [DllImport(LibName)]
        public extern static void UUnicodeObject_AsUnicode(IntPtr uObj, ref IntPtr str);

        [DllImport(LibName)]
        public extern static IntPtr UUnicodeObject_FromUnicode(IntPtr str);

        [DllImport(LibName)]
        public extern static void UUnicodeObject_SetUnicode(IntPtr uObj, string str);

        [DllImport(LibName)]
        public extern static void UClassObject_SetField(IntPtr uObj, string field, IntPtr uField);

        [DllImport(LibName)]
        public extern static IntPtr UClassObject_GetField(IntPtr uObj, string field);

        [DllImport(LibName)]
        public extern static Int32 UTypeList_New(string valueType);

        [DllImport(LibName)]
        public extern static Int32 UObjectList_Count(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UObjectList_GetItem(IntPtr uObj, Int32 index);

        [DllImport(LibName)]
        public extern static void UObjectList_Append(IntPtr uObj, IntPtr value);

        [DllImport(LibName)]
        public extern static void UObjectList_SetItem(IntPtr uObj, IntPtr value, Int32 index);

        [DllImport(LibName)]
        public extern static void UObjectList_Clear(IntPtr uObj);

        [DllImport(LibName)]
        public extern static Int32 UTypeDict_New(string keyType, string valueType);

        [DllImport(LibName)]
        public extern static Int32 UObjectDict_Count(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UObjectDict_GetItem(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public extern static void UObjectDict_SetItem(IntPtr uObj, IntPtr key, IntPtr value);

        [DllImport(LibName)]
        public extern static bool UObjectDict_Contains(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public extern static void UObjectDict_Clear(IntPtr uObj);

        [DllImport(LibName)]
        public extern static bool UObjectDict_RemoveItem(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public extern static void UObjectDict_BeginLoop(IntPtr uObj);

        [DllImport(LibName)]
        public extern static bool UObjectDict_MoveNext(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UObjectDict_Current(IntPtr uObj);

        [DllImport(LibName)]
        public extern static void UObjectDict_EndLoop(IntPtr uObj);

        [DllImport(LibName)]
        public extern static IntPtr UObjectDict_AllKeys(IntPtr uObj);

        [DllImport(LibName)]
        public extern static bool UObject_Check();

        [DllImport(LibName)]
        public extern static IntPtr UObject_GetUTypeName(IntPtr uObj);

        [DllImport(LibName)]
        public extern static void Release();

        public static IntPtr UObject_GC_New(string uType)
        {
            return UObject_New(uType);
        }

        public static void UObject_GC_Delete(IntPtr uObj)
        {
            UObject_Delete(uObj);
        }
    }
}
