#include "ILogger.h"

Logger::ILogger::ILogger(bool _enable, Level _level)
	: mbEnable(_enable)
	, mLevel(_level)
{
}

bool Logger::ILogger::IsEnable(Level _level) const
{
	return (mbEnable && mLevel >= _level);
}

void Logger::ILogger::SetEnable(bool _enable)
{
	mbEnable = _enable;
}
