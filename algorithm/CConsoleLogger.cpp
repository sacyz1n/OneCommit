#include <iostream>
#include "CConsoleLogger.h"

#pragma warning(disable: 4996)
using namespace Logger;

bool CConsoleLogger::log(Logger::Level _level, int _threadId, const wchar_t * _file, const wchar_t * _func, int _line, const wchar_t * _msg, ...)
{
	wchar_t buffer[512] = L"";
	va_list ap;
	va_start(ap, _msg);
	vswprintf_s(buffer, _msg, ap);
	va_end(ap);

	std::wcout << logLevel[static_cast<unsigned short>(_level)] << "ThreadId:" << _threadId << ", Function:" << _func << ", Line:" << _line << ", Msg:" << buffer << std::endl;

	return true;
}
