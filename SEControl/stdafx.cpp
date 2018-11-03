
// stdafx.cpp : 只包括标准包含文件的源文件
// SEControl.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"


char* str2char(CString str) //CString -> const char *
{
	char *ptr;
#ifdef _UNICODE
	LONG len;
	len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	ptr = new char[len + 1];
	memset(ptr, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, str, -1, ptr, len + 1, NULL, NULL);
#else
	ptr = new char[str.GetAllocLength() + 1];
	sprintf(ptr, _T("%s"), str);
#endif
	return ptr;
}