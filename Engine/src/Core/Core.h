#pragma once

#include <iostream>

#ifdef FC_DEBUG
#define FC_ASSERT(x, message) if(!(x)) { std::cout << "Assertion failed:\n    " << message << '\n'; __debugbreak(); }
#elif defined FC_RELEASE
#define FC_ASSERT(x)
#endif