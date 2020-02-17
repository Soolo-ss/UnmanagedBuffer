#pragma once

#include "../Common/Exceptions.hpp"

#include "UObject.hpp"
#include "UObjectDefine.hpp"

namespace UnmanagedBuffer
{
	class UFloatObject : public UObject
	{
	public:
		UFloatObject(UType* uType);

		~UFloatObject();

		Float GetVal() const
		{
			return m_Val;
		}

		void SetVal(Float val)
		{
			m_Val = val;
		}

	private:
		Float m_Val;
	};

}
