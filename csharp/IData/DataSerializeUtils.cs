using System;
using System.Collections.Generic;
using System.Text;

namespace SunnyMobile.UnmanagedBuffer
{
    /// <summary>
    /// 原生类型转换器
    /// 将Native的数据转化为C#的类型
    /// 支持类型包括：
    /// Init内所有声明的类型
    /// List<> , Dict<,> -> List Dict 内的模版类型必须是基础类型或者在types.xml中事先声明
    /// </summary>
    public static class DataSerializeUtils
    {
        static DataSerializeUtils()
        {
            Init();
        }

        private static void Init()
        {
            m_Serializes.Add(typeof(char), new CharSerializer());
            m_Serializes.Add(typeof(bool), new BoolSerializer());
            m_Serializes.Add(typeof(int), new IntSerializer());
            m_Serializes.Add(typeof(uint), new UIntSerializer());
            m_Serializes.Add(typeof(short), new ShortSerializer());
            m_Serializes.Add(typeof(ushort), new UShortSerialier());
            m_Serializes.Add(typeof(long), new LongSerializer());
            m_Serializes.Add(typeof(ulong), new ULongSerializer());
            m_Serializes.Add(typeof(sbyte), new SByteSerializer());
            m_Serializes.Add(typeof(byte), new ByteSerializer());
            m_Serializes.Add(typeof(float), new FloatSerializer());
            m_Serializes.Add(typeof(double), new DoubleSerializer());
            m_Serializes.Add(typeof(string), new StringSerializer());
            m_Serializes.Add(typeof(SunnyFramework.SValue), new SValueSerializer());
            m_Serializes.Add(typeof(SunnyFramework.AssetType), new EnumSerializer<SunnyFramework.AssetType>());
            m_Serializes.Add(typeof(SunnyFramework.GUITweenType), new EnumSerializer<SunnyFramework.GUITweenType>());
            m_Serializes.Add(typeof(SunnyGame.ApplicationType), new EnumSerializer<SunnyGame.ApplicationType>());
            m_Serializes.Add(typeof(SunnyFramework.UITweenerStyle), new EnumSerializer<SunnyFramework.UITweenerStyle>());

            //UserDefine Begin
			m_Serializes.Add(typeof(global), new global_Serializer());
			m_Serializes.Add(typeof(jump), new jump_Serializer());
			m_Serializes.Add(typeof(map), new map_Serializer());
			m_Serializes.Add(typeof(race), new race_Serializer());
			m_Serializes.Add(typeof(randname), new randname_Serializer());
			m_Serializes.Add(typeof(role), new role_Serializer());
			m_Serializes.Add(typeof(role_level), new role_level_Serializer());
			m_Serializes.Add(typeof(school), new school_Serializer());
			m_Serializes.Add(typeof(BootData), new BootData_Serializer());
			m_Serializes.Add(typeof(BootConfig), new BootConfig_Serializer());
			m_Serializes.Add(typeof(AssetInfo), new AssetInfo_Serializer());
			m_Serializes.Add(typeof(AssetDependencies), new AssetDependencies_Serializer());
			m_Serializes.Add(typeof(LualibConfig), new LualibConfig_Serializer());
			m_Serializes.Add(typeof(BaseLangConfig), new BaseLangConfig_Serializer());
			m_Serializes.Add(typeof(ParticleConfig), new ParticleConfig_Serializer());
			m_Serializes.Add(typeof(TweenData), new TweenData_Serializer());
			m_Serializes.Add(typeof(GUITweenConfig), new GUITweenConfig_Serializer());
			m_Serializes.Add(typeof(CameraConfig), new CameraConfig_Serializer());
			m_Serializes.Add(typeof(SoundsConfig), new SoundsConfig_Serializer());
			m_Serializes.Add(typeof(FontConfig), new FontConfig_Serializer());
			m_Serializes.Add(typeof(SpriteAniConfig), new SpriteAniConfig_Serializer());
			m_Serializes.Add(typeof(BasicConfig), new BasicConfig_Serializer());
            //UserDefine End
        }

        public static IntPtr UObjectNew<T>(T value)
        {
            var t = typeof(T);

            if (m_Serializes.ContainsKey(t))
                return ((IDataSerializer<T>)(m_Serializes[t])).UObjectNew(value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return ListSerializer.UObjectNew(t, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return DictSerializer.UObjectNew(t, value);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }
        
        public static IntPtr UObjectNew(Type t, object value)
        {
            if (m_Serializes.ContainsKey(t))
                return (m_Serializes[t]).UObjectNew(t, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return ListSerializer.UObjectNew(t, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return DictSerializer.UObjectNew(t, value);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static T LoadValue<T>(IntPtr uObj)
        {
            if (uObj == IntPtr.Zero)
                return default(T);

            var t = typeof(T);

            if (m_Serializes.ContainsKey(t))
                return ((IDataSerializer<T>)(m_Serializes[t])).LoadValue(uObj);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return (T)ListSerializer.LoadValue(t, uObj);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return (T)DictSerializer.LoadValue(t, uObj);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static object LoadValue(Type t, IntPtr uObj)
        {
            if (uObj == IntPtr.Zero)
                return null;

            if (m_Serializes.ContainsKey(t))
                return (m_Serializes[t]).LoadValue(t, uObj);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return ListSerializer.LoadValue(t, uObj);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return DictSerializer.LoadValue(t, uObj);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static T LoadFieldValue<T>(IntPtr uObj, string field)
        {
            if (uObj == IntPtr.Zero)
                return default(T);

            IntPtr uField = UnmanagedBuffer.UClassObject_GetField(uObj, field);

            if (uField == IntPtr.Zero)
                return default(T);

            T val = DataSerializeUtils.LoadValue<T>(uField);

            UnmanagedBuffer.UObject_GC_Delete(uField);

            return val;
        }

        public static void StoreFieldValue<T>(IntPtr uObj, T value, string field)
        {
            if (uObj == IntPtr.Zero)
                return;

            IntPtr uField = UnmanagedBuffer.UClassObject_GetField(uObj, field);

            if (uField == IntPtr.Zero)
                return;

            StoreValue<T>(uField, value);
        }

        public static void StoreValue<T>(IntPtr uObj, T value)
        {
            if (uObj == IntPtr.Zero)
                return;

            var t = typeof(T);

            if (m_Serializes.ContainsKey(t))
                ((IDataSerializer<T>)(m_Serializes[t])).StoreValue(uObj, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                ListSerializer.StoreValue(t, uObj, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                DictSerializer.StoreValue(t, uObj, value);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static void StoreValue(Type t, IntPtr uObj, object value)
        {
            if (uObj == IntPtr.Zero)
                return;

            if (m_Serializes.ContainsKey(t))
                m_Serializes[t].StoreValue(t, uObj, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                ListSerializer.StoreValue(t, uObj, value);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                DictSerializer.StoreValue(t, uObj, value);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static string UnmanagedName<T>()
        {
            var t = typeof(T);

            if (m_Serializes.ContainsKey(t))
                return ((IDataSerializer<T>)(m_Serializes[t])).UnmanagedName();
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return ListSerializer.UnmanagedName(t);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return DictSerializer.UnmanagedName(t);
            else
                throw new Exception("Un Supported IDataSerialize Type -> " + t.ToString());
        }

        public static string UnmanagedName(Type t)
        {
            if (m_Serializes.ContainsKey(t))
                return m_Serializes[t].UnmanagedName(t);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(List<>))
                return ListSerializer.UnmanagedName(t);
            else if (t.IsGenericType && t.GetGenericTypeDefinition() == typeof(Dictionary<,>))
                return DictSerializer.UnmanagedName(t);
            else
                throw new Exception("Un Supported IDataSerializer Type ->" + t.ToString());
        }

        public static string GetUObjectTypeName(IntPtr uObj)
        {
            string uTypeName = string.Empty;

            IntPtr uTypeNameObj = UnmanagedBuffer.UObject_GetUTypeName(uObj);

            uTypeName = LoadValue<string>(uTypeNameObj);

            UnmanagedBuffer.UObject_GC_Delete(uTypeNameObj);

            return uTypeName;
        }

        private static Dictionary<Type, IDataSerializerBase> m_Serializes = new Dictionary<Type, IDataSerializerBase>();
    }
}
