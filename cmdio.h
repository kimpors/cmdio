#pragma once
#include <stdio.h>

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#elif __linux__
	#define EXPORT
#endif

EXPORT int cokbhit(void);
EXPORT int cogetch(void);
EXPORT inline void coclear(void);
EXPORT inline void comove(size_t row, size_t col);
