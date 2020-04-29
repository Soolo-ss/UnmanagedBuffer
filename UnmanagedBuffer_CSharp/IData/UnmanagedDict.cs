using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Collections;
using System.Collections.Generic;

namespace UnmanagedBuffer
{

    /// <summary>
    /// 原生字典
    /// Key Value 可容纳DataSerializeUtils内任意类型的Pair
    /// </summary>
    public class UnmanagedDict : UnmanagedObject, IEnumerable
    {
        private UnmanagedDict()
        {

        }

        public static UnmanagedDict Create()
        {
            UnmanagedDict uDict = new UnmanagedDict();
            IntPtr uAddr = UnmanagedBuffer.UObject_GC_New("Dict");
            uDict.Address = uAddr;

            return uDict;
        }

        public static UnmanagedDict Create(string keyType, string valueType)
        {
            int error = UnmanagedBuffer.UTypeDict_New(keyType, valueType);
            if (error != 0)
                throw new Exception(RapidDataPool.RapidDataPool.ErrorCode.GetErrorCodeDescription(error));

            UnmanagedDict uDict = new UnmanagedDict();
            IntPtr uAddr = UnmanagedBuffer.UObject_GC_New("Dict<" + keyType + "," + valueType + ">");
            if (uAddr == IntPtr.Zero)
                throw new Exception(RapidDataPool.RapidDataPool.ErrorCode.GetErrorCodeDescription(10));

            uDict.Address = uAddr;

            return uDict;
        }

        public static UnmanagedDict Create(IntPtr uAddr)
        {
            UnmanagedDict uDict = new UnmanagedDict();
            uDict.Address = uAddr;
            return uDict;
        }

        public static void Delete(UnmanagedDict uDict)
        {
            if (!uDict.IsAllocated)
                throw new Exception("try to dellocate a empty dict");

            UnmanagedBuffer.UObject_GC_Delete(uDict.Address);
        }

        public bool ContainsKey<Key>(Key key)
        {
            IntPtr uKey = DataSerializeUtils.UObjectNew<Key>(key);

            bool contains = UnmanagedBuffer.UObjectDict_Contains(this.Address, uKey);

            UnmanagedBuffer.UObject_GC_Delete(uKey);

            return contains;
        }

        public void Add<Key, Value>(Key key, Value value)
        {
            IntPtr uKey = DataSerializeUtils.UObjectNew<Key>(key);
            IntPtr uValue = DataSerializeUtils.UObjectNew<Value>(value);

            UnmanagedBuffer.UObjectDict_SetItem(this.Address, uKey, uValue);

            UnmanagedBuffer.UObject_GC_Delete(uKey);
            UnmanagedBuffer.UObject_GC_Delete(uValue);
        }

        public bool Remove<Key>(Key key)
        {
            IntPtr uKey = DataSerializeUtils.UObjectNew<Key>(key);

            bool removed = UnmanagedBuffer.UObjectDict_RemoveItem(this.Address, uKey);
            UnmanagedBuffer.UObject_GC_Delete(uKey);

            return removed;
        }

        public bool TryGetValue<Key, Value>(Key key, out Value value)
        {
            IntPtr uKey = DataSerializeUtils.UObjectNew<Key>(key);

            if (uKey == IntPtr.Zero)
                throw new Exception("allocate key error");

            bool contains = UnmanagedBuffer.UObjectDict_Contains(this.Address, uKey);

            if (!contains)
            {
                value = default(Value);
                UnmanagedBuffer.UObject_GC_Delete(uKey);
                return false;
            }

            IntPtr uValue = UnmanagedBuffer.UObjectDict_GetItem(this.Address, uKey);
            value = DataSerializeUtils.LoadValue<Value>(uValue);

            UnmanagedBuffer.UObject_GC_Delete(uKey);
            UnmanagedBuffer.UObject_GC_Delete(uValue);

            return true;
        }

        /// <summary>
        /// 假设所有Key都为同一种类型
        /// </summary>
        public List<Key> AllKeys<Key>()
        {
            IntPtr uKeys = UnmanagedBuffer.UObjectDict_AllKeys(this.Address);

            List<Key> keys = DataSerializeUtils.LoadValue<List<Key>>(uKeys);

            UnmanagedBuffer.UObject_GC_Delete(uKeys);

            return keys;
        }

        public void Clear()
        {
            UnmanagedBuffer.UObjectDict_Clear(this.Address);
        }

        /*
        public Enumerator GetEnumerator()
        {
            return new Enumerator(this);
        }
        */

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public Value Get<Key, Value>(Key key)
        {
            if (!IsAllocated)
                throw new Exception("Try To Get Value From UnAllocated Dict");

            IntPtr uKey = DataSerializeUtils.UObjectNew<Key>(key);
            if (uKey == IntPtr.Zero)
                throw new Exception("allocated key error");

            if (!UnmanagedBuffer.UObjectDict_Contains(this.Address, uKey))
            {
                UnmanagedBuffer.UObject_GC_Delete(uKey);
                throw new KeyNotFoundException();
            }

            IntPtr uValue = UnmanagedBuffer.UObjectDict_GetItem(this.Address, uKey);
            if (uValue == IntPtr.Zero)
            {
                UnmanagedBuffer.UObject_GC_Delete(uKey);
                throw new Exception("get value error");
            }

            Value val = DataSerializeUtils.LoadValue<Value>(uValue);

            UnmanagedBuffer.UObject_GC_Delete(uKey);
            UnmanagedBuffer.UObject_GC_Delete(uValue);

            return val;
        }

        public void Set<Key, Value>(Key key, Value value)
        {
            if (!IsAllocated)
                throw new Exception("Try To Set Value To UnAllocated Dict");

            IntPtr uKey = IntPtr.Zero;
            IntPtr uValue = IntPtr.Zero;

            try
            {
                uKey = DataSerializeUtils.UObjectNew<Key>(key);
                uValue = DataSerializeUtils.UObjectNew<Value>(value);

                UnmanagedBuffer.UObjectDict_SetItem(this.Address, uKey, uValue);

                UnmanagedBuffer.UObject_GC_Delete(uKey);
                UnmanagedBuffer.UObject_GC_Delete(uValue);
            }
            catch (Exception e)
            {
                if (uKey != IntPtr.Zero)
                    UnmanagedBuffer.UObject_GC_Delete(uKey);

                if (uValue != IntPtr.Zero)
                    UnmanagedBuffer.UObject_GC_Delete(uValue);

                SunnyFramework.CDebug.LogError(e.ToString());
            }
        }

        public int Length
        {
            get
            {
                if (!IsAllocated)
                    return 0;

                return UnmanagedBuffer.UObjectDict_Count(this.Address);
            }
        }

        /*
        public struct Enumerator : IEnumerator<KeyValuePair<object, object>>
        {
            UnmanagedDict m_Dict;

            public KeyValuePair<object, object> Current
            {
                get
                {
                    using (UnmanagedObject uKey = UnmanagedBuffer.UDictObject_Current(m_Dict))
                    {
                        using (UnmanagedObject uValue = UnmanagedBuffer.UDictObject_GetItem(m_Dict, uKey))
                        {
                            object key = DataSerializeUtils.LoadValue(uKey);
                            Value value = DataSerializeUtils.LoadValue<Value>(uValue);

                            return new KeyValuePair<Key, Value>(key, value);
                        }
                    }
                }
            }

            object IEnumerator.Current
            {
                get
                {
                    using (UnmanagedObject uKey = UnmanagedBuffer.UDictObject_Current(m_Dict))
                    {
                        using (UnmanagedObject uValue = UnmanagedBuffer.UDictObject_GetItem(m_Dict, uKey))
                        {
                            Key key = DataSerializeUtils.LoadValue<Key>(uKey);
                            Value value = DataSerializeUtils.LoadValue<Value>(uValue);

                            return new KeyValuePair<Key, Value>(key, value);
                        }
                    }
                }
            }

            public Enumerator(UnmanagedDict dict)
            {
                m_Dict = dict;
                UnmanagedBuffer.UDictObject_BeginLoop(m_Dict);
            }

            public void Dispose()
            {
                UnmanagedBuffer.UDictObject_EndLoop(m_Dict);
            }

            public bool MoveNext()
            {
                return UnmanagedBuffer.UDictObject_MoveNext(m_Dict);
            }

            public void Reset()
            {
                throw new NotImplementedException();
            }
        }
        */
    }
}
