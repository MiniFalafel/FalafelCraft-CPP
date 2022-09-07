#pragma once

#include <iostream>
#include <array>

namespace FC
{
	enum LogLevel {
		LogLevelTRACE,
		LogLevelINFO,
		LogLevelWARNING,
		LogLevelERROR
	};

	class Logger
	{
	private:
		static LogLevel m_LogLevel;

		static std::array<std::string, 4> m_LogLevelColors;

	public:
		static void Init();

		static void SetLogLevel(LogLevel level);

		static void Log(const char* message, LogLevel level);
	};
}