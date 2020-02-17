#pragma once

#include "UObject.hpp"

namespace UnmanagedBuffer
{
	class UStringObject : public UObject
	{
	public:
		UStringObject(UType* uType)
			: UObject(uType)
		{

		}

		~UStringObject()
		{
			m_Val.clear();
		}

		std::string GetVal() const
		{
			return m_Val;
		}

		void SetVal(std::string val)
		{
			m_Val = val;
		}

		const char* GetValStr() const
		{
			return m_Val.c_str();
		}

	private:
		std::string m_Val;
	};

	class UWStringObject : public UObject
	{
	public:
		UWStringObject(UType* uType)
			: UObject(uType)
		{

		}

		~UWStringObject()
		{
			m_Val.clear();
		}

		std::u16string GetVal() const
		{
			return m_Val;
		}

		void SetVal(std::u16string val)
		{
			m_Val = val;
		}

		const char16_t* GetValStr() const
		{
			return m_Val.c_str();
		}

	private:
		std::u16string m_Val;
	};
}
