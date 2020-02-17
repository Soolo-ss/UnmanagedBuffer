#pragma once

#include "./Common.hpp"

template <typename T>
class TransferTraits
{
public:
	template <typename TransferFunction>
	static void Transfer(T &data, TransferFunction &transfer)
	{
		data.Transfer(transfer);
	}
};

template <typename T>
class TransferTraitsBasic
{
public:
	template <typename TransferFunction>
	static void Transfer(T &data, TransferFunction &transfer)
	{
		transfer.TransferBasic(data);
	}
};

template <>
class TransferTraits<UINT8> : TransferTraitsBasic<UINT8>
{
};

template <>
class TransferTraits<UINT16> : TransferTraitsBasic<UINT16>
{
};

template <>
class TransferTraits<UINT32> : TransferTraitsBasic<UINT32>
{
};

template <>
class TransferTraits<UINT64> : TransferTraitsBasic<UINT64>
{
};

template <>
class TransferTraits<INT8> : TransferTraitsBasic<INT8>
{
};

template <>
class TransferTraits<INT16> : TransferTraitsBasic<INT16>
{
};

template <>
class TransferTraits<INT32> : TransferTraitsBasic<INT32>
{
};

template <>
class TransferTraits<INT64> : TransferTraitsBasic<INT64>
{
};

template <typename T>
class TransferTraitsString
{
public:
	template <typename TransferFunction>
	static void Transfer(T &data, TransferFunction &transfer)
	{
		transfer.TransferString(data);
	}
};

template <>
class TransferTraits<std::string> : TransferTraitsString<std::string>
{
};

template <typename T>
class TransferTraitsArray
{
public:
	template <typename TransferFunction>
	static void Transfer(T &data, TransferFunction &transfer)
	{
		transfer.TransferArray(data);
	}
};

template <typename ArrayElement>
class TransferTraits<std::vector<ArrayElement>> : TransferTraitsArray<std::vector<ArrayElement>>
{
};

template <typename T>
class TransferTraitsMap
{
public:
	template <typename TransferFunction>
	static void Transfer(T &data, TransferFunction &transfer)
	{
		transfer.TransferMap(data);
	}
};

template <typename Key, typename Value>
class TransferTraits<std::map<Key, Value>> : TransferTraitsMap<std::map<Key, Value>>
{
};
