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

//����Ŀ¼
BOOL ZM_CreateDirectory(const CHAR *pszDirName, BOOL bForced = FALSE );

//ɾ��Ŀ¼
BOOL ZM_DeleteDirectory(const CHAR * pszDirName, BOOL bForce= FALSE);

//Ŀ¼�Ƿ����
BOOL ZM_DirectoryExists(const CHAR* pszDirName);

//�Ƿ��ǿ�Ŀ¼
BOOL ZM_isEmptyDirectory(const CHAR * pszDirName);

//�ж��Ƿ���һ��Ŀ¼
BOOL ZM_IsDirectory(const CHAR* pszDirName);

//��Ŀ¼�ַ�����'\'
zstring  ZM_DirectoryIncludeTrailingDelimiter(const CHAR* pszDirName);

