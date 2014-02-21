#pragma  once
#ifndef ZM_STRING_H
#define ZM_STRING_H
/*
这个类实现的是字符串类
*/
#include "zm_type.h"
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <stdarg.h>
#include <vector>

#if UNICODE
typedef  std::wstring  zstring;
#else
typedef std::string zstring;
#endif




#if (defined(WIN32)||defined(WIN64))
#include <tchar.h>
#define  ZM_SYMBOL_RT    "\r\n"
#define  ZM_FMT_I64      "%I64d"
#define  ZM_WCHAR_FMT_I64 L"%I64u"
#define  ZM_FMT_U64       "%I64u"
#define  ZM_WCHAR_FMT_U64 L"%U64u"
#define  ZM_FMT_X64       "%I64x"
#endif


  /*
  下边是一些常用的字符串宏的整理
  */

  /*
	功能：判断字符变量c是否为字母或数字

	说明：当c为数字0-9或字母a-z及A-Z时，返回非零值，否则返回零。
	*/
#define ZM_IsAlNum(c) (isalnum(((UCHAR)(c))))

 /*
	一种函数：判断字符ch是否为英文字母，当ch为英文字母a-z或A-Z时，在标准c中相当于使用“isupper(ch)||islower(ch)”做测试，返回非零值(不一定是1)，否则返回零。
	*/
#define ZM_IsAlpha(c)  (isalpha((UCHAR)(c)))

/*	
功能：判断字符c是否为控制字符
说明：当c在0x00-0x1F之间或等于0x7F(DEL)时，返回非零值，否则返回零。	
*/
#define ZM_isCntrl(c)  (iscntrl((UCHAR) (c)))


/*
函数说明	检查参数c是否为阿拉伯数字0到9。
返回值	若参数c为阿拉伯数字，则返回TRUE，否则返回NULL(0)。 
*/
#define ZM_isDigit(c)  (isdigit((UCHAR)(c)))

/*
函数说明 	检查参数c是否为可打印字符，若c所对映的ASCII码可打印，且非空格字符则返回TRUE。
返回值 	若参数c为可打印字符，则返回TRUE，否则返回NULL(0)。
*/
#define ZM_isGraph(c) (isgraph((UCHAR)(c)))

/*
函数说明  检查参数c是否为小写英文字母。
返回值  若参数c为小写英文字母，则返回TRUE，否则返回NULL(0)。

*/
#define ZM_isLower(c) (islower((UCHAR)(c)))

#ifdef ISASCII
#define ZM_isAscii(c) (isascii((UCHAR)(c)))
#else
#define ZM_isAscii(c) (((c) & ~0x7f)==0)
#endif

/*功能：判断字符c是否为可打印字符（含空格）
说明：当c为可打印字符（0x20-0x7e）时，返回非零值，否则返回零。	*/
#define  ZM_isPrint(c) (issprint((UCHAR)(c)))

/*	
函数说明:检查参数c是否为标点符号或特殊符号。返回TRUE也就是代表参数c为非空格、非数字和非英文字母。
返回值;	v若参数c为标点符号或特殊符号，则返回TRUE，否则返回NULL(0)。
*/
#define ZM_isPunct(c) (ispunct((UCHAR)(c)))


/*
函数说明:查参数c是否为空格字符，也就是判断是否为空格(' ')、水平定位字符
('\t')、归位键('\r')、换行('\n')、垂直定位字符('\v')或翻页('\f')的情况。
*/
#define ZM_isSpace(c) (isspace((UCHAR)(c)))

/*
功能：判断字符c是否为大写英文字母
说明：当参数c为大写英文字母(A-Z)时，返回非零值，否则返回零。
*/
#define ZM_isUpper(c) (isupper((UCHAR)(c)))

/*  
函数说明 检查参数c是否为16进制数字，只要c为下列其中一个情况则返回TRUE。16进制数字:0123456789ABCDEF。
 参数类型为int,但是可以直接将char 类型数据传入.
*/
#define ZM_isXdigit(c) (isxdigit((UCHAR)(c)))


  	/*功 能: 把字符转换成小写字母,非字母字符不做出处理*/
#define ZM_toLower(c) (tolower((UCHAR)(c)))

  /*
	功 能: 把字符转换成大写字母,非字母字符不做出处理
  */
#define ZM_toUpper(c) (toupper((UCHAR)(c)))

/*把格式化的数据写入某个字符串缓冲区。*/
#define ZM_sprintf  sprintf

#define ZM_wsprintf swprintf

#if (defined(WIN32) || defined(WIN64))
#define ZM_snprintf  _snprintf
#else
#define ZM_snprintf  snprintf
#endif

  /* 
  把字符串转换成整型数
*/
#define ZM_atoi atoi

#if (defined(WIN32) || defined(WIN64))
  /* 
  把字符串转换成64位整型数
*/
#define ZM_Atoi64 _atoi64
#else
#define ZM_Atoi64 atoll
#endif

#ifdef UNICODE
#define TCHAR  WCHAR
#define ZM_L(x) L##x
#define ZM_strlen                 ZM_StrlenW
#define ZM_Strcat                 ZM_StrcatW
#define ZM_StrSafeCat          ZM_StrSafeCatW
#define ZM_Strncat               ZM_StrncatW
#define ZM_Strcpy                ZM_StrcpyW
#define ZM_StrSafeCpy         ZM_StrSafeCpyW
#define ZM_Strncpy              ZM_StrncpyW
#define ZM_Strcmp               ZM_StrcmpW
#define ZM_Strchr				   ZM_StrchrW
#define ZM_Strcasecmp        ZM_StrcasecmpW
#define ZM_Strtok                 ZM_StrtokW
#define ZM_Strlwr                 ZM_StrlwrW
#define ZM_Strupr                ZM_StruprW

#else
#define TCHAR CHAR;
#define ZM_L(x)  x
#define ZM_strlen                 ZM_StrlenA
#define ZM_Strcat                 ZM_StrcatA
#define ZM_StrSafeCat          ZM_StrSafeCatA
#define ZM_Strncat               ZM_StrncatA
#define ZM_Strcpy                ZM_StrcpyA
#define ZM_StrSafeCpy         ZM_StrSafeCpyA
#define ZM_Strncpy              ZM_StrncpyA
#define ZM_Strcmp               ZM_StrcmpA
#define ZM_Strchr				   ZM_StrchrA
#define ZM_Strcasecmp        ZM_StrcasecmpA
#define ZM_Strtok                ZM_StrtokA
#define ZM_Strlwr                ZM_StrlwrA
#define ZM_Strupr               ZM_StruprA


#endif


    /**
    *功能： 获取字符串的长度
    * @param string : 以0为结束符的字符串
    * @return : 字符串的长度
    */
    inline UINT32  ZM_StrlenA( const CHAR* string )
    {
        return (UINT32)strlen(string);
    }

	  /**
    * 功能：获取Unicode字符串的长度
    * @param string : 以0为结束符的字符串
    * @return : Unicode字符串的长度
    */
    inline UINT32  ZM_StrlenW( const WCHAR* string )
    {
        return (UINT32)wcslen(string);
    }

	 /**
	 *功能： 获取字符串的长度
	 * @param pszStr : 字符串
	 * @param sizeInBytes :最大检测长度
	 * @return 获取字符串的长度，如果字符串的长度超过sizeInBytes，返回sizeInBytes
    */
	inline UINT32  ZM_StrnlenA(const CHAR* pszStr, UINT32 sizeInBytes )
	{
		return (UINT32)strnlen(pszStr, sizeInBytes);
	}

	 /*
    * 功能：获取Unicode字符串的长度
    * @param pszStr : Unicode字符串
    * @param sizeInBytes :最大检测长度
    * @return 获取Unicode字符串的长度，如果Unicode字符串的长度超过sizeInBytes，返回sizeInBytes
    */
    inline UINT32  ZM_StrnlenW(const WCHAR* pszStr, size_t sizeInBytes)
    {
        return (UINT32)wcsnlen(pszStr, sizeInBytes);
    }

    /*
    * 功能：在目标字符串后添加一个字符串
    * @param strDestination : 以0为结束符的目标字符串
    * @param strSource : 以0为结束符的源字符串
    * @return 结果字符串，使用的是目标字符串空间，请预留足够的空间
    */
    inline CHAR*  ZM_StrcatA(CHAR* strDestination, const CHAR* strSource )
    {
        return strcat(strDestination, strSource);
    }

    /*
    * 功能：在目标字符串后添加一个字符串
    * @param strDestination : 以0为结束符的目标字符串
    * @param dstLen : 目标串内存的总长度,如果合并后的长度大于此长度,不会进行合并,返回空串,不修改目标串
    * @param strSource : 以0为结束符的源字符串
    * @return 结果字符串，使用的是目标字符串空间,如果合并后的长度大于此长度,不会进行合并,返回NULL,不修改目标串
    */
    inline CHAR *  ZM_StrSafeCatA(CHAR* strDestination, UINT32 dstLen, const CHAR* strSource)
    {
        if (dstLen < strlen(strDestination) + strlen(strSource) + 1)
        {
            return NULL;
        }
        return strcat(strDestination,strSource);
    }


    /*
    * 功能：在目标Unicode字符串后添加一个Unicode字符串
    * @param strDestination : 以0为结束符的目标Unicode字符串
    * @param strSource : 以0为结束符的源Unicode字符串
    * @return 结果Unicode字符串，使用的是目标Unicode字符串空间，请预留足够的空间
    */
    inline WCHAR*   ZM_StrcatW(WCHAR*strDestination, const WCHAR *strSource )
    {
        return wcscat(strDestination, strSource);
    }

    /*
    * 功能：在目标字符串后添加一个字符串
    * @param strDestination : 以0为结束符的目标字符串
    * @param strSource : 源字符串
    * @param len : 源字符串的最大添加长度
    * @return 结果字符串，使用的是目标字符串空间，请预留足够的空间
    */
    inline CHAR*  ZM_StrncatA(CHAR *strDestination, const CHAR *strSource, UINT32 len)
    {
        return strncat(strDestination, strSource, len);
    }

    /*
    * 功能：在目标Unicode字符串后添加一个Unicode字符串
    * @param strDestination : 以0为结束符的目标Unicode字符串
    * @param strSource : 源Unicode字符串
    * @param len : 源Unicode字符串的最大添加长度
    * @return 结果Unicode字符串，使用的是目标Unicode字符串空间，请预留足够的空间
    */
    inline WCHAR*  ZM_StrncatW(WCHAR *strDestination, const WCHAR *strSource, UINT32 len)
    {
        return wcsncat(strDestination, strSource, len);
    }

    /*
    * 功能：拷贝字符串
    * @param strDestination : 以0为结束符的目标缓冲区，请保证有足够的空间
    * @param strSource : 以0为结束符的源字符串
    * @return 目标字符串
    */
    inline CHAR*  ZM_StrcpyA( CHAR *strDestination, const CHAR *strSource )
    {
        return strcpy(strDestination, strSource);
    }

    /*
    * 安全拷贝字符串
    * @param strDestination : 需要拷贝字符串的目标缓冲区
    * @param numberOfElements : 目标字符串最大长度
    * @param strSource : 以0结尾的源字符串
    * @return 返回目标串,如果目标缓冲区的长度小于源串,返回NULL
    */
    inline CHAR* ZM_StrSafeCpyA( char *strDestination, size_t numberOfElements, const CHAR *strSource )
    {
        if (numberOfElements  < strlen(strSource) +1)
        {
            return NULL;
        }

        return strncpy(strDestination,strSource,numberOfElements);
    }

    /*
    * 功能：安全拷贝字符串
    * @param strDestination : 需要拷贝字符串的目标缓冲区
    * @param numberOfElements : 目标字符串最大长度
    * @param strSource : 以0结尾的源字符串
    * @return 返回目标串,如果目标缓冲区的长度小于源串,返回NULL
    */
    template <class T>
    inline void ZM_StrSafeCpyT(T& Destination, const char* Source) 
    {
        // Use cast to ensure that we only allow character arrays
        (static_cast<char[sizeof(Destination)]>(Destination));

        // Copy up to the size of the buffer
        ZM_StrSafeCpyA(Destination, Source, sizeof(Destination));
    }


    /*
    *功能： 拷贝Unicode字符串
    * @param strDestination : 以0结尾的目标缓冲区，请保证有足够的空间
    * @param strSource : 以0结尾的源字符串
    * @return 目标字符串
    */
    inline WCHAR*  ZM_StrcpyW( WCHAR *strDestination, const WCHAR *strSource )
    {
        return wcscpy(strDestination, strSource);
    }

    /*
	* 功能： 安全拷贝Unicode字符串
    * @param strDestination : 需要拷贝Unicode字符串的目标缓冲区
    * @param numberOfElements : 目标字Unicode符串最大长度
    * @param strSource : 以0结尾的源Unicode字符串
    * @return 返回目标串,如果目标缓冲区的长度小于源串,返回NULL
    */
    WCHAR * ZM_StrSafeCpyW( WCHAR *strDestination, size_t numberOfElements, const WCHAR *strSource );

    /*
    * 功能：拷贝字符串
    * @param strDestination : 以0结尾的目标字符串
    * @param strSource : 以0结尾的源字符串
    * @param len : 最大拷贝长度
    * @return 返回目标字符串
    */
    inline CHAR*  ZM_StrncpyA( CHAR *strDestination, const CHAR *strSource, UINT32 len )
    {
        return strncpy(strDestination, strSource, len);
    }

    /*
    * 功能：拷贝Unicode字符串
    * @param strDestination : 以0结尾的目标Unicode字符串
    * @param strSource : 以0结尾的源Unicode字符串
    * @param len : 最大拷贝长度
    * @return 返回目标Unicode字符串
    */
    inline WCHAR*  ZM_StrncpyW( WCHAR *strDestination, const WCHAR *strSource, UINT32 len )
    {
        return wcsncpy(strDestination, strSource, len);
    }

    /*
	* 功能： 比较字符串
    * @param string1 : 以0结束的字符串1
    * @param string2 : 以0结束的字符串2
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrcmpA( const CHAR *string1, const CHAR *string2 )
    {
        return strcmp(string1, string2);
    }

    /*
    * 功能：比较Unicode字符串
    * @param string1 : 以0结束的Unicode字符串1
    * @param string2 : 以0结束的Unicode字符串2
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrcmpW( const WCHAR *string1, const WCHAR *string2 )
    {
        return wcscmp(string1, string2);
    }

    /*
    * 功能：比较字符串
    * @param string1 : 以0结束的字符串1
    * @param string2 : 以0结束的字符串2
    * @param count : 最大比较长度
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrncmpA( const CHAR *string1, const CHAR *string2, UINT32 count )
    {
        return strncmp( string1, string2, count );
    }

    /*
    * 功能：比较Unicode字符串
    * @param string1 : 以0结束的Unicode字符串1
    * @param string2 : 以0结束的Unicode字符串2
    * @param count : 最大比较长度
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrncmpW( const WCHAR *string1, const WCHAR *string2, size_t count )
    {
        return wcsncmp( string1, string2, count );
    }

    /*
    * 功能：在一个字符串中查找某个字符的位置
    * @param string : 以0结束的字符串
    * @param c : 需要被查找的字符字符
    * @return 指向查找的该字符的第一次出现的位置，或者没有找到返回NULL
    */
    inline CHAR*  ZM_StrchrA( const CHAR *string, INT32 c )
    {
        return (CHAR*)strchr(string, c);
    }

    /*
    * 功能：在一个Unicode字符串中查找某个字符的位置
    * @param string : 以0结束的Unicode字符串
    * @param c : 需要被查找的字符字符
    * @return 指向查找的该字符的第一次出现的位置，或者没有找到返回NULL
    */
    inline WCHAR*  ZM_StrchrW( const WCHAR *string, WCHAR c )
    {
        return (WCHAR*)wcschr(string, c);
    }

    /*
    * 功能：在一个字符串中逆向查找某个字符的位置
    * @param string : 以0结束的字符串
    * @param c : 需要被查找的字符字符
    * @return 指向查找的该字符的最后一次出现的位置，或者没有找到返回NULL
    */
    inline CHAR*  ZM_StrrchrA( const CHAR *string, INT32 c )
    {
        return (CHAR*)strrchr(string ,c);
    }

    /*
    * 功能：在一个Unicode字符串中逆向查找某个字符的位置
    * @param string : 以0结束的Unicode字符串
    * @param c : 需要被查找的字符字符
    * @return 指向查找的该字符的最后一次出现的位置，或者没有找到返回NULL
    */
    wchar_t*  ZM_StrrchrW( const wchar_t *string, wchar_t c );

    /*
    * 功能：无视字符大小写，比较字符串
    * @param s1 : 以0结束的字符串1
    * @param s2 : 以0结束的字符串2
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrcasecmpA(const CHAR *s1, const CHAR *s2)
    {
#if (defined(WIN32) || defined(WIN64))
        return _stricmp(s1, s2);
#else
        return strcasecmp(s1, s2);
#endif
    }

    /*
    * 无视字符大小写，比较字符串
    * @param s1 : 以0结束的字符串1
    * @param s2 : 以0结束的字符串2
    * @param count : 最大比较长度
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    inline INT32  ZM_StrncasecmpA(const CHAR *s1, const CHAR *s2, UINT32 count)
    {
#if (defined(WIN32) || defined(WIN64))
        return _strnicmp(s1, s2, count);
#else
        return strncasecmp(s1, s2, count);
#endif
    }

    /*
    * 功能：无视字符大小写，比较Unicode字符串
    * @param s1 : 以0结束的Unicode字符串1
    * @param s2 : 以0结束的Unicode字符串2
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
     INT32  ZM_StrncasecmpW(const wchar_t *s1, const wchar_t *s2);

    /*
    * 功能：无视字符大小写，比较Unicode字符串
    * @param s1 : 以0结束的Unicode字符串1
    * @param s2 : 以0结束的Unicode字符串2
    * @param count : 最大比较长度
    * @return 比较结果
    * < 0 字符串1小于字符串2
    * 0 字符串1等于字符串2
    * > 0 字符串1大于字符串2
    */
    INT32  ZM_StrncasecmpW(const wchar_t *s1, const wchar_t *s2, UINT32 count);


    /*
    * 功能：将某个字符串切分为多个字符串
    * @param pszStr : 第一次输入被切分的字符串，之后输入NULL
    * @param delim : 分割字符串，如“:”，“,”，“ ”等
    * @return 依次返回被切割的子字符串，如果没有新的子字符串，返回NULL
    */
    inline CHAR*  ZM_StrtokA(CHAR *pszStr, const CHAR *delim)
    {
        return strtok(pszStr, delim);
    }

    /*
    * 功能：将某个Unicode字符串切分为多个Unicode字符串
    * @param pszStr : 第一次输入被切分的Unicode字符串，之后输入NULL
    * @param delim : 分割Unicode字符串，如“:”，“,”，“ ”等
    * @return 依次返回被切割的子Unicode字符串，如果没有新的子Unicode字符串，返回NULL
    */
    inline wchar_t*  ZM_StrtokW(wchar_t *pszStr, const wchar_t *delim);

    /*
    * 功能：将字符串中的所有ANSI字符转化为小写
    * @param pszStr : 以0结尾的字符串
    * @return 被转化的字符串，使用原有字符串的空间，原有字符串将被破坏
    */
    CHAR*  ZM_StrlwrA(CHAR* pszStr);


    /*
    * 功能：将字符串中的所有ANSI字符转化为大写
    * @param pszStr : 以0结尾的字符串
    * @return 被转化的字符串，使用原有字符串的空间，原有字符串将被破坏
    */
    CHAR*  ZM_StruprA(CHAR* pszStr);

    /*
    * 将Unicode字符串中的所有字符转化为小写
    * @param pszStr : 以0结尾的Unicode字符串
    * @return 被转化的Unicode字符串，使用原有Unicode字符串的空间，原有Unicode字符串将被破坏
    */
    WCHAR*  ZM_StrlwrW(WCHAR* pszStr);

    /*
    * 功能：将Unicode字符串中的所有字符转化为大写
    * @param pszStr : 以0结尾的Unicode字符串
    * @return 被转化的Unicode字符串，使用原有Unicode字符串的空间，原有Unicode字符串将被破坏
    */
    WCHAR*  ZM_StruprW(WCHAR* pszStr);

    /*f
    * 将字符串转化为Unicode字符串
    * @param src : 以0结尾的字符串
    * @return 转化后的MultiBytes字符串
    */
	std::wstring  ZM_A2W(const CHAR *src);


 //   /*
 //   * 功能：将Unicode字符串转化为ANSI字符串
 //   * @param src : 以0结尾的Unicode字符串
 //   * @return 转化后的ANSI字符串
 //   */
	//std::string  ZM_W2A(const WCHAR *src);
 // 
 //   /*
 //   * 功能：将Unicode字符集转化为本地操作系统设置的字符集编码
 //   * @param src : 以0结尾的Unicode字符串
 //   * @return 转化后的字符串
 //   */
	//std::string  ZM_W2Local(const WCHAR *src);

 //   /*
 //   *功能： 将本地操作系统设置的字符集编码转换为Unicode字符集
 //   * @param src : 以0结尾的字符串
 //   * @return 转化后的字符串
 //   */
	//std::wstring  ZM_Local2W(const CHAR *src);

 //   /*
 //   * 功能：将Unicode字符集转换为UTF8编码集
 //   * @param src : 以0结尾的Unicode字符串
 //   * @return 转化后的字符串
 //   */
	//std::string  ZM_W2UTF8(const WCHAR *src);

 //   /*
 //   * 功能：将UTF8编码集转换为Unicode字符集
 //   * @param src : 以0结尾的字符串
 //   * @return 转化后的字符串
 //   */
 //   std::wstring  ZM_UTF82W(const CHAR *src);

 //   /*
 //   * 功能：将UTF8编码集转换为ASCII字符集
 //   * @param src : 以0结尾的字符串
 //   * @return 转化后的字符串
 //   */
 //   std::string  ZM_UTF82A(const CHAR *src);

    /*
	*功能： 将ASCII字符集转换为UTF8编码集
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::string  ZM_A2UTF8(const CHAR *src);
  
    /*
    * 功能：将本地操作系统设置的字符集编码转换为UTF8编码集
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::string  ZM_Local2UTF8(const CHAR *src);

    /*
    * 功能：将UTF8编码集转换为本地操作系统设置的字符集编码
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::string  ZM_UTF82Local(const CHAR *src);

    /*
    * 功能：将UTF8编码集转换为本地操作系统设置的字符集编码
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::wstring ZM_Source2W(const CHAR *szCodePage,const CHAR *src);

    /*
    * 功能：将UTF8编码集转换为本地操作系统设置的字符集编码
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::string ZM_Source2Local(const CHAR *szCodePage,const CHAR *src);

    /*
    * 功能：将UTF8编码集转换为本地操作系统设置的字符集编码
    * @param src : 以0结尾的字符串
    * @return 转化后的字符串
    */
    std::string ZM_UTF82Source(const CHAR *szCodePage,const CHAR *src);

	/*
	* 将字符串转换为32位无符号数字
	* @param pStr : 被转换的字符串
	* @return 32位无符号数字
	*/
    UINT32  ZM_Atou(const CHAR* pStr);

	/*
	* 功能：将字符串转换为64位无符号数字
	* @param pStr : 待转化的字符串
	* @return 64位无符号数字
	*/
	UINT64  ZM_Atou64(const CHAR* pStr); 

	/*
	* 功能：将Unicode字符串转换为64位无符号数字
	* @param pStr : 待转化的字符串
	* @return 64位无符号数字
	*/
	UINT64  ZM_Wtou64(const WCHAR* pStr); 

    UINT32  ZM_Wtou(const WCHAR* pStr);

    /*
	* 功能：将Unicode字符串转换为32位有符号数字
	* @param _Str : 待转化的字符串
	* @return 32位有符号数字
	*/
	inline INT32 ZM_Wtoi(const WCHAR *_Str)
	{
		//return atoi(ZM_W2A(_Str).c_str());
	}

    /*
    * 功能：将一个数字转化为字符串
    * @param pBuf : 转化后的字符存储空间
    * @param buflen : 字符存储空间的最大长度
    * @param dwNum : 将被转化的数字
    * @return 转化后字符串使用的空间长度
    */
    inline INT32  ZM_Itoa(CHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return ZM_snprintf(pBuf, buflen, "%d", dwNum);
    }

	/*
    * 功能：将一个数字转化为Unicode字符串
    * @param pBuf : 转化后的字符存储空间
    * @param buflen : 字符存储空间的最大长度
    * @param dwNum : 将被转化的数字
    * @return 转化后字符串使用的空间长度
    */
    inline INT32 ZM_Itow(WCHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%d", dwNum);
    }


	/*
	* 功能：将有64位符号整型转换为字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dqNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
	inline INT32  ZM_Itoa64(CHAR *pBuf, UINT32 buflen, INT64 dqNum)
	{
		return ZM_snprintf(pBuf, buflen, ZM_FMT_I64 , dqNum);
	}

	/*
	* 功能：将有64位符号整型转换为Unicode字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dqNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
    inline INT32  ZM_Itow64(WCHAR *pBuf, UINT32 buflen, INT64 dqNum)
    {
        return swprintf(pBuf, buflen,ZM_WCHAR_FMT_I64 , dqNum);
    }

	/**
	* @brief
	* 将无符号整型转换为字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dwNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
	inline INT32  SDUtoa(CHAR *pBuf, UINT32 buflen, UINT32 dwNum)
	{
		return ZM_snprintf(pBuf, buflen, "%u", dwNum);
	}

	/*
	* 功能：将无符号整型转换为Unicode字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dwNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
    inline INT32  ZM_Utow(WCHAR *pBuf, UINT32 buflen, UINT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%u", dwNum);
    }


	/*
	* 将有64位无符号整型转换为字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dqNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
	inline INT32  ZM_Utoa64(CHAR* pBuf,UINT32 buflen, UINT64 dqNum)
	{
		return ZM_snprintf(pBuf, buflen, ZM_FMT_U64, dqNum);
	}
   
	/*
	* 功能：将有64位无符号整型转换为Unicode字符串
	* @param pBuf : 转化后的字符存储空间
	* @param buflen : 字符存储空间的最大长度
	* @param dqNum : 将被转化的数字
	* @return 转化后字符串使用的空间长度
	*/
    inline INT32  ZM_Utow64(WCHAR* pBuf,UINT32 buflen, UINT64 dqNum)
    {
        return ZM_wsprintf(pBuf, buflen, ZM_WCHAR_FMT_U64, dqNum);
    }

    /*
    * 功能：将字符串转化为浮点数
    * @param nptr : 将被转化的以0结尾的字符串
    * @param endptr : [输出参数]若不为NULL，则遇到无法转化的字符从这里返回其指针
    * @return 获取的浮点数
    */
    inline DOUBLE  ZM_Strtod(const CHAR *nptr, CHAR **endptr)
    {
        return strtod(nptr, endptr);
    }

	/*
    * 功能：将Unicode字符串转化为浮点数
    * @param nptr : 将被转化的以0结尾的字符串
    * @param endptr : [输出参数]若不为NULL，则遇到无法转化的字符从这里返回其指针
    * @return 获取的浮点数
    */
    inline DOUBLE  ZM_WCStrtod(const WCHAR *nptr, WCHAR **endptr)
    {
        return wcstod(nptr, endptr);
    }
    
    /*
    * 功能：split a string将字符串分割为一个字符串的vector
    * @param sSource : 被分割的字符串
    * @param delim : 分隔符，如:“:”，“,”，“ ”等
    * @return a vector to store strings splited from sSource
    */
 //   std::vector<std::string>  ZM_SplitStringsA(const std::string &sSource, CHAR delim);
   
	/*
    * 功能：split a wstring将Unicode字符串分割为一个Unicode字符串的vector
    * @param sSource : 被分割的Unicode字符串
    * @param delim : 分隔符，如:“:”，“,”，“ ”等
    * @return a vector to store wstrings splited from sSource
    */
