#pragma once

#include <iostream>

#ifdef FC_DEBUG
#define FC_ASSERT(x) if(!(x)) { std::cout << "Assertion failed!\n"; __debugbreak(); }
#elif defined FC_RELEASE
#define FC_ASSERT(x)
#endif