using System;
using System.Collections.Generic;
using System.Text;

namespace UnmanagedBuffer
{
    public class UObject
    {
        public UObject()
        {
            this.m_Address = IntPtr.Zero;
        }

        public UObject(IntPtr address)
        {
            this.m_Address = address;
        }

        public bool IsAllocated
        {
            get
            {
                return m_Address != IntPtr.Zero;
            }
        }

        public IntPtr Address
        {
            get
            {
                return m_Address;
            }
        }

        private IntPtr m_Address;
    }
}
