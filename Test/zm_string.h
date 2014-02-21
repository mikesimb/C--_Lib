#pragma  once
#ifndef ZM_STRING_H
#define ZM_STRING_H
/*
�����ʵ�ֵ����ַ�����
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
  �±���һЩ���õ��ַ����������
  */

  /*
	���ܣ��ж��ַ�����c�Ƿ�Ϊ��ĸ������

	˵������cΪ����0-9����ĸa-z��A-Zʱ�����ط���ֵ�����򷵻��㡣
	*/
#define ZM_IsAlNum(c) (isalnum(((UCHAR)(c))))

 /*
	һ�ֺ������ж��ַ�ch�Ƿ�ΪӢ����ĸ����chΪӢ����ĸa-z��A-Zʱ���ڱ�׼c���൱��ʹ�á�isupper(ch)||islower(ch)�������ԣ����ط���ֵ(��һ����1)�����򷵻��㡣
	*/
#define ZM_IsAlpha(c)  (isalpha((UCHAR)(c)))

/*	
���ܣ��ж��ַ�c�Ƿ�Ϊ�����ַ�
˵������c��0x00-0x1F֮������0x7F(DEL)ʱ�����ط���ֵ�����򷵻��㡣	
*/
#define ZM_isCntrl(c)  (iscntrl((UCHAR) (c)))


/*
����˵��	������c�Ƿ�Ϊ����������0��9��
����ֵ	������cΪ���������֣��򷵻�TRUE�����򷵻�NULL(0)�� 
*/
#define ZM_isDigit(c)  (isdigit((UCHAR)(c)))

/*
����˵�� 	������c�Ƿ�Ϊ�ɴ�ӡ�ַ�����c����ӳ��ASCII��ɴ�ӡ���ҷǿո��ַ��򷵻�TRUE��
����ֵ 	������cΪ�ɴ�ӡ�ַ����򷵻�TRUE�����򷵻�NULL(0)��
*/
#define ZM_isGraph(c) (isgraph((UCHAR)(c)))

/*
����˵��  ������c�Ƿ�ΪСдӢ����ĸ��
����ֵ  ������cΪСдӢ����ĸ���򷵻�TRUE�����򷵻�NULL(0)��

*/
#define ZM_isLower(c) (islower((UCHAR)(c)))

#ifdef ISASCII
#define ZM_isAscii(c) (isascii((UCHAR)(c)))
#else
#define ZM_isAscii(c) (((c) & ~0x7f)==0)
#endif

/*���ܣ��ж��ַ�c�Ƿ�Ϊ�ɴ�ӡ�ַ������ո�
˵������cΪ�ɴ�ӡ�ַ���0x20-0x7e��ʱ�����ط���ֵ�����򷵻��㡣	*/
#define  ZM_isPrint(c) (issprint((UCHAR)(c)))

/*	
����˵��:������c�Ƿ�Ϊ�����Ż�������š�����TRUEҲ���Ǵ������cΪ�ǿո񡢷����ֺͷ�Ӣ����ĸ��
����ֵ;	v������cΪ�����Ż�������ţ��򷵻�TRUE�����򷵻�NULL(0)��
*/
#define ZM_isPunct(c) (ispunct((UCHAR)(c)))


/*
����˵��:�����c�Ƿ�Ϊ�ո��ַ���Ҳ�����ж��Ƿ�Ϊ�ո�(' ')��ˮƽ��λ�ַ�
('\t')����λ��('\r')������('\n')����ֱ��λ�ַ�('\v')��ҳ('\f')�������
*/
#define ZM_isSpace(c) (isspace((UCHAR)(c)))

/*
���ܣ��ж��ַ�c�Ƿ�Ϊ��дӢ����ĸ
˵����������cΪ��дӢ����ĸ(A-Z)ʱ�����ط���ֵ�����򷵻��㡣
*/
#define ZM_isUpper(c) (isupper((UCHAR)(c)))

/*  
����˵�� ������c�Ƿ�Ϊ16�������֣�ֻҪcΪ��������һ������򷵻�TRUE��16��������:0123456789ABCDEF��
 ��������Ϊint,���ǿ���ֱ�ӽ�char �������ݴ���.
*/
#define ZM_isXdigit(c) (isxdigit((UCHAR)(c)))


  	/*�� ��: ���ַ�ת����Сд��ĸ,����ĸ�ַ�����������*/
#define ZM_toLower(c) (tolower((UCHAR)(c)))

  /*
	�� ��: ���ַ�ת���ɴ�д��ĸ,����ĸ�ַ�����������
  */
#define ZM_toUpper(c) (toupper((UCHAR)(c)))

/*�Ѹ�ʽ��������д��ĳ���ַ�����������*/
#define ZM_sprintf  sprintf

#define ZM_wsprintf swprintf

#if (defined(WIN32) || defined(WIN64))
#define ZM_snprintf  _snprintf
#else
#define ZM_snprintf  snprintf
#endif

  /* 
  ���ַ���ת����������
*/
#define ZM_atoi atoi

#if (defined(WIN32) || defined(WIN64))
  /* 
  ���ַ���ת����64λ������
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
    *���ܣ� ��ȡ�ַ����ĳ���
    * @param string : ��0Ϊ���������ַ���
    * @return : �ַ����ĳ���
    */
    inline UINT32  ZM_StrlenA( const CHAR* string )
    {
        return (UINT32)strlen(string);
    }

	  /**
    * ���ܣ���ȡUnicode�ַ����ĳ���
    * @param string : ��0Ϊ���������ַ���
    * @return : Unicode�ַ����ĳ���
    */
    inline UINT32  ZM_StrlenW( const WCHAR* string )
    {
        return (UINT32)wcslen(string);
    }

	 /**
	 *���ܣ� ��ȡ�ַ����ĳ���
	 * @param pszStr : �ַ���
	 * @param sizeInBytes :����ⳤ��
	 * @return ��ȡ�ַ����ĳ��ȣ�����ַ����ĳ��ȳ���sizeInBytes������sizeInBytes
    */
	inline UINT32  ZM_StrnlenA(const CHAR* pszStr, UINT32 sizeInBytes )
	{
		return (UINT32)strnlen(pszStr, sizeInBytes);
	}

	 /*
    * ���ܣ���ȡUnicode�ַ����ĳ���
    * @param pszStr : Unicode�ַ���
    * @param sizeInBytes :����ⳤ��
    * @return ��ȡUnicode�ַ����ĳ��ȣ����Unicode�ַ����ĳ��ȳ���sizeInBytes������sizeInBytes
    */
    inline UINT32  ZM_StrnlenW(const WCHAR* pszStr, size_t sizeInBytes)
    {
        return (UINT32)wcsnlen(pszStr, sizeInBytes);
    }

    /*
    * ���ܣ���Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline CHAR*  ZM_StrcatA(CHAR* strDestination, const CHAR* strSource )
    {
        return strcat(strDestination, strSource);
    }

    /*
    * ���ܣ���Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param dstLen : Ŀ�괮�ڴ���ܳ���,����ϲ���ĳ��ȴ��ڴ˳���,������кϲ�,���ؿմ�,���޸�Ŀ�괮
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ�,����ϲ���ĳ��ȴ��ڴ˳���,������кϲ�,����NULL,���޸�Ŀ�괮
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
    * ���ܣ���Ŀ��Unicode�ַ��������һ��Unicode�ַ���
    * @param strDestination : ��0Ϊ��������Ŀ��Unicode�ַ���
    * @param strSource : ��0Ϊ��������ԴUnicode�ַ���
    * @return ���Unicode�ַ�����ʹ�õ���Ŀ��Unicode�ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline WCHAR*   ZM_StrcatW(WCHAR*strDestination, const WCHAR *strSource )
    {
        return wcscat(strDestination, strSource);
    }

    /*
    * ���ܣ���Ŀ���ַ��������һ���ַ���
    * @param strDestination : ��0Ϊ��������Ŀ���ַ���
    * @param strSource : Դ�ַ���
    * @param len : Դ�ַ����������ӳ���
    * @return ����ַ�����ʹ�õ���Ŀ���ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline CHAR*  ZM_StrncatA(CHAR *strDestination, const CHAR *strSource, UINT32 len)
    {
        return strncat(strDestination, strSource, len);
    }

    /*
    * ���ܣ���Ŀ��Unicode�ַ��������һ��Unicode�ַ���
    * @param strDestination : ��0Ϊ��������Ŀ��Unicode�ַ���
    * @param strSource : ԴUnicode�ַ���
    * @param len : ԴUnicode�ַ����������ӳ���
    * @return ���Unicode�ַ�����ʹ�õ���Ŀ��Unicode�ַ����ռ䣬��Ԥ���㹻�Ŀռ�
    */
    inline WCHAR*  ZM_StrncatW(WCHAR *strDestination, const WCHAR *strSource, UINT32 len)
    {
        return wcsncat(strDestination, strSource, len);
    }

    /*
    * ���ܣ������ַ���
    * @param strDestination : ��0Ϊ��������Ŀ�껺�������뱣֤���㹻�Ŀռ�
    * @param strSource : ��0Ϊ��������Դ�ַ���
    * @return Ŀ���ַ���
    */
    inline CHAR*  ZM_StrcpyA( CHAR *strDestination, const CHAR *strSource )
    {
        return strcpy(strDestination, strSource);
    }

    /*
    * ��ȫ�����ַ���
    * @param strDestination : ��Ҫ�����ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ���ַ�����󳤶�
    * @param strSource : ��0��β��Դ�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
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
    * ���ܣ���ȫ�����ַ���
    * @param strDestination : ��Ҫ�����ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ���ַ�����󳤶�
    * @param strSource : ��0��β��Դ�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
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
    *���ܣ� ����Unicode�ַ���
    * @param strDestination : ��0��β��Ŀ�껺�������뱣֤���㹻�Ŀռ�
    * @param strSource : ��0��β��Դ�ַ���
    * @return Ŀ���ַ���
    */
    inline WCHAR*  ZM_StrcpyW( WCHAR *strDestination, const WCHAR *strSource )
    {
        return wcscpy(strDestination, strSource);
    }

    /*
	* ���ܣ� ��ȫ����Unicode�ַ���
    * @param strDestination : ��Ҫ����Unicode�ַ�����Ŀ�껺����
    * @param numberOfElements : Ŀ����Unicode������󳤶�
    * @param strSource : ��0��β��ԴUnicode�ַ���
    * @return ����Ŀ�괮,���Ŀ�껺�����ĳ���С��Դ��,����NULL
    */
    WCHAR * ZM_StrSafeCpyW( WCHAR *strDestination, size_t numberOfElements, const WCHAR *strSource );

    /*
    * ���ܣ������ַ���
    * @param strDestination : ��0��β��Ŀ���ַ���
    * @param strSource : ��0��β��Դ�ַ���
    * @param len : ��󿽱�����
    * @return ����Ŀ���ַ���
    */
    inline CHAR*  ZM_StrncpyA( CHAR *strDestination, const CHAR *strSource, UINT32 len )
    {
        return strncpy(strDestination, strSource, len);
    }

    /*
    * ���ܣ�����Unicode�ַ���
    * @param strDestination : ��0��β��Ŀ��Unicode�ַ���
    * @param strSource : ��0��β��ԴUnicode�ַ���
    * @param len : ��󿽱�����
    * @return ����Ŀ��Unicode�ַ���
    */
    inline WCHAR*  ZM_StrncpyW( WCHAR *strDestination, const WCHAR *strSource, UINT32 len )
    {
        return wcsncpy(strDestination, strSource, len);
    }

    /*
	* ���ܣ� �Ƚ��ַ���
    * @param string1 : ��0�������ַ���1
    * @param string2 : ��0�������ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  ZM_StrcmpA( const CHAR *string1, const CHAR *string2 )
    {
        return strcmp(string1, string2);
    }

    /*
    * ���ܣ��Ƚ�Unicode�ַ���
    * @param string1 : ��0������Unicode�ַ���1
    * @param string2 : ��0������Unicode�ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  ZM_StrcmpW( const WCHAR *string1, const WCHAR *string2 )
    {
        return wcscmp(string1, string2);
    }

    /*
    * ���ܣ��Ƚ��ַ���
    * @param string1 : ��0�������ַ���1
    * @param string2 : ��0�������ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  ZM_StrncmpA( const CHAR *string1, const CHAR *string2, UINT32 count )
    {
        return strncmp( string1, string2, count );
    }

    /*
    * ���ܣ��Ƚ�Unicode�ַ���
    * @param string1 : ��0������Unicode�ַ���1
    * @param string2 : ��0������Unicode�ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    inline INT32  ZM_StrncmpW( const WCHAR *string1, const WCHAR *string2, size_t count )
    {
        return wcsncmp( string1, string2, count );
    }

    /*
    * ���ܣ���һ���ַ����в���ĳ���ַ���λ��
    * @param string : ��0�������ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ��ĵ�һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline CHAR*  ZM_StrchrA( const CHAR *string, INT32 c )
    {
        return (CHAR*)strchr(string, c);
    }

    /*
    * ���ܣ���һ��Unicode�ַ����в���ĳ���ַ���λ��
    * @param string : ��0������Unicode�ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ��ĵ�һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline WCHAR*  ZM_StrchrW( const WCHAR *string, WCHAR c )
    {
        return (WCHAR*)wcschr(string, c);
    }

    /*
    * ���ܣ���һ���ַ������������ĳ���ַ���λ��
    * @param string : ��0�������ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ������һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    inline CHAR*  ZM_StrrchrA( const CHAR *string, INT32 c )
    {
        return (CHAR*)strrchr(string ,c);
    }

    /*
    * ���ܣ���һ��Unicode�ַ������������ĳ���ַ���λ��
    * @param string : ��0������Unicode�ַ���
    * @param c : ��Ҫ�����ҵ��ַ��ַ�
    * @return ָ����ҵĸ��ַ������һ�γ��ֵ�λ�ã�����û���ҵ�����NULL
    */
    wchar_t*  ZM_StrrchrW( const wchar_t *string, wchar_t c );

    /*
    * ���ܣ������ַ���Сд���Ƚ��ַ���
    * @param s1 : ��0�������ַ���1
    * @param s2 : ��0�������ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
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
    * �����ַ���Сд���Ƚ��ַ���
    * @param s1 : ��0�������ַ���1
    * @param s2 : ��0�������ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
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
    * ���ܣ������ַ���Сд���Ƚ�Unicode�ַ���
    * @param s1 : ��0������Unicode�ַ���1
    * @param s2 : ��0������Unicode�ַ���2
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
     INT32  ZM_StrncasecmpW(const wchar_t *s1, const wchar_t *s2);

    /*
    * ���ܣ������ַ���Сд���Ƚ�Unicode�ַ���
    * @param s1 : ��0������Unicode�ַ���1
    * @param s2 : ��0������Unicode�ַ���2
    * @param count : ���Ƚϳ���
    * @return �ȽϽ��
    * < 0 �ַ���1С���ַ���2
    * 0 �ַ���1�����ַ���2
    * > 0 �ַ���1�����ַ���2
    */
    INT32  ZM_StrncasecmpW(const wchar_t *s1, const wchar_t *s2, UINT32 count);


    /*
    * ���ܣ���ĳ���ַ����з�Ϊ����ַ���
    * @param pszStr : ��һ�����뱻�зֵ��ַ�����֮������NULL
    * @param delim : �ָ��ַ������硰:������,������ ����
    * @return ���η��ر��и�����ַ��������û���µ����ַ���������NULL
    */
    inline CHAR*  ZM_StrtokA(CHAR *pszStr, const CHAR *delim)
    {
        return strtok(pszStr, delim);
    }

    /*
    * ���ܣ���ĳ��Unicode�ַ����з�Ϊ���Unicode�ַ���
    * @param pszStr : ��һ�����뱻�зֵ�Unicode�ַ�����֮������NULL
    * @param delim : �ָ�Unicode�ַ������硰:������,������ ����
    * @return ���η��ر��и����Unicode�ַ��������û���µ���Unicode�ַ���������NULL
    */
    inline wchar_t*  ZM_StrtokW(wchar_t *pszStr, const wchar_t *delim);

    /*
    * ���ܣ����ַ����е�����ANSI�ַ�ת��ΪСд
    * @param pszStr : ��0��β���ַ���
    * @return ��ת�����ַ�����ʹ��ԭ���ַ����Ŀռ䣬ԭ���ַ��������ƻ�
    */
    CHAR*  ZM_StrlwrA(CHAR* pszStr);


    /*
    * ���ܣ����ַ����е�����ANSI�ַ�ת��Ϊ��д
    * @param pszStr : ��0��β���ַ���
    * @return ��ת�����ַ�����ʹ��ԭ���ַ����Ŀռ䣬ԭ���ַ��������ƻ�
    */
    CHAR*  ZM_StruprA(CHAR* pszStr);

    /*
    * ��Unicode�ַ����е������ַ�ת��ΪСд
    * @param pszStr : ��0��β��Unicode�ַ���
    * @return ��ת����Unicode�ַ�����ʹ��ԭ��Unicode�ַ����Ŀռ䣬ԭ��Unicode�ַ��������ƻ�
    */
    WCHAR*  ZM_StrlwrW(WCHAR* pszStr);

    /*
    * ���ܣ���Unicode�ַ����е������ַ�ת��Ϊ��д
    * @param pszStr : ��0��β��Unicode�ַ���
    * @return ��ת����Unicode�ַ�����ʹ��ԭ��Unicode�ַ����Ŀռ䣬ԭ��Unicode�ַ��������ƻ�
    */
    WCHAR*  ZM_StruprW(WCHAR* pszStr);

    /*f
    * ���ַ���ת��ΪUnicode�ַ���
    * @param src : ��0��β���ַ���
    * @return ת�����MultiBytes�ַ���
    */
	std::wstring  ZM_A2W(const CHAR *src);


 //   /*
 //   * ���ܣ���Unicode�ַ���ת��ΪANSI�ַ���
 //   * @param src : ��0��β��Unicode�ַ���
 //   * @return ת�����ANSI�ַ���
 //   */
	//std::string  ZM_W2A(const WCHAR *src);
 // 
 //   /*
 //   * ���ܣ���Unicode�ַ���ת��Ϊ���ز���ϵͳ���õ��ַ�������
 //   * @param src : ��0��β��Unicode�ַ���
 //   * @return ת������ַ���
 //   */
	//std::string  ZM_W2Local(const WCHAR *src);

 //   /*
 //   *���ܣ� �����ز���ϵͳ���õ��ַ�������ת��ΪUnicode�ַ���
 //   * @param src : ��0��β���ַ���
 //   * @return ת������ַ���
 //   */
	//std::wstring  ZM_Local2W(const CHAR *src);

 //   /*
 //   * ���ܣ���Unicode�ַ���ת��ΪUTF8���뼯
 //   * @param src : ��0��β��Unicode�ַ���
 //   * @return ת������ַ���
 //   */
	//std::string  ZM_W2UTF8(const WCHAR *src);

 //   /*
 //   * ���ܣ���UTF8���뼯ת��ΪUnicode�ַ���
 //   * @param src : ��0��β���ַ���
 //   * @return ת������ַ���
 //   */
 //   std::wstring  ZM_UTF82W(const CHAR *src);

 //   /*
 //   * ���ܣ���UTF8���뼯ת��ΪASCII�ַ���
 //   * @param src : ��0��β���ַ���
 //   * @return ת������ַ���
 //   */
 //   std::string  ZM_UTF82A(const CHAR *src);

    /*
	*���ܣ� ��ASCII�ַ���ת��ΪUTF8���뼯
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  ZM_A2UTF8(const CHAR *src);
  
    /*
    * ���ܣ������ز���ϵͳ���õ��ַ�������ת��ΪUTF8���뼯
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  ZM_Local2UTF8(const CHAR *src);

    /*
    * ���ܣ���UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string  ZM_UTF82Local(const CHAR *src);

    /*
    * ���ܣ���UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::wstring ZM_Source2W(const CHAR *szCodePage,const CHAR *src);

    /*
    * ���ܣ���UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string ZM_Source2Local(const CHAR *szCodePage,const CHAR *src);

    /*
    * ���ܣ���UTF8���뼯ת��Ϊ���ز���ϵͳ���õ��ַ�������
    * @param src : ��0��β���ַ���
    * @return ת������ַ���
    */
    std::string ZM_UTF82Source(const CHAR *szCodePage,const CHAR *src);

	/*
	* ���ַ���ת��Ϊ32λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 32λ�޷�������
	*/
    UINT32  ZM_Atou(const CHAR* pStr);

	/*
	* ���ܣ����ַ���ת��Ϊ64λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 64λ�޷�������
	*/
	UINT64  ZM_Atou64(const CHAR* pStr); 

	/*
	* ���ܣ���Unicode�ַ���ת��Ϊ64λ�޷�������
	* @param pStr : ��ת�����ַ���
	* @return 64λ�޷�������
	*/
	UINT64  ZM_Wtou64(const WCHAR* pStr); 

    UINT32  ZM_Wtou(const WCHAR* pStr);

    /*
	* ���ܣ���Unicode�ַ���ת��Ϊ32λ�з�������
	* @param _Str : ��ת�����ַ���
	* @return 32λ�з�������
	*/
	inline INT32 ZM_Wtoi(const WCHAR *_Str)
	{
		//return atoi(ZM_W2A(_Str).c_str());
	}

    /*
    * ���ܣ���һ������ת��Ϊ�ַ���
    * @param pBuf : ת������ַ��洢�ռ�
    * @param buflen : �ַ��洢�ռ����󳤶�
    * @param dwNum : ����ת��������
    * @return ת�����ַ���ʹ�õĿռ䳤��
    */
    inline INT32  ZM_Itoa(CHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return ZM_snprintf(pBuf, buflen, "%d", dwNum);
    }

	/*
    * ���ܣ���һ������ת��ΪUnicode�ַ���
    * @param pBuf : ת������ַ��洢�ռ�
    * @param buflen : �ַ��洢�ռ����󳤶�
    * @param dwNum : ����ת��������
    * @return ת�����ַ���ʹ�õĿռ䳤��
    */
    inline INT32 ZM_Itow(WCHAR* pBuf, UINT32 buflen, INT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%d", dwNum);
    }


	/*
	* ���ܣ�����64λ��������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  ZM_Itoa64(CHAR *pBuf, UINT32 buflen, INT64 dqNum)
	{
		return ZM_snprintf(pBuf, buflen, ZM_FMT_I64 , dqNum);
	}

	/*
	* ���ܣ�����64λ��������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  ZM_Itow64(WCHAR *pBuf, UINT32 buflen, INT64 dqNum)
    {
        return swprintf(pBuf, buflen,ZM_WCHAR_FMT_I64 , dqNum);
    }

	/**
	* @brief
	* ���޷�������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dwNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  SDUtoa(CHAR *pBuf, UINT32 buflen, UINT32 dwNum)
	{
		return ZM_snprintf(pBuf, buflen, "%u", dwNum);
	}

	/*
	* ���ܣ����޷�������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dwNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  ZM_Utow(WCHAR *pBuf, UINT32 buflen, UINT32 dwNum)
    {
        return swprintf(pBuf, buflen, L"%u", dwNum);
    }


	/*
	* ����64λ�޷�������ת��Ϊ�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
	inline INT32  ZM_Utoa64(CHAR* pBuf,UINT32 buflen, UINT64 dqNum)
	{
		return ZM_snprintf(pBuf, buflen, ZM_FMT_U64, dqNum);
	}
   
	/*
	* ���ܣ�����64λ�޷�������ת��ΪUnicode�ַ���
	* @param pBuf : ת������ַ��洢�ռ�
	* @param buflen : �ַ��洢�ռ����󳤶�
	* @param dqNum : ����ת��������
	* @return ת�����ַ���ʹ�õĿռ䳤��
	*/
    inline INT32  ZM_Utow64(WCHAR* pBuf,UINT32 buflen, UINT64 dqNum)
    {
        return ZM_wsprintf(pBuf, buflen, ZM_WCHAR_FMT_U64, dqNum);
    }

    /*
    * ���ܣ����ַ���ת��Ϊ������
    * @param nptr : ����ת������0��β���ַ���
    * @param endptr : [�������]����ΪNULL���������޷�ת�����ַ������ﷵ����ָ��
    * @return ��ȡ�ĸ�����
    */
    inline DOUBLE  ZM_Strtod(const CHAR *nptr, CHAR **endptr)
    {
        return strtod(nptr, endptr);
    }

	/*
    * ���ܣ���Unicode�ַ���ת��Ϊ������
    * @param nptr : ����ת������0��β���ַ���
    * @param endptr : [�������]����ΪNULL���������޷�ת�����ַ������ﷵ����ָ��
    * @return ��ȡ�ĸ�����
    */
    inline DOUBLE  ZM_WCStrtod(const WCHAR *nptr, WCHAR **endptr)
    {
        return wcstod(nptr, endptr);
    }
    
    /*
    * ���ܣ�split a string���ַ����ָ�Ϊһ���ַ�����vector
    * @param sSource : ���ָ���ַ���
    * @param delim : �ָ�������:��:������,������ ����
    * @return a vector to store strings splited from sSource
    */
 //   std::vector<std::string>  ZM_SplitStringsA(const std::string &sSource, CHAR delim);
   
	/*
    * ���ܣ�split a wstring��Unicode�ַ����ָ�Ϊһ��Unicode�ַ�����vector
    * @param sSource : ���ָ��Unicode�ַ���
    * @param delim : �ָ�������:��:������,������ ����
    * @return a vector to store wstrings splited from sSource
    */
