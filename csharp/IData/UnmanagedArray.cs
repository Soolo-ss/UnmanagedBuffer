using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Collections;

namespace SunnyMobile.UnmanagedBuffer
{
    public class UnmanagedArray : UnmanagedObject
    {
        private UnmanagedArray()
        {

        }

        public static UnmanagedArray Create()
        {
            UnmanagedArray uArray = new UnmanagedArray();
            IntPtr uAddr = UnmanagedBuffer.UObject_GC_New("List");
            uArray.Address = uAddr;

            return uArray;
        }

        public static UnmanagedArray Create(IntPtr uAddr)
        {
            if (uAddr == IntPtr.Zero)
                throw new Exception("create unamanged array by zero intptr");

            UnmanagedArray uArray = new UnmanagedArray();
            uArray.Address = uAddr;

            return uArray;  
        }

        public static UnmanagedArray Create(string elementType)
        {
            int error = UnmanagedBuffer.UTypeList_New(elementType);
            if (error != 0)
                throw new Exception(RapidDataPool.RapidDataPool.ErrorCode.GetErrorCodeDescription(error));

            IntPtr uAddr = UnmanagedBuffer.UObject_GC_New("List<" + elementType + ">");
            UnmanagedArray uArray = new UnmanagedArray();
            uArray.Address = uAddr;

            return uArray;
        }

        public static void Delete(UnmanagedArray uArray)
        {
            if (!uArray.IsAllocated)
                throw new Exception("try to dellocated a empty unmanaged array");

            UnmanagedBuffer.UObject_GC_Delete(uArray.Address);
        }

        public void Add<T>(T value)
        {
            if (value == null)
                return;

            if (!IsAllocated)
                throw new Exception("Try To Add UnAllocated UnmanagedArray");

            IntPtr uValue = DataSerializeUtils.UObjectNew<T>(value);
            if (uValue == IntPtr.Zero)
                return;

            UnmanagedBuffer.UObjectList_Append(this.Address, uValue);

            UnmanagedBuffer.UObject_GC_Delete(uValue);
        }

        public void Add(object value)
        {
            if (value == null)
                return;

            if (!IsAllocated)
                throw new Exception("Try to Add UnAllocated UnmanagedArray");

            IntPtr uValue = DataSerializeUtils.UObjectNew(value.GetType(), value);
            if (uValue == IntPtr.Zero)
                return;

            UnmanagedBuffer.UObjectList_Append(this.Address, uValue);

            UnmanagedBuffer.UObject_GC_Delete(uValue);
        }

        public void Clear()
        {
            if (!IsAllocated)
                throw new Exception("Try To Clear UnAllocated UnmanagedArray");

            UnmanagedBuffer.UObjectList_Clear(this.Address);
        }

        public T Get<T>(int index)
        {
            if (!IsAllocated)
                throw new Exception("Try To Index UnAllocated Unmanaged Array");

            if (index < 0 || index >= Length)
                throw new IndexOutOfRangeException();

            IntPtr uValue = UnmanagedBuffer.UObjectList_GetItem(this.Address, index);
            T val = DataSerializeUtils.LoadValue<T>(uValue);

            UnmanagedBuffer.UObject_GC_Delete(uValue);

            return val;
        }

        public void Set<T>(T value, int index)
        {
            if (!IsAllocated)
                throw new Exception("Try To Set UnAllocated Unmanaged Array");

            if (index < 0 || index >= Length)
                throw new IndexOutOfRangeException();

            IntPtr uValue = DataSerializeUtils.UObjectNew<T>(value);

            UnmanagedBuffer.UObjectList_SetItem(this.Address, uValue, index);

            UnmanagedBuffer.UObject_GC_Delete(uValue);
        }

        /*
        public IEnumerator<T> GetEnumerator()
        {
            return new Enumerator(this, 0);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return new Enumerator(this, 0);
        }
        */

        /*
        [StructLayout(LayoutKind.Sequential)]
        public struct Enumerator : IEnumerator<T>
        {
            UnmanagedArray<T> m_Array;
            int m_Index;

            internal Enumerator(UnmanagedArray<T> array, int index)
            {
                m_Array = array;
                m_Index = index;
            }

            public bool MoveNext()
            {
                if (m_Index >= 0 && m_Index < (m_Array.Length - 1))
                {
                    m_Index += 1;
                    return true;
                }

                return false;
            }

            public void Reset()
            {
                m_Index = 0;
            }

            public T Current
            {
                get
                {
                    return m_Array[m_Index];
                }
            }

            object IEnumerator.Current
            {
                get
                {
                    return m_Array[m_Index];
                }
            }

            public void Dispose()
            {
            }
        }
        */

        public int Length
        {
            get
            {
                return UnmanagedBuffer.UObjectList_Count(this.Address);
            }
        }
    }
}
