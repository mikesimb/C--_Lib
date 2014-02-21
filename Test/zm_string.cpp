#include "zm_string.h"


#if (defined(WIN32) || defined(WIN64))
#define UNICODE_CHARSET      "UCS-2LE"
#else
#define UNICODE_CHARSET      "UCS-4LE"
#endif

#define ASCII_CHARSET             "ASCII"
#define UTF8_CHARSET             "UTF-8"
#define ZM_PAGE                          4096

	CHAR*  ZM_Strlwr(CHAR *str)
	{
#if (defined(WIN32) || defined(WIN64))
		return strlwr(str);
#else
		std::transform(str, str + ZM_Strlen(str),
			str, ::tolower);
		return str;
#endif
	}

	CHAR*  ZM_Strupr(CHAR *str)
	{
#if (defined(WIN32) || defined(WIN64))
		return strupr(str);
#else
		std::transform(str, str + ZM_Strlen(str),
			str, ::toupper);
		return str;
#endif
	}



	std::vector<std::string>  ZM_SplitStringsA(const std::string& sSource, CHAR delim)
	{
		std::string::size_type pos1, pos2;
		std::vector<std::string> strParams;

		pos2 = 0;
		while (pos2 != std::string::npos)
		{
			pos1 = sSource.find_first_not_of(delim, pos2);
			if (pos1 == std::string::npos)
				break;
			pos2 = sSource.find_first_of(delim, pos1 + 1);
			if (pos2 == std::string::npos)
			{
				if (pos1 != sSource.size())
					strParams.push_back(sSource.substr(pos1));
				break;
			}
			strParams.push_back(sSource.substr(pos1, pos2 - pos1));
		}
		return strParams;
	}

	std::string   ZM_Strupr(std::string& str)
	{
		return ZM_Strupr(const_cast<CHAR*>(str.c_str()));
	}

	std::string   ZM_Strlwr(std::string& str)
	{
		return ZM_Strlwr(const_cast<CHAR*>(str.c_str()));
	}

	std::string  ZM_BufferToHexA(const CHAR *pBuf, UINT32 bufLen, const CHAR *pSplitter, INT32 lineLen)
	{
		static unsigned char szHex[] = "0123456789abcdef";

		char* p = (char*)pBuf;
		std::string strResult;
		for (unsigned int i = 0; i < bufLen; ++i)
		{
			strResult += szHex[(p[i] >> 4) & 0xF];
			strResult += szHex[p[i] & 0xF];
			if (pSplitter != NULL && *pSplitter && i < bufLen - 1)
			{
				strResult.append(pSplitter);
			}
			if (lineLen > 0  && (i + 1) % lineLen == 0)
			{
				strResult += "\n";
			}
		}
		return strResult;
	}

	std::string  ZM_IntToHexA(INT32 num)
	{
		CHAR szBuf[16] = {0};
		ZM_snprintf(szBuf, sizeof(szBuf), "0x%x",num);
		return szBuf;
	}

	std::string   ZM_StrTrimLeftA(std::string & str, const CHAR *trimStr )
	{
		for (std::string::iterator itr = str.begin(); itr != str.end(); ++itr)
		{
			if (strchr(trimStr,*itr) == NULL)
			{
				str.erase(str.begin(), itr);
				break;
			}
		}
		return str;
	}

	std::string   ZM_StrTrimRightA(std::string & str, const CHAR* trimStr )
	{
		for (std::string::reverse_iterator itr = str.rbegin(); itr != str.rend(); ++itr)
		{
			if (strchr(trimStr,*itr) == NULL)
			{
				str.erase(itr.base(), str.end());
				break;
			}
		}
		return str;
	}

	std::string   ZM_StrTrimA(std::string & str, const CHAR* pTrimStr)
	{
		ZM_StrTrimRightA(str, pTrimStr);
		return ZM_StrTrimLeftA(str, pTrimStr);
	}

	UINT32  ZM_Atou(const CHAR* pStr)
	{
		UINT32 result = 0;
		const CHAR * pos = pStr;
		while (*pos != 0)
		{
			if (ZM_isDigit(*pos) || *pos == '+')
			{
				UINT32 d = *pos - '0';
				result = result * 10 + d;
			}
			else
			{
				return 0;
			}
			pos ++;
		}
		return result;
	}

	UINT64  ZM_Atou64(const CHAR* pStr)
	{
		UINT64 result = 0;
		const CHAR * pos = pStr;
		while (*pos != 0 )
		{
			if (ZM_isDigit(*pos) || *pos == '+')
			{
				UINT64 d = *pos - '0';
				result = result * 10 + d;
			}
			else
			{
				return 0;
			}
			pos ++;
		}
		return result;
	}

	std::string  ZM_W2A(const WCHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(ASCII_CHARSET,UNICODE_CHARSET,(CHAR*)src,wcslen(src)*sizeof(WCHAR),szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}
	std::string  ZM_W2Local(const WCHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		ZM_IconvCovert(cpCharSet,UNICODE_CHARSET,(CHAR*)src,wcslen(src)*sizeof(WCHAR),szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	} 

	std::wstring  ZM_Local2W(const CHAR *src)
	{
		WCHAR szDesc [ZM_PAGE*10] = {0};
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UNICODE_CHARSET,cpCharSet,(CHAR*)src,strlen(src),(CHAR*)szDesc,nSize);
		std::wstring strResult = szDesc;
		return strResult;
	} 

	std::wstring  ZM_A2W(const CHAR *src)
	{
		WCHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UNICODE_CHARSET,ASCII_CHARSET,(CHAR*)src,strlen(src),(CHAR*)szDesc,nSize);
		return szDesc;
	}

	std::string  ZM_W2UTF8(const WCHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UTF8_CHARSET,UNICODE_CHARSET,(CHAR*)src,wcslen(src)*sizeof(WCHAR),szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}

	std::wstring  ZM_UTF82W(const CHAR *src)
	{
		WCHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UNICODE_CHARSET,UTF8_CHARSET,(CHAR*)src,ZM_Strlen(src),(CHAR*)szDesc,nSize);
		std::wstring strResult = szDesc;
		return strResult;
	}

	std::wstring  ZM_Source2W(const CHAR *szCodePage,const CHAR *src)
	{
		WCHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UNICODE_CHARSET,(CHAR*)szCodePage,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::wstring strResult = szDesc;
		return strResult;
	}
	std::string  ZM_Source2Local(const CHAR *szCodePage,const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		ZM_IconvCovert(cpCharSet,(CHAR*)szCodePage,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}
	std::string  ZM_UTF82Source(const CHAR *szCodePage,const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		ZM_IconvCovert((CHAR*)szCodePage,UTF8_CHARSET,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}

	std::string  ZM_UTF82A(const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(ASCII_CHARSET,UTF8_CHARSET,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}

	std::string  ZM_A2UTF8(const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		ZM_IconvCovert(UTF8_CHARSET,ASCII_CHARSET,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}

	std::string  ZM_Local2UTF8(const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		ZM_IconvCovert(UTF8_CHARSET,cpCharSet,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}

	std::string  ZM_UTF82Local(const CHAR *src)
	{
		CHAR szDesc [ZM_PAGE*10] = {0};
		size_t nSize = ZM_PAGE*10;
		CHAR* cpCharSet = (CHAR*)ZM_GetLocaleCharset();
		ZM_IconvCovert(cpCharSet,UTF8_CHARSET,(CHAR*)src,ZM_StrlenA(src),(CHAR*)szDesc,nSize);
		std::string strResult = szDesc;
		return strResult;
	}



