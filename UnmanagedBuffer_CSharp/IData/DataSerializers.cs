using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;
using System.Runtime.InteropServices;

namespace UnmanagedBuffer
{
    /// <summary>
    /// 原生类型转化为Native类型的转换器
    /// </summary>
    public interface IDataSerializerBase
    {
        IntPtr UObjectNew(Type t, object value);

        object LoadValue(Type t, IntPtr uObj);

        void StoreValue(Type t, IntPtr uObj, object value);

        string UnmanagedName(Type t);
    }

    public interface IDataSerializer<T> : IDataSerializerBase
    {
        IntPtr UObjectNew(T value);

        T LoadValue(IntPtr uObj);

        void StoreValue(IntPtr uObj, T value);

        string UnmanagedName();
    }

    public class IntPtrSerializer : IDataSerializer<IntPtr>
    {
        public IntPtr UObjectNew(IntPtr value)
        {
            throw new NotImplementedException();
        }

        public IntPtr LoadValue(IntPtr uObj)
        {
            throw new NotImplementedException();
        }

        public void StoreValue(IntPtr uObj, IntPtr value)
        {
            throw new NotImplementedException();
        }

        public string UnmanagedName()
        {
            throw new NotImplementedException();
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            throw new NotImplementedException();
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            throw new NotImplementedException();
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            throw new NotImplementedException();
        }

        public string UnmanagedName(Type t)
        {
            throw new NotImplementedException();
        }
    }

    public class CharSerializer : IDataSerializer<char>
    {
        public IntPtr UObjectNew(char value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte(Convert.ToByte(value));
        }

        public char LoadValue(IntPtr uObj)
        {
            return Convert.ToChar(UnmanagedBuffer.UInt8Object_AsByte(uObj));
        }

        public void StoreValue(IntPtr uObj, char value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, Convert.ToByte(value));
        }

