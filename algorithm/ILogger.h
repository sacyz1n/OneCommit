#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <tchar.h>
#include <stdarg.h>

#pragma comment(lib, "ws2_32.lib")

namespace Logger
{
	// Log Level
	enum class Level : unsigned short
	{
		Debug, Trace, Info, Warning, Error, Fatal
	};

	// Log Interface
	class ILogger abstract
	{
	public:
		explicit ILogger(bool _enable = true, Level _level = Level::Fatal);
		virtual ~ILogger() = default;

	private:
		Level mLevel; 
		bool  mbEnable;
			
	public:
		virtual bool log(Level _level, int _threadId, const wchar_t* _file, const wchar_t* _func, int _line, const wchar_t* _msg, ...) = 0;

		bool IsEnable(Level _level) const;
		void SetEnable(bool _enable);
	};
}


#define _LOG(logger, level, msg, ...)											 \
{																				 \
	if ((logger).IsEnable(level)) {												 \
		(logger).log(level, GetCurrentThreadId(), _T(__FILE__), _T(__FUNCTION__), __LINE__, _T(msg), ##__VA_ARGS__); \
	}																			 \
}

#define _LOG_DEBUG(logger, msg, ...)							 \
		_LOG((logger), Logger::Level::Debug, msg, ##__VA_ARGS__)

#define _LOG_TRACE(logger, msg, ...)							 \
		_LOG((logger), Logger::Level::Trace, msg, ##__VA_ARGS__)

#define _LOG_INFO(logger, msg, ...)								 \
		_LOG((logger), Logger::Level::Info, msg, ##__VA_ARGS__)

#define _LOG_WARN(logger, msg, ...)								 \
		_LOG((logger), Logger::Level::Warning, msg, ##__VA_ARGS__)

#define _LOG_ERROR(logger, msg, ...)							 \
		_LOG((logger), Logger::Level::Error, msg, ##__VA_ARGS__)

#define _LOG_FATAL(logger, msg, ...)							 \
		_LOG((logger), Logger::Level::Fatal, msg, ##__VA_ARGS__)

