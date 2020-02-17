#pragma once

#include "Common.hpp"

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#if PLATFORM != PLATFORM_WIN
#include "iconv.h"
#endif

class StringUtils
{
public:
	//// trim from start (in place)
	static inline void ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch);
		}));
	}

	// trim from end (in place)
	static inline void rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string &s) {
		ltrim(s);
		rtrim(s);
	}

	static inline std::vector<std::string> split(const std::string& s, char seperator)
	{
		std::vector<std::string> output;

		std::string::size_type prev_pos = 0, pos = 0;

		while ((pos = s.find(seperator, pos)) != std::string::npos)
		{
			std::string substring(s.substr(prev_pos, pos - prev_pos));

			output.push_back(substring);

			prev_pos = ++pos;
		}

		output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

		return output;
	}

	static inline std::u16string gb2312_to_unicode(std::string s)
	{
#if PLATFORM == PLATFORM_WIN
		char* in = const_cast<char*>(s.data());
		int outsize = MultiByteToWideChar(CP_ACP, 0, in, -1, NULL, 0);

		if (outsize <= 0)
			return std::u16string();

		memset(buffer, 0, sizeof(buffer));

		MultiByteToWideChar(CP_ACP, 0, in, -1, (wchar_t*)buffer, outsize);

		return std::u16string(buffer, outsize - 1);
#else
		if (!gbk_ucs_cd)
			gbk_ucs_cd = iconv_open("UCS-2LE", "GB2312");

		size_t bufSize = sizeof(buffer);

		char* in = const_cast<char*>(s.c_str());
		size_t ins = strlen(in);
		memset(buffer, 0, bufSize);
		char* out = (char*)&buffer[0];
		size_t outs = bufSize;

		size_t bytes = iconv(gbk_ucs_cd, &in, &ins, &out, &outs);

		if (bytes == -1)
			return std::u16string();

		size_t wsize = std::char_traits<char16_t>::length(buffer);

		return std::u16string((char16_t*)buffer, wsize);
#endif
	}

	static inline std::u16string utf8_to_ucs(std::string s)
	{
#if PLATFORM == PLATFORM_WIN
		char* in = const_cast<char*>(s.data());
		int outsize = MultiByteToWideChar(CP_UTF8, 0, in, -1, NULL, 0);

		if (outsize <= 0)
			return std::u16string();

		memset(buffer, 0, sizeof(buffer));

		MultiByteToWideChar(CP_UTF8, 0, in, -1, (wchar_t*)buffer, outsize);

		return std::u16string(buffer, outsize - 1);
#else
		if (!utf8_ucs_cd)
			utf8_ucs_cd = iconv_open("UCS-2LE", "UTF-8");

		size_t bufSize = sizeof(buffer);

		char* in = const_cast<char*>(s.c_str());
		size_t ins = strlen(in);
		memset(buffer, 0, bufSize);
		char* out = (char*)&buffer[0];
		size_t outs = bufSize;

		size_t bytes = iconv(utf8_ucs_cd, &in, &ins, &out, &outs);

		if (bytes == -1)
			return std::u16string();

		size_t wsize = std::char_traits<char16_t>::length(buffer);

		return std::u16string((char16_t*)buffer, wsize);
#endif
	}

private:
#if PLATFORM != PLATFORM_WIN
	static iconv_t gbk_ucs_cd;
	static iconv_t utf8_ucs_cd;
#endif
	static char16_t buffer[4096];
};