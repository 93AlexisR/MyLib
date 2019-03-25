#pragma once //https://stackoverflow.com/a/3371986
#include <cstdio>
#include <cstdarg>

class CLog
{
public:
	enum { All = 0, Debug, Info, Warning, Error, Fatal, None };
	static void Write(int nLevel, const char *szFormat, ...);
	static void SetLevel(int nLevel);

protected:
	static void CheckInit();
	static void Init();

private:
	CLog();
	static bool m_bInitialised;
	static int  m_nLevel;
};


