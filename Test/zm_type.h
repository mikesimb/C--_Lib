/*
本单元主要是处理统一定义一些标准数据类型
*/
#pragma  once
#ifndef ZM_TYPE_H
#define ZM_TYPE_H


#include <string>
#include <wchar.h>

#ifdef _M_X64
#ifndef WIN64
#define WIN64
#endif
#endif

#if (defined(WIN32)|| defined(WIN64))
#pragma  warning(disable:4996)
#pragma  warning(disable:4786)
#include <windows.h>
#include <baseTsd.h>
#include <tchar.h>


#define ZM_API  __stdcall

typedef HANDLE ZM_HANDLE;

#define  ZM_MAX_PATH 260

#define ZM_INVALID_HANDLE   NULL
#define ZM_CLOSEHANDLE(x) CloseHandle(x)

#endif //endif   (defined(WIN32)|| defined(WIN64))

#endif 