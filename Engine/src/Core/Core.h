#pragma once

#include "Core/Log.h"
#include <iostream>

#ifdef FC_DEBUG
#define FC_ENABLE_ASSERTS
#define FC_ENABLE_LOGGING
#endif

#ifdef FC_ENABLE_ASSERTS
#define FC_ASSERT(x, message) if(!(x)) { std::cout << "Assertion failed:\n    " << message << '\n'; __debugbreak(); }
#else
#define FC_ASSERT(x, message)
#endif

#ifdef FC_ENABLE_LOGGING
#define FC_TRACE(x) FC::Logger::Log("[TRACE]: " x, FC::LogLevelTRACE)
#define FC_INFO(x)  FC::Logger::Log("[INFO]: " x, FC::LogLevelINFO)
#define FC_WARN(x)  FC::Logger::Log("[WARNING]: " x, FC::LogLevelWARNING)
#define FC_ERROR(x) FC::Logger::Log("[ERROR]: " x, FC::LogLevelERROR)
#else
#define FC_TRACE(x)
#define FC_INFO(x)
#define FC_WARN(x)
#define FC_ERROR(x)
#endif