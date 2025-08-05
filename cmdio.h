#pragma once
#include <stdio.h>
#include <sys/ioctl.h>

#define PREFIX(name) CO_##name 
#define SPREFIX(name) co_##name // small prefix

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

int SPREFIX(kbhit)(void);
int SPREFIX(getch)(void);
void SPREFIX(clear)(void);
void SPREFIX(bgcolor)(PREFIX(Color) color);
void SPREFIX(fgcolor)(PREFIX(Color) color);
void SPREFIX(color)(PREFIX(Color) fg, PREFIX(Color) bg);
void SPREFIX(move)(size_t col, size_t row);
void SPREFIX(getpos)(size_t *x, size_t *y);
