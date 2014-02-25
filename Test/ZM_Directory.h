#pragma once
#include "zm_string.h"
#include "zm_type.h"
#include <direct.h>
typedef struct _tgaFileAttr{
	BOOL  isDir;
}SFileAttr,*SFileArr;

class CZM_Directory
{
public:
	CZM_Directory(void);
	virtual ~CZM_Directory(void);

	BOOL Open(const CHAR * pszDirName);
	void Close();
	BOOL Read( CHAR* pszitemName, INT32 buflen, SFileAttr* pAttr);

private:
	zstring  m_szpath;  
	ZM_HANDLE  m_HPath;

};

//创建目录
BOOL ZM_CreateDirectory(const CHAR *pszDirName, BOOL bForced = FALSE );

//删除目录
BOOL ZM_DeleteDirectory(const CHAR * pszDirName, BOOL bForce= FALSE);

//目录是否存在
BOOL ZM_DirectoryExists(const CHAR* pszDirName);

//是否是空目录
BOOL ZM_isEmptyDirectory(const CHAR * pszDirName);

//判断是否是一个目录
BOOL ZM_IsDirectory(const CHAR* pszDirName);

//给目录字符串加'\'
zstring  ZM_DirectoryIncludeTrailingDelimiter(const CHAR* pszDirName);

