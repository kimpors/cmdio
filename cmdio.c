#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "cmdio.h"

#ifdef __cplusplus
extern "C" {
#endif

int CO_S(kbhit)(void)
{
	int ch, oldf;
	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

void CO_S(getpos)(size_t *x, size_t *y)
{
	char s[] = "\033[6n";
	write(1, s, sizeof(s));

	int oldf;
	struct termios old, new;
	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);

	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	scanf("\033[%ld,%ldR", y, x);

	tcsetattr(STDIN_FILENO, TCSANOW, &old);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
}

int CO_S(getch)(void)
{
	return getchar();
}

inline void CO_S(putch)(char ch)
{
	putchar(ch);
}

inline void CO_S(size)(struct winsize *size)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, size);
}

inline void CO_S(fgcolor)(CO(Color) color)
{
	printf("\033[%dm", color);
}

inline void CO_S(bgcolor)(CO(Color) color)
{
	printf("\033[%dm", color + 10);
}

inline void CO_S(color)(CO(Color) fg, CO(Color) bg)
{
	printf("\033[%d;%dm", fg, bg + 10);
}

inline void CO_S(clear)(void)
{
	printf("\033[1;1H\033[2J");
}

inline void CO_S(move)(size_t col, size_t row)
{
	printf("\033[%lu;%luH", row, col);
	fflush(stdout);
}

#ifdef __cplusplus
}
#endif