//	std::vector<std::wstring>  ZM_SplitStringsW(const std::wstring &sSource, WCHAR delim);

    /*
    * ���ܣ����ַ���ת��Ϊ��д
    * @param pszStr : ����ת�����ַ���
    * @return ת������ַ���
    */
    std::string  ZM_Strupr(std::string &pszStr);

    /*
    * ���ܣ����ַ���ת��ΪСд
    * @param pszStr : ����ת�����ַ���
    * @return ת������ַ���
    */
    std::string  ZM_Strlwr(std::string &pszStr);

    /*
    * ���ܣ���һ���ַ����ÿ�
    * @param Destination : ��Ҫ�ÿյ�����
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
    * ���ܣ���������Bufferת��Ϊ�ַ���,
    * @param pBuf    ������Bufferָ��
    * @param bufLen  ������Buffer����
    * @param pSplitter ����Ķ��������ݼ����
	* @param lineLen Դ�ַ����ָ���е�ÿ�г���,�ó��Ȳ������ָ����ĳ���
    * @return ת������ַ���
    */
    std::string  ZM_BufferToHexA(const CHAR *pBuf, UINT32 bufLen, const CHAR *pSplitter = "", INT32 lineLen = -1);

	/*
    * ���ܣ���������Bufferת��ΪUnicode�ַ���,
    * @param pBuf    ������Bufferָ��
    * @param bufLen  ������Buffer����
    * @param pSplitter ����Ķ��������ݼ����
	* @param lineLen Դ�ַ����ָ���е�ÿ�г���,�ó��Ȳ������ָ����ĳ���
    * @return ת�����Unicode�ַ���
    */
    std::wstring  ZM_BufferToHexW(const WCHAR *pBuf, UINT32 bufLen, const WCHAR *pSplitter = L"", INT32 lineLen = -1);

    /*
    * ���ܣ���32λ�з�����������ת��Ϊ�����ƴ�,
    * @param dwNum : 32λ�з�����������
    * @return ת������ַ���
    */
    std::string  ZM_IntToHexA(INT32 dwNum);

	/*
    * ���ܣ���32λ�з�����������ת��Ϊ�����ƴ�,
    * @param dwNum : 32λ�з�����������
    * @return ת�����Unicode�ַ���
    */
    std::wstring  ZM_IntToHexW(INT32 dwNum);

    /*
    * ���ܣ���str��ߵ�chȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ����ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  ZM_StrTrimLeftA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/*
    * ���ܣ���str��ߵ�chȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ����ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
    std::wstring  ZM_StrTrimLeftW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /*
    * ���ܣ���str�ұߵ�chȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ���ұߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  ZM_StrTrimRightA(std::string &pszStr, const CHAR *pTrimStr = " \r\t\n");

	/*
    * ���ܣ���str�ұߵ�chȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ���ұߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
	std::wstring  ZM_StrTrimRightW(std::wstring &pszStr, const WCHAR *pTrimStr = L" \r\t\n");

    /*
    * ���ܣ���str�������ߵ�pTrimStrȥ����ԭ�ַ��������޸�
    * @param pszStr : ȥ���������ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr����ַ���
    */
    std::string  ZM_StrTrimA(std::string &pszStr, const CHAR* pTrimStr = " \r\t\n");
   
	/*
    * ���ܣ���str�������ߵ�pTrimStrȥ����ԭUnicode�ַ��������޸�
    * @param pszStr : ȥ���������ߵ�ch�ַ�
    * @param pTrimStr : ��ȥ�����ַ�
    * @return ȥ���ַ�pTrimStr���Unicode�ַ���
    */
	std::wstring  ZM_StrTrimW(std::wstring &pszStr, const WCHAR* pTrimStr = L" \r\t\n");

    /** @} */


    /*
	*���ܣ�Unicode�ַ�����ʽ��
    * @param buffer : �洢��ʽ�����buffer
    * @param n      : Unicode�ַ�������
    * @param format : ����ʽ����Unicode�ַ���
    * @return ��ֵ:�ɹ�ת�����ַ����ĳ��� ��ֵ:��ʽ��ʧ��
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

