#include "zm_string.h"
#include "ZM_Directory.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
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


*/
int main(int  argc , char * argv[])
{
	cout<<"zm_string测试:"<<endl;
	cout<<"输入需要测试的内容的编号："<<endl;
	cout<<"1、ZM_strlen    2、ZM_strcat   3、ZM_Strncat  4、ZM_Strcpy"<<endl;
	cout<<"5、ZM_strcmp  6、ZM_Strchr   7、ZM_Strcasecmp  8、ZM_Strtok"<<endl;
	cout<<"9、ZM_strlwr  10、ZM_Strupr  "<<endl;
	int num;
	cin>>num;
	switch(num)
	{
	case 1:
		{
			zstring name ;
			cout<<"请输入测试的内容"<<endl;
			cin>>name;
			cout<<ZM_strlen(name.c_str())<<endl;
			break;
		}
	case 2:
		{
			zstring txt_source ;
			zstring txt_dest;
			char * c_dest;
			cout<<"请输入测试的txt_source"<<endl;
			cin>>txt_source;
			cout<<"请输入测试的txt_dest"<<endl;
			cin>>txt_dest;
			c_dest =const_cast<char*>( txt_dest.c_str());
			cout<<ZM_Strcat(c_dest,txt_source.c_str())<<endl;
		
			break;
		}
	case 3:
		{
			zstring txt_source ;
			zstring txt_dest;
			int charnum;
			char * c_dest;
			cout<<"请输入测试的txt_source"<<endl;
			cin>>txt_source;
			cout<<"请输入测试的txt_dest"<<endl;
			cin>>txt_dest;
			c_dest =const_cast<char*>( txt_dest.c_str());
			cout<<"输入需要连接的字符个数"<<endl;
			cin>>charnum;
			cout<<ZM_Strncat(c_dest,txt_source.c_str(),charnum)<<endl;
		
			break;
		}
	case 4:
		{
			zstring txt_source ;
			zstring txt_dest;
			int charnum;
			char * c_dest;
			cout<<"请输入测试的txt_source"<<endl;
			cin>>txt_source;
			cout<<"请输入测试的txt_dest"<<endl;
			cin>>txt_dest;
			c_dest =const_cast<char*>( txt_dest.c_str());
			cout<<ZM_Strcpy(c_dest,txt_source.c_str())<<endl;
		
			break;
		}
	case 5:
		{
			//ZM_CreateDirectory(ZM_L("C:\\Bool\\k\\f\\"),TRUE);
			if(ZM_isEmptyDirectory(ZM_L("C:\\Bool\\k\\f\\")))
			{
				printf("is Empty!");
			}
			else
				printf("is Not Empty!");
			if(ZM_DeleteDirectory(ZM_L("C:\\Bool\\"),TRUE))
				printf("Delete Directory is Successed");
			break;
		}
	default:
		break;
	}
	cin>>num;
}