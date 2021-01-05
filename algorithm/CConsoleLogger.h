#pragma once
#include "ILogger.h"


namespace Logger
{
	static const wchar_t* logLevel[6] = {
		L"[DEBUG]",
		L"[TRACE]",
		L"[INFO]",
		L"[WARN]",
		L"[ERROR]",
		L"[FATAL]"
	};

	class CConsoleLogger : public ILogger
	{
	public:
		CConsoleLogger() = default;

	public:
		virtual bool log(Level _level, int _threadId, const wchar_t * _file, const wchar_t * _func, int _line, const wchar_t * _msg, ...) override;
	};
}
