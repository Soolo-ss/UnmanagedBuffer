using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace UnmanagedBuffer
{
    public interface IUObjectStorer<T>
    {
        void Store(IntPtr uObj, T value);
    }

    public class Int8Storer : IUObjectStorer<byte>
    {
        public void Store(IntPtr uObj, byte value)
        {
            throw new NotImplementedException();
        }
    }

    public class UInt8Storer : IUObjectStorer<sbyte>
    {
        public void Store(IntPtr uObj, sbyte value)
        {
            throw new NotImplementedException();
        }
    }

    public class Int16Storer : IUObjectStorer<Int16>
    {
        public void Store(IntPtr uObj, short value)
        {
            throw new NotImplementedException();
        }
    }

    public class UInt16Storer : IUObjectStorer<UInt16>
    {
        public void Store(IntPtr uObj, UInt16 value)
        {
            throw new NotImplementedException();
        }
    }

    public class Int32Storer : IUObjectStorer<Int32>
    {
        public void Store(IntPtr uObj, int value)
        {
            throw new NotImplementedException();
        }
    }

    public class UInt32Storer : IUObjectStorer<UInt32>
    {
        public void Store(IntPtr uObj, UInt32 value)
        {
            throw new NotImplementedException();
        }
    }

    public class CharStorer : IUObjectStorer<Char>
    {
        public void Store(IntPtr uObj, char value)
        {
            throw new NotImplementedException();
        }
    }

    public class ListStore<T> : IUObjectStorer<List<T>>
    {
        public void Store(IntPtr uObj, List<T> value)
        {
            throw new NotImplementedException();
        }
    }

    public class DictStorer<Key, Value> : IUObjectStorer<Dictionary<Key, Value>>
    {
        public void Store(IntPtr uObj, Dictionary<Key, Value> value)
        {
            throw new NotImplementedException();
        }
    }
}