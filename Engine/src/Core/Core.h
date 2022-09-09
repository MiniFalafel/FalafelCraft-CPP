#pragma once

#include "Core/Log.h"
#include <iostream>

#ifdef FC_DEBUG
#define FC_ENABLE_ASSERTS
#define FC_ENABLE_LOGGING
#endif

#ifdef FC_ENABLE_ASSERTS
#define FC_ASSERT(x, message) if(!(x)) { std::cout << "Assertion failed: " message "\n"; __debugbreak(); }
#else
#define FC_ASSERT(x, message)
#endif

#ifdef FC_ENABLE_LOGGING
#define FC_TRACE(...) FC::Logger::Log(std::string("[TRACE]: ") + FC::format(__VA_ARGS__), FC::LogLevelTRACE)
#define FC_INFO(...)  FC::Logger::Log(std::string("[INFO]: ") + FC::format(__VA_ARGS__), FC::LogLevelINFO)
#define FC_WARN(...)  FC::Logger::Log(std::string("[WARNING]: ") + FC::format(__VA_ARGS__), FC::LogLevelWARNING)
#define FC_ERROR(...) FC::Logger::Log(std::string("[ERROR]: ") + FC::format(__VA_ARGS__), FC::LogLevelERROR)
#else
#define FC_TRACE(x)
#define FC_INFO(x)
#define FC_WARN(x)
#define FC_ERROR(x)
#endif