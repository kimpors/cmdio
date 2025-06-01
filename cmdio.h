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
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	PINK = 35,
	CYAN = 36,
	WHITE = 37,
} CO_Color;

EXPORT int cokbhit(void);
EXPORT int cogetch(void);
EXPORT void coclear(void);
EXPORT void cobgcolor(CO_Color color);
EXPORT void cofgcolor(CO_Color color);
EXPORT void cocolor(CO_Color fg, CO_Color bg);
EXPORT void comove(size_t row, size_t col);
