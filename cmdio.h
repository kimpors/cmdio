#pragma once
#include <stdio.h>
#include <sys/ioctl.h>

#define PREFIX(name, object) name ## _ ## object
#define CO(object) PREFIX(CO, object)
#define CO_S(object) PREFIX(co, object)

typedef enum {
	CO(RESET),
	CO(BLACK),
	CO(RED),
	CO(GREEN),
	CO(YELLOW),
	CO(BLUE),
	CO(PINK),
	CO(CYAN),
	CO(WHITE)
} CO(Color);

int CO_S(kbhit)(void);
int CO_S(getch)(void);
void CO_S(clear)(void);
void CO_S(bgcolor)(CO(Color) color);
void CO_S(fgcolor)(CO(Color) color);
void CO_S(color)(CO(Color) fg, CO(Color) bg);
void CO_S(move)(size_t col, size_t row);
void CO_S(getpos)(size_t *x, size_t *y);
void CO_S(size)(struct winsize *size);
