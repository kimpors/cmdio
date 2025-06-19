#pragma once
#include <stdio.h>

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#elif __linux__
	#include <sys/ioctl.h>
	#define EXPORT
	EXPORT void cosize(struct winsize *size);
#endif

typedef enum {
	CO_RESET,
	CO_BLACK = 30,
	CO_RED = 31,
	CO_GREEN = 32,
	CO_YELLOW = 33,
	CO_BLUE = 34,
	CO_PINK = 35,
	CO_CYAN = 36,
	CO_WHITE = 37,
} CO_Color;

EXPORT int cokbhit(void);
EXPORT int cogetch(void);
EXPORT void coclear(void);
EXPORT void cobgcolor(CO_Color color);
EXPORT void cofgcolor(CO_Color color);
EXPORT void cocolor(CO_Color fg, CO_Color bg);
EXPORT void comove(size_t row, size_t col);
