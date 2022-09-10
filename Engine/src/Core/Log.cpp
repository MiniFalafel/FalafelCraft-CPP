#include "Log.h"

namespace FC
{

	void Logger::Init()
	{
		std::cout.flush();
	}

	void Logger::SetLogLevel(LogLevel level) { m_LogLevel = level; }

	void Logger::Log(std::string message, LogLevel level)
	{
		if (level > m_LogLevel - 1)
			std::cout << m_LogLevelColors[level] << message << "\x1b[0m\n";
	}

	LogLevel Logger::m_LogLevel = LogLevelTRACE;
	std::array<std::string, 4> Logger::m_LogLevelColors =
	{
		"\x1b[38;2;228;228;228m", // TRACE
		"\x1b[38;2;128;255;128m", // INFO
		"\x1b[38;2;255;255;128m", // WARNING
		"\x1b[38;2;255;128;128m"  // ERROR
	};
}