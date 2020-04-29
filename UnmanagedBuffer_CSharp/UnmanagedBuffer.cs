using System;
using System.Runtime.InteropServices;

namespace UnmanagedBuffer
{
    public static class UnmanagedBuffer
    {
#if UNITY_ANDRIOD
        public const string LibName = "UnmanagedBuffer";
#else
        public const string LibName = "UnmanagedBuffer";
#endif

        #region interface
        [DllImport(LibName)]
        public static extern int Initialise(string path);

        [DllImport(LibName)]
        private static extern IntPtr UObject_New(string type);

        [DllImport(LibName)]
        private static extern bool UObject_Delete(IntPtr uObj);

        [DllImport(LibName)]
        public static extern UInt64 UObject_AllCount();

        [DllImport(LibName)]
        public static extern byte UInt8Object_AsByte(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UInt8Object_FromByte(byte value);

        [DllImport(LibName)]
        public static extern void UInt8Object_SetByte(IntPtr uObj, byte value);

        [DllImport(LibName)]
        public static extern sbyte UUInt8Object_AsSByte(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UUInt8Object_FromSByte(sbyte value);

        [DllImport(LibName)]
        public static extern void UUInt8Object_SetSByte(IntPtr uObj, sbyte value);

        [DllImport(LibName)]
        public static extern short UInt16Object_AsShort(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UInt16Object_FromShort(short value);

        [DllImport(LibName)]
        public static extern void UInt16Object_SetShort(IntPtr uObj, short value);

        [DllImport(LibName)]
        public static extern ushort UUInt16Object_AsUShort(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UUInt16Object_FromUShort(ushort value);

        [DllImport(LibName)]
        public static extern void UUInt16Object_SetUShort(IntPtr uObj, ushort value);

        [DllImport(LibName)]
        public static extern int UInt32Object_AsInt(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UInt32Object_FromInt(int value);

        [DllImport(LibName)]
        public static extern void UInt32Object_SetInt(IntPtr uObj, int value);

        [DllImport(LibName)]
        public static extern uint UUInt32Object_AsUInt(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UUInt32Object_FromUInt(uint value);

        [DllImport(LibName)]
        public static extern void UUInt32Object_SetUInt(IntPtr uObj, uint value);

        [DllImport(LibName)]
        public static extern long UInt64Object_AsLong(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UInt64Object_FromLong(long value);

        [DllImport(LibName)]
        public static extern void UInt64Object_SetLong(IntPtr uObj, long value);

        [DllImport(LibName)]
        public static extern ulong UUInt64Object_AsULong(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UUInt64Object_FromULong(ulong value);

        [DllImport(LibName)]
        public static extern void UUInt64Object_SetULong(IntPtr uObj, ulong value);

        [DllImport(LibName)]
        public static extern float UFloatObject_AsFloat(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UFloatObject_FromFloat(float value);

        [DllImport(LibName)]
        public static extern void UFloatObject_SetFloat(IntPtr uObj, float value);

        [DllImport(LibName)]
        public static extern void UStringObject_AsString(IntPtr uObj, ref IntPtr str);

        [DllImport(LibName)]
        public static extern IntPtr UStringObject_FromString(string str);

        [DllImport(LibName)]
        public static extern void UStringObject_SetString(IntPtr uObj, string str);

        [DllImport(LibName)]
        public static extern void UUnicodeObject_AsUnicode(IntPtr uObj, ref IntPtr str);

        [DllImport(LibName)]
        public static extern IntPtr UUnicodeObject_FromUnicode(IntPtr str);

        [DllImport(LibName)]
        public static extern void UUnicodeObject_SetUnicode(IntPtr uObj, string str);

        [DllImport(LibName)]
        public static extern void UClassObject_SetField(IntPtr uObj, string field, IntPtr uField);

        [DllImport(LibName)]
        public static extern IntPtr UClassObject_GetField(IntPtr uObj, string field);

        [DllImport(LibName)]
        public static extern Int32 UTypeList_New(string valueType);

        [DllImport(LibName)]
        public static extern Int32 UObjectList_Count(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UObjectList_GetItem(IntPtr uObj, Int32 index);

        [DllImport(LibName)]
        public static extern void UObjectList_Append(IntPtr uObj, IntPtr value);

        [DllImport(LibName)]
        public static extern void UObjectList_SetItem(IntPtr uObj, IntPtr value, Int32 index);

        [DllImport(LibName)]
        public static extern void UObjectList_Clear(IntPtr uObj);

        [DllImport(LibName)]
        public static extern Int32 UTypeDict_New(string keyType, string valueType);

        [DllImport(LibName)]
        public static extern Int32 UObjectDict_Count(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UObjectDict_GetItem(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public static extern void UObjectDict_SetItem(IntPtr uObj, IntPtr key, IntPtr value);

        [DllImport(LibName)]
        public static extern bool UObjectDict_Contains(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public static extern void UObjectDict_Clear(IntPtr uObj);

        [DllImport(LibName)]
        public static extern bool UObjectDict_RemoveItem(IntPtr uObj, IntPtr key);

        [DllImport(LibName)]
        public static extern void UObjectDict_BeginLoop(IntPtr uObj);

        [DllImport(LibName)]
        public static extern bool UObjectDict_MoveNext(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UObjectDict_Current(IntPtr uObj);

        [DllImport(LibName)]
        public static extern void UObjectDict_EndLoop(IntPtr uObj);

        [DllImport(LibName)]
        public static extern IntPtr UObjectDict_AllKeys(IntPtr uObj);

        [DllImport(LibName)]
        public static extern bool UObject_Check();

        [DllImport(LibName)]
        public static extern IntPtr UObject_GetUTypeName(IntPtr uObj);

        [DllImport(LibName)]
        public static extern void Release();

        #endregion 


        public static UObject UObject_GC_New(string uType)
        {
            return new UObject(UObject_New(uType));
        }

        public static void UObject_GC_Delete(IntPtr uObj)
        {
            UObject_Delete(uObj);
        }

        /// <summary>
        /// Native UObjecet Re
        /// </summary>
        /// <param name="uObj"></param>
        /// <returns></returns>
        public static bool UObject_GC_Delete(UObject uObj)
        {
            return UObject_Delete(uObj.Address);
        }
    }
}