//	std::vector<std::wstring>  ZM_SplitStringsW(const std::wstring &sSource, WCHAR delim);

    /*
    * 功能：将字符串转化为大写
    * @param pszStr : 将被转化的字符串
    * @return 转化后的字符串
    */
    std::string  ZM_Strupr(std::string &pszStr);

    /*
    * 功能：将字符串转化为小写
    * @param pszStr : 将被转化的字符串
    * @return 转化后的字符串
    */
    std::string  ZM_Strlwr(std::string &pszStr);

    /*
    * 功能：将一个字符串置空
    * @param Destination : 需要置空的类型
    * @return VOID
    */
    template <class T>
    inline VOID  ZM_ZeroString(T &Destination) throw()
    {
        (static_cast<CHAR[sizeof(Destination)]>(Destination));
        Destination[0] = '\0';
        Destination[sizeof(Destination)-1] = '\0';
    }


    /*
    * 功能：将二进制Buffer转换为字符串,
    * @param pBuf    二进制Buffer指针
    * @param bufLen  二进制Buffer长度
    * @param pSplitter 输出的二进制数据间隔符
	* @param lineLen 源字符串分割多行的每行长度,该长度不包含分隔符的长度
    * @return 转换后的字符串
    */
    std::string  ZM_BufferToHexA(const CHAR *pBuf, UINT32 bufLen, const CHAR *pSplitter = "", INT32 lineLen = -1);

	/*
    * 功能：将二进制Buffer转换为Unicode字符串,
    * @param pBuf    二进制Buffer指针
    * @param bufLen  二进制Buffer长度
    * @param pSplitter 输出的二进制数据间隔符
	* @param lineLen 源字符串分割多行的每行长度,该长度不包含分隔符的长度
    * @return 转换后的Unicode字符串
    */
    std::wstring  ZM_BufferToHexW(const WCHAR *pBuf, UINT32 bufLen, const WCHAR *pSplitter = L"", INT32 lineLen = -1);

    /*
    * 功能：将32位有符号整型数字转换为二进制串,
    * @param dwNum : 32位有符号整型数字
    * @return 转换后的字符串
    */
    std::string  ZM_IntToHexA(INT32 dwNum);

	/*
    * 功能：将32位有符号整型数字转换为二进制串,
    * @param dwNum : 32位有符号整型数字
    * @return 转换后的Unicode字符串
    */
    std::wstring  ZM_IntToHexW(INT32 dwNum);

    /*
    * 功能：将str左边的ch去掉，原字符串将被修改
    * @param pszStr : 去掉左边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的字符串
    */
    std::string  ZM_StrTrimLeftA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/*
    * 功能：将str左边的ch去掉，原Unicode字符串将被修改
    * @param pszStr : 去掉左边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的Unicode字符串
    */
    std::wstring  ZM_StrTrimLeftW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /*
    * 功能：将str右边的ch去掉，原字符串将被修改
    * @param pszStr : 去掉右边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的字符串
    */
    std::string  ZM_StrTrimRightA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/*
    * 功能：将str右边的ch去掉，原Unicode字符串将被修改
    * @param pszStr : 去掉右边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的Unicode字符串
    */
	std::wstring  ZM_StrTrimRightW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /*
    * 功能：将str左右两边的pTrimStr去掉，原字符串将被修改
    * @param pszStr : 去掉左右两边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的字符串
    */
    std::string  ZM_StrTrimA(std::string &pszStr, const CHAR* pTrimStr = " \r\t\n");
   
	/*
    * 功能：将str左右两边的pTrimStr去掉，原Unicode字符串将被修改
    * @param pszStr : 去掉左右两边的ch字符
    * @param pTrimStr : 被去掉的字符
    * @return 去掉字符pTrimStr后的Unicode字符串
    */
	std::wstring  ZM_StrTrimW(std::wstring &pszStr, const WCHAR* pTrimStr = L" \r\t\n");

    /** @} */


    /*
	*功能：Unicode字符串格式化
    * @param buffer : 存储格式化后的buffer
    * @param n      : Unicode字符串长度
    * @param format : 待格式化的Unicode字符串
    * @return 正值:成功转换后字符串的长度 负值:格式化失败
    */
	INT32  SM_snwprintf(WCHAR* buffer, size_t n, const WCHAR* format, ...);

    template <class T>
    inline void SM_SafeSprintf(T& Destination, const CHAR *format, ...)
    {
        (static_cast<char[sizeof(Destination)]>(Destination));

        va_list args;
        va_start(args,format);
        _vsnprintf(Destination, sizeof(Destination)-1, format, args);
        va_end(args);
        Destination[sizeof(Destination)-1] = '\0';
    }

#endif

