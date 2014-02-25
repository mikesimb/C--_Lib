#include "ZM_Directory.h"


CZM_Directory::CZM_Directory(void)
{
}


CZM_Directory::~CZM_Directory(void)
{
}

BOOL CZM_Directory::Open(const CHAR * pszDirName)
{
	m_HPath = INVALID_HANDLE_VALUE;
	m_szpath = pszDirName;
	m_szpath += ZM_L("\\*");
//	ZM_Strncpy(const_cast <char*>(m_szpath.c_str()),pszDirName,ZM_strlen(pszDirName));
	return true;


}

void CZM_Directory::Close()
{
	if (m_HPath !=  INVALID_HANDLE_VALUE)
	{
		FindClose	(m_HPath);
		m_HPath = INVALID_HANDLE_VALUE;
	}
}

BOOL CZM_Directory::Read(CHAR* pszitemName, INT32 buflen, SFileAttr* pAttr)
{
	WIN32_FIND_DATAA  find_data;
	if(m_HPath == INVALID_HANDLE_VALUE)
	{
		m_HPath = FindFirstFileA(m_szpath.c_str(),&find_data);
		if(m_HPath == INVALID_HANDLE_VALUE)
		{
			return FALSE;
		}
	}else
	{
		if(FindNextFileA(m_HPath,&find_data)==0)
			return FALSE;
	}

	if ((ZM_Strcmp(find_data.cFileName,".")==0) || (ZM_Strcmp(find_data.cFileName,"..")==0))
	{
		return Read(pszitemName,buflen,pAttr);
	}
	_sntprintf(pszitemName, buflen, ZM_L("%s"), find_data.cFileName);

        if (pAttr != NULL)
        {
            pAttr->isDir = (find_data.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY) ? 1 : 0;
        }

	return TRUE;
}


/**************************************************************************************************************************************
//目录操作的全局函数
***************************************************************************************************************************************/
BOOL ZM_CreateDirectory(const CHAR* pszDirName,BOOL bForced)
{
	BOOL ret = CreateDirectory(pszDirName,NULL);
	if(!ret)
	{
		//创建目录不成功但是又需要强制创建的
		if(bForced)
		{
			//首先分析字符串获取根目录
			int len  =ZM_strlen(pszDirName);
			CHAR path[ZM_MAX_PATH]={'\0'};
			CHAR* pos = path;
			ZM_Strncpy(pos,pszDirName,len);
			//在windows平台下先找到盘符
			while((*pos) != ZM_L('\0'))
			{
				if (*pos ==ZM_L('\\'))
				{
					if(*(pos-sizeof(CHAR)) ==':')
					{
						//这里是盘符部分结束了
						pos++;
						continue;
					}
					else
					{
						CHAR tmpdir[ZM_MAX_PATH] ={'\0'};   
						CHAR * tmppos = tmpdir;
						ZM_Strncpy(tmppos,pszDirName,pos-path);
						if(!ZM_DirectoryExists(tmppos))
						{
							ZM_CreateDirectory(tmppos);
						}
						printf(ZM_L(" %s \n"),tmpdir);
						//ZM_DirectoryExists(pszDirName,
					}
				}
					 pos++;
			}
		}
	}
	return ret;
}


BOOL ZM_DirectoryExists(const CHAR* pszDirName)
{
	int nCode  = GetFileAttributesA(ZM_L(pszDirName));
	if (nCode ==-1)
	{
		return FALSE;
	}
	else
	{
		return nCode & FILE_ATTRIBUTE_DIRECTORY;
	}
}

BOOL ZM_IsDirectory(const CHAR* pszDirName)
{
	return ZM_DirectoryExists(pszDirName);
}

BOOL ZM_isEmptyDirectory(const CHAR* pszDirName)
{
	if(ZM_DirectoryExists(pszDirName))
	{
		 HANDLE hFind = INVALID_HANDLE_VALUE;

		 zstring dirFile = ZM_DirectoryIncludeTrailingDelimiter(pszDirName);

            BOOL isEmpty = TRUE;
			dirFile+= ZM_L("*");
            WIN32_FIND_DATA find_data;
            hFind = FindFirstFile(dirFile.c_str(), &find_data);
            if (hFind)
            {
                while( FindNextFile(hFind,&find_data))
                {
                    if (_tcscmp(find_data.cFileName,ZM_L(".")) == 0 || _tcscmp(find_data.cFileName,ZM_L("..")) == 0)
                    {
                        continue;
                    }
                    isEmpty = FALSE;
                    break;
                }

                FindClose(hFind);

                return isEmpty;
            }
	}			else
				 return FALSE;

}


BOOL ZM_DeleteDirectory(const CHAR* pszDirName,BOOL bForce)
{
 if(NULL == pszDirName)
        {
            return FALSE;
        }
        if(!bForce)
        {
#if (defined(WIN32) || defined(WIN64))
			return _rmdir(ZM_L(pszDirName)) == 0;
#else
            return rmdir(_SDTT2A(pszDirName)) == 0;
#endif
        }
        else
        {
			CZM_Directory dir;
            if(dir.Open(pszDirName))
            {
				CHAR _filename[ZM_MAX_PATH];
                SFileAttr attr = {0};
                while(dir.Read(_filename, ZM_MAX_PATH, &attr))
                {
                    CHAR _subfilepath[ZM_MAX_PATH];
					ZM_Strncpy(_subfilepath, pszDirName, ZM_MAX_PATH);
					//ZM_Strcat(_subfilepath, ZM_L("\\") );
                    ZM_Strcat(_subfilepath, _filename );
                    if(attr.isDir)
                    {

						if(!ZM_DeleteDirectory(_subfilepath, bForce))
                        {
                            return FALSE;
                        }
                    }
                    else
                    {
                        if(_unlink(ZM_L(_subfilepath)) != 0)
                        {
                            return FALSE;
                        }
                    }
                }
                dir.Close();
                return _rmdir(ZM_L(pszDirName)) == 0;
            }
            return FALSE;
        }

}


zstring  ZM_DirectoryIncludeTrailingDelimiter(const CHAR* pszDirName)
{
	if(NULL == pszDirName)
        {
			return ZM_L("");
        }
	int len = ZM_strlen(pszDirName);
        if (len == 0 )
        {
            return ZM_L("");
        }
        if ((pszDirName[len - 1]!= ZM_L('\\')))
        {
            return zstring(pszDirName) + ZM_L('\\');
        }
        else
        {
            return pszDirName;
        }
}



