#pragma once
class zmchartranslate
{
public:
	zmchartranslate(void);
	~zmchartranslate(void);
};


const CHAR *  ZM_GetLocaleCharset (void)
{
	return locale_charset();
}

INT32 ZM_IconvCovert(CHAR *desc, CHAR *src, CHAR *input, size_t ilen, CHAR *output, size_t& olen)
{
	INT32 nOutTotalLen = olen;
	CHAR **pin = &input;
	CHAR **pout = &output;
	iconv_t cd = iconv_open(desc, src);
	if (cd == (iconv_t)-1)
	{
		return -1;
	}
	memset(output, 0, olen);
#ifdef __linux__
	if (iconv(cd, (char**)pin, &ilen, pout, &olen))
#else
	if (iconv(cd, (const char**)pin, &ilen, pout, &olen))
#endif
	{
		iconv_close(cd);
		return -1;
	}
	olen = nOutTotalLen - olen;
	iconv_close(cd);
	return 0;
}
}

