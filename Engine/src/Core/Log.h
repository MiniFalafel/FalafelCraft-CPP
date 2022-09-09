#pragma once

#include <iostream>
#include <array>
#include <string>

namespace FC
{
	template<typename ... Args>
	static std::string format(const std::string& str, Args ... args)
	{
		int size_s = std::snprintf(nullptr, 0, str.c_str(), args ...) + 1;
		if (size_s <= 0)
		{
			throw std::runtime_error("Error during formatting.");
		}
		auto size = static_cast<size_t>(size_s);
		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, str.c_str(), args ...);
		return std::string(buf.get(), buf.get() + size - 1);
	}

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

		static void Log(std::string message, LogLevel level);
	};
}