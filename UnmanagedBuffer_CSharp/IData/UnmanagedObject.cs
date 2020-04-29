using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace UnmanagedBuffer
{
    public class UnmanagedObject
    {
        public UnmanagedObject()
        {
            m_uObj = IntPtr.Zero;
        }

        public UnmanagedObject(IntPtr uObj)
        {
            m_uObj = uObj;
        }

        public bool IsAllocated
        {
            get
            {
                return m_uObj != IntPtr.Zero;
            }
        }

        public IntPtr Address
        {
            get
            {
                return m_uObj;
            }
            set
            {
                m_uObj = value;
            }
        }

        public IntPtr m_uObj;
    }
}
