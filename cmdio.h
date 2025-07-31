#pragma once
#include <stdio.h>

#define PREFIX(name) CO_##name 
#define SPREFIX(name) co_##name // small prefix

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#elif __linux__
	#include <sys/ioctl.h>
	#define EXPORT
	EXPORT void SPREFIX(size)(struct winsize *size);
#endif

typedef enum {
	PREFIX(RESET),
	PREFIX(BLACK),
	PREFIX(RED),
	PREFIX(GREEN),
	PREFIX(YELLOW),
	PREFIX(BLUE),
	PREFIX(PINK),
	PREFIX(CYAN),
	PREFIX(WHITE)
} PREFIX(Color);

EXPORT int SPREFIX(kbhit)(void);
EXPORT int SPREFIX(getch)(void);
EXPORT void SPREFIX(clear)(void);
EXPORT void SPREFIX(bgcolor)(PREFIX(Color) color);
EXPORT void SPREFIX(fgcolor)(PREFIX(Color) color);
EXPORT void SPREFIX(color)(PREFIX(Color) fg, PREFIX(Color) bg);
EXPORT void SPREFIX(move)(size_t col, size_t row);
