#include "StringUtils.hpp"


#if PLATFORM != PLATFORM_WIN
	iconv_t StringUtils::gbk_ucs_cd = nullptr;
	iconv_t StringUtils::utf8_ucs_cd = nullptr;
#endif
	char16_t StringUtils::buffer[4096];
