简介：
    一个提供通用接口的C#托管内存与C++堆内存互相映射的框架。只需要定义一个Types.xml文件,就可以在C#中存储一个对应的C++实例。

依赖:
    rapidxml
    libiconv (unix)

使用方法：
    1 生成UnmanagedBuffer的DLL或者SO库， Windows下直接Build Andriod或者IOS 需要通过各自的编译工具进行编译。Andriod下推荐NDK

    2 见ROOT目录下的Types.xml 根据Types.xml中的注释定义需要在C++和C#之间互通的结构。 然后通过Tools下的工具生成C#代码。
    将生成的C#代码连同UnmanagedBufferCS下的文件一同拷入你的项目。

    3 C#代码中的UnmangedBuffer.cs会引用UnmanagedBuffer的C++动态库,请设置好对应的路径

如何在代码中使用UnmanagedBuffer：

    1 DataSerializeUtils.cs中的接口是使用UnmanagedBuffer的关键。
        //指定类型信息，创建一个C++实例
        //UnmanagedBuffer会在C++端创建一份这个实例的拷贝并且返回这个实例的IntPtr
        //C++中使用引用计数管理内存
        //新创建的UObject的默认引用计数为1
        IntPtr UObjectNew<T>(T val)
        IntPtr UObjectNew(Type t, object value)

        //指定一个指针和T的类型信息, 返回一个C#实例
        T LoadValue<T>(IntPtr uObj)
        object LoadValue(Type t, IntPtr uObj)

        //提供C++实例的指针、C#实例、类型信息， 将C#实例拷贝给C++实例
        void StoreValue<T>(IntPtr uObj, T value)
        void StoreValue(Type t, IntPtr uObj, object value)

        //给定一个复合类型的指针，和变量域名，返回实例的一个域
        T LoadFieldValue<T>(IntPtr uObj, string field)
        void StoreFieldValue<T>(IntPtr uObj, T value, string field)

        这些接口是对UnmanagedBuffer.cs中的底层接口的一层封装。避免创建UObject的时候过于繁琐。

        对于所有创建的UObject， 每当其离开作用域，都需要调用UnmanagedBuffer.UObject_GC_Delete(IntPtr uObj)进行回收。

    2 目前没有提供C#端对C++创建的IntPtr的管理，我认为对自己创建的C++内存，必须在C#端有一个清晰的管理。不能依赖C++自己去释放。所以目前的内存管理是基于引用计数的垃圾收集机制
      C++中的所有创建或者使用了UObject的接口都会对UObject的引用计数进行+1 例如UObjectList_Append，会对加入List的UObject的引用计数+1 所以在C#端必须做好引用计数的加减。



未完待续。。。。。。