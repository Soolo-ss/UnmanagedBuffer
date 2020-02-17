#pragma once

//----include

//common include
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdint.h>

//windwos include 
#if defined(__WIN32__) || defined(_WIN32) || defined(_WINDOWS) || defined(WIN) || defined(_WIN64) || defined(__WIN64__)	
#define NOMINMAX
#include <windows.h>
#else
//linux include

#endif

//----platform
#define PLATFORM_WIN			0
#define PLATFORM_ANDROID		1
#define PLATFORM_UNIX			2
#define PLATFORM_IOS			3
#define PLATFORM_MAC			4


#ifdef _WIN32
   //define something for Windows (32-bit and 64-bit, this part is common)
#define PLATFORM PLATFORM_WIN
#ifdef _WIN64
   //define something for Windows (64-bit only)
#else
   //define something for Windows (32-bit only)
#endif
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
#define PLATFORM PLATFORM_IOS
	 // iOS Simulator
#elif TARGET_OS_IPHONE
#define PLATFORM PLATFORM_IOS
	// iOS device
#elif TARGET_OS_MAC
#define PLATFORM PLATFORM_MAC
	// Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
#define PLATFORM PLATFORM_UNIX
	// linux
#elif __unix__ // all unices not caught above
	// Unix
#define PLATFORM PLATFORM_UNIX

#elif defined(_POSIX_VERSION)
	// POSIX
#define PLATFORM PLATFORM_UNIX
#else
#   error "Unknown compiler"
#endif

#if PLATFORM == PLATFORM_WIN
#define EXPORT extern "C" __declspec(dllexport)
#else
#define EXPORT extern "C" __attribute ((visibility("default")))
#endif

#define IS_USE_POOL 1