        public string UnmanagedName()
        {
            return "Int8";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte(Convert.ToByte(value));
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return Convert.ToChar(UnmanagedBuffer.UInt8Object_AsByte(uObj));
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, Convert.ToByte(value));
        }

        public string UnmanagedName(Type t)
        {
            return "Int8";
        }
    }

    public class BoolSerializer : IDataSerializer<bool>
    {
        public IntPtr UObjectNew(bool value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte(Convert.ToByte(value));
        }

        public bool LoadValue(IntPtr uObj)
        {
            return Convert.ToBoolean(UnmanagedBuffer.UInt8Object_AsByte(uObj));
        }

        public void StoreValue(IntPtr uObj, bool value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, Convert.ToByte(value));
        }

        public string UnmanagedName()
        {
            return "Int8";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte(Convert.ToByte(value));
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return Convert.ToBoolean(UnmanagedBuffer.UInt8Object_AsByte(uObj));
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, Convert.ToByte(value));
        }

        public string UnmanagedName(Type t)
        {
            return "Int8";
        }
    }

    public class FloatSerializer : IDataSerializer<float>
    {
        public IntPtr UObjectNew(float value)
        {
            return UnmanagedBuffer.UFloatObject_FromFloat(value);
        }

        public float LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UFloatObject_AsFloat(uObj);
        }

        public void StoreValue(IntPtr uObj, float value)
        {
            UnmanagedBuffer.UFloatObject_SetFloat(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Float";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UFloatObject_FromFloat((float)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UFloatObject_AsFloat(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UFloatObject_SetFloat(uObj, (float)value);
        }

        public string UnmanagedName(Type t)
        {
            return "Float";
        }
    }

    public class DoubleSerializer : IDataSerializer<double>
    {
        public IntPtr UObjectNew(double value)
        {
            return UnmanagedBuffer.UFloatObject_FromFloat(Convert.ToSingle(value));
        }

        public double LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UFloatObject_AsFloat(uObj);
        }

        public void StoreValue(IntPtr uObj, double value)
        {
            UnmanagedBuffer.UFloatObject_SetFloat(uObj, Convert.ToSingle(value));
        }

        public string UnmanagedName()
        {
            return "Float";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UFloatObject_FromFloat(Convert.ToSingle(value));
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UFloatObject_AsFloat(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UFloatObject_SetFloat(uObj, Convert.ToSingle(value));
        }

        public string UnmanagedName(Type t)
        {
            return "Float";
        }
    }

    public class IntSerializer : IDataSerializer<int>
    {
        public IntPtr UObjectNew(int value)
        {
            return UnmanagedBuffer.UInt32Object_FromInt(value);
        }

        public Int32 LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UInt32Object_AsInt(uObj); 
        }

        public void StoreValue(IntPtr uObj, int value)
        {
            UnmanagedBuffer.UInt32Object_SetInt(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Int32";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt32Object_FromInt((int)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UInt32Object_AsInt(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt32Object_SetInt(uObj, (int)value);
        }

        public string UnmanagedName(Type t)
        {
            return "Int32";
        }
    }

    public class UIntSerializer : IDataSerializer<UInt32>
    {
        public IntPtr UObjectNew(uint value)
        {
            return UnmanagedBuffer.UUInt32Object_FromUInt(value);
        }

        public UInt32 LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt32Object_AsUInt(uObj);
        }

        public void StoreValue(IntPtr uObj, uint value)
        {
            UnmanagedBuffer.UUInt32Object_SetUInt(uObj, value);
        }

        public string UnmanagedName()
        {
            return "UInt32";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UUInt32Object_FromUInt((uint)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt32Object_AsUInt(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UUInt32Object_SetUInt(uObj, (uint)value);
        }

        public string UnmanagedName(Type t)
        {
            return "UInt32";
        }
    }

    public class ByteSerializer : IDataSerializer<Byte>
    {
        public IntPtr UObjectNew(byte value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte(value);
        }

        public Byte LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UInt8Object_AsByte(uObj);
        }

        public void StoreValue(IntPtr uObj, byte value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Int8";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt8Object_FromByte((byte)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UInt8Object_AsByte(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt8Object_SetByte(uObj, (byte)value);
        }

        public string UnmanagedName(Type t)
        {
            return "Int8";
        }
    }

    public class SByteSerializer : IDataSerializer<SByte>
    {
        public IntPtr UObjectNew(sbyte value)
        {
            return UnmanagedBuffer.UUInt8Object_FromSByte(value);
        }

        public SByte LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt8Object_AsSByte(uObj);
        }

        public void StoreValue(IntPtr uObj, sbyte value)
        {
            UnmanagedBuffer.UUInt8Object_SetSByte(uObj, value);
        }

        public string UnmanagedName()
        {
            return "UInt8";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UUInt8Object_FromSByte((sbyte)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt8Object_AsSByte(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UUInt8Object_SetSByte(uObj, (sbyte)value);
        }

        public string UnmanagedName(Type t)
        {
            return "UInt8";
        }
    }

    public class ShortSerializer : IDataSerializer<Int16>
    {
        public IntPtr UObjectNew(short value)
        {
            return UnmanagedBuffer.UInt16Object_FromShort(value);
        }

        public short LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UInt16Object_AsShort(uObj);
        }

        public void StoreValue(IntPtr uObj, short value)
        {
            UnmanagedBuffer.UInt16Object_SetShort(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Int16";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt16Object_FromShort((short)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UInt16Object_AsShort(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt16Object_SetShort(uObj, (short)value);
        }

        public string UnmanagedName(Type t)
        {
            return "Int16";
        }
    }

    public class UShortSerialier : IDataSerializer<UInt16>
    {
        public IntPtr UObjectNew(ushort value)
        {
            return UnmanagedBuffer.UUInt16Object_FromUShort(value);
        }

        public ushort LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt16Object_AsUShort(uObj);
        }

        public void StoreValue(IntPtr uObj, ushort value)
        {
            UnmanagedBuffer.UUInt16Object_SetUShort(uObj, value);
        }

        public string UnmanagedName()
        {
            return "UInt16";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UUInt16Object_FromUShort((ushort)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt16Object_AsUShort(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UUInt16Object_SetUShort(uObj, (ushort)value);
        }

        public string UnmanagedName(Type t)
        {
            return "UInt16";
        }
    }

    public class LongSerializer : IDataSerializer<Int64>
    {
        public IntPtr UObjectNew(long value)
        {
            return UnmanagedBuffer.UInt64Object_FromLong(value);
        }

        public long LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UInt64Object_AsLong(uObj);
        }

        public void StoreValue(IntPtr uObj, long value)
        {
            UnmanagedBuffer.UInt64Object_SetLong(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Int64";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UInt64Object_FromLong((long)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UInt64Object_AsLong(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UInt64Object_SetLong(uObj, (long)value);
        }

        public string UnmanagedName(Type t)
        {
            return "Int64";
        }
    }

    public class ULongSerializer : IDataSerializer<UInt64>
    {
        public IntPtr UObjectNew(ulong value)
        {
            return UnmanagedBuffer.UUInt64Object_FromULong(value);
        }

        public ulong LoadValue(IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt64Object_AsULong(uObj);
        }

        public void StoreValue(IntPtr uObj, ulong value)
        {
            UnmanagedBuffer.UUInt64Object_SetULong(uObj, value);
        }

        public string UnmanagedName()
        {
            return "UInt64";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            return UnmanagedBuffer.UUInt64Object_FromULong((ulong)value);
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return UnmanagedBuffer.UUInt64Object_AsULong(uObj);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UUInt64Object_SetULong(uObj, (ulong)value);
        }

        public string UnmanagedName(Type t)
        {
            return "UInt64";
        }
    }

    public class StringSerializer : IDataSerializer<String>
    {
        public IntPtr UObjectNew(string value)
        {
            IntPtr uStr = Marshal.StringToHGlobalUni(value);
            IntPtr uObj = UnmanagedBuffer.UUnicodeObject_FromUnicode(uStr);
            Marshal.FreeHGlobal(uStr);

            return uObj;
        }

        public String LoadValue(IntPtr uObj)
        {
            IntPtr str = IntPtr.Zero;
            UnmanagedBuffer.UUnicodeObject_AsUnicode(uObj, ref str);

            return Marshal.PtrToStringUni(str);
        }

        public void StoreValue(IntPtr uObj, string value)
        {
            UnmanagedBuffer.UUnicodeObject_SetUnicode(uObj, value);
        }

        public string UnmanagedName()
        {
            return "Unicode";
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            IntPtr uStr = Marshal.StringToHGlobalUni(Convert.ToString(value));
            IntPtr uObj = UnmanagedBuffer.UUnicodeObject_FromUnicode(uStr);
            Marshal.FreeHGlobal(uStr);

            return uObj;
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            IntPtr str = IntPtr.Zero;
            UnmanagedBuffer.UUnicodeObject_AsUnicode(uObj, ref str);

            return Marshal.PtrToStringUni(str);
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            UnmanagedBuffer.UUnicodeObject_SetUnicode(uObj, Convert.ToString(value));
        }

        public string UnmanagedName(Type t)
        {
            return "Unicode";
        }
    }

    public class EnumSerializer<T> : IDataSerializer<T>
    {
        public IntPtr UObjectNew(T value)
        {
            throw new NotImplementedException();
        }

        public T LoadValue(IntPtr uObj)
        {
            T val = (T)Enum.Parse(typeof(T), DataSerializeUtils.LoadValue<string>(uObj));
            return val;
        }

        public void StoreValue(IntPtr uObj, T value)
        {
            DataSerializeUtils.StoreValue<string>(uObj, value.ToString());
        }

        public string UnmanagedName()
        {
            return typeof(T).Name;
        }

        public IntPtr UObjectNew(Type t, object value)
        {
            throw new NotImplementedException();
        }

        public object LoadValue(Type t, IntPtr uObj)
        {
            return Enum.Parse(t, DataSerializeUtils.LoadValue<string>(uObj));
        }

        public void StoreValue(Type t, IntPtr uObj, object value)
        {
            DataSerializeUtils.StoreValue<string>(uObj, value.ToString());
        }

        public string UnmanagedName(Type t)
        {
            return t.Name;
        }
    }

    public class ArraySerializer
    {
        public static object LoadValue(Type t, IntPtr uObj)
        {
            Type vt = t.GetElementType();

            return null;
        }
    }

    public class GenericListSerializer<T>
    {
    }

    /// <summary>
    /// List转换器  注意 性能低下  尽量不要用
    /// </summary>
    public class ListSerializer
    {
        public static IntPtr UObjectNew(Type t, object value)
        {
            throw new NotImplementedException();
        }

        public static object LoadValue(Type t, IntPtr uObj)
        {
            Type vt = t.GetGenericArguments()[0];
            if (vt == null)
                return null;

            int count = UnmanagedBuffer.UObjectList_Count(uObj);

            object list = Activator.CreateInstance(t, count);
            MethodInfo add = t.GetMethod("Add");

            for(int i = 0; i != count; ++i)
            {
                IntPtr uElement = UnmanagedBuffer.UObjectList_GetItem(uObj, i);
                object element = DataSerializeUtils.LoadValue(vt, uElement);
                add.Invoke(list, new object[] { element });
                UnmanagedBuffer.UObject_GC_Delete(uElement);
            }

            return list;
        }

        public static void StoreValue(Type t, IntPtr uObj, object value)
        {
            throw new NotImplementedException();
        }

        public static string UnmanagedName(Type t)
        {
            Type vt = t.GetGenericArguments()[0];
            if (vt == null)
                return null;

            return "List<" + DataSerializeUtils.UnmanagedName(vt) + ">";
        }

    }

    public class DictSerializer
    {
        public static IntPtr UObjectNew(Type t, object value)
        {
            throw new NotImplementedException();
        }

        public static object LoadValue(Type t, IntPtr uObj)
        {
            throw new NotImplementedException();
        }

        public static void StoreValue(Type t, IntPtr uObj, object value)
        {
            throw new NotImplementedException();
        }

        public static string UnmanagedName(Type t)
        {
            Type keyt = t.GetGenericArguments()[0];
            Type valuet = t.GetGenericArguments()[1];

            return "Dict<" + DataSerializeUtils.UnmanagedName(keyt) + "," + DataSerializeUtils.UnmanagedName(valuet) + ">";
        }
    }
}
