#pragma once

#include "Platform.hpp"
#include "ErrorCode.hpp"
#include "Exceptions.hpp"

using std::map;
using std::set;
using std::vector;
using std::string;
using std::function;
using std::shared_ptr;
using std::unordered_map;
using std::queue;

using Int8 = int8_t;
using UInt8 = uint8_t;
using Int16 = int16_t;
using UInt16 = uint16_t;
using Int32 = int32_t;
using UInt32 = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;
//Windows有一个BOOL的定义
using Boolean = bool;
using Float = float;
using Double = double;

using MessageCallback = void(*)(void*);
using NetworkDispatcher = void(*)(void*);
