#pragma once

#include "../Common/Exceptions.hpp"

#include "UObject.hpp"
#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	class UInt8Object : public UObject
	{
	public:
		using IntType = Int8;

		UInt8Object(UType* uType);

		~UInt8Object();

		Int8 GetVal() const
		{
			return m_Val;
		}

		void SetVal(Int8 val)
		{
			m_Val = val;
		}

	private:
		Int8 m_Val;
	};

	class UUInt8Object : public UObject
	{
	public:
		using IntType = UInt8;

		UUInt8Object(UType* uType);

		~UUInt8Object();

		UInt8 GetVal() const
		{
			return m_Val;
		}

		void SetVal(UInt8 val)
		{
			m_Val = val;
		}

	private:
		UInt8 m_Val;
	};

	class UInt16Object : public UObject
	{
	public:
		using IntType = Int16;

		UInt16Object(UType* uType);

		~UInt16Object();

		Int16 GetVal() const
		{
			return m_Val;
		}

		void SetVal(Int16 val)
		{
			m_Val = val;
		}

	private:
		Int16 m_Val;
	};

	class UUInt16Object : public UObject
	{
	public:
		using IntType = UInt16;

		UUInt16Object(UType* uType);

		~UUInt16Object();

		UInt16 GetVal() const
		{
			return m_Val;
		}

		void SetVal(UInt16 val)
		{
			m_Val = val;
		}

	private:
		UInt16 m_Val;
	};

	class UInt32Object : public UObject
	{
	public:
		using IntType = Int32;

		UInt32Object(UType* uType);

		~UInt32Object();

		Int32 GetVal() const
		{
			return m_Val;
		}

		void SetVal(Int32 val)
		{
			m_Val = val;
		}

	private:
		Int32 m_Val;
	};

	class UUInt32Object : public UObject
	{
	public:
		using IntType = UInt32;

		UUInt32Object(UType* uType);

		~UUInt32Object();

		UInt32 GetVal() const
		{
			return m_Val;
		}

		void SetVal(UInt32 val)
		{
			m_Val = val;
		}

	private:
		UInt32 m_Val;
	};

	class UInt64Object : public UObject
	{
	public:
		using IntType = Int64;

		UInt64Object(UType* uType);

		~UInt64Object();

		Int64 GetVal() const
		{
			return m_Val;
		}

		void SetVal(Int64 val)
		{
			m_Val = val;
		}

	private:
		Int64 m_Val;
	};

	class UUInt64Object : public UObject
	{
	public:
		using IntType = UInt64;

		UUInt64Object(UType* uType);

		~UUInt64Object();

		UInt64 GetVal() const
		{
			return m_Val;
		}

		void SetVal(UInt64 val)
		{
			m_Val = val;
		}

	private:
		UInt64 m_Val;
	};

}
