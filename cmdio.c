#include "cmdio.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

EXPORT int cokbhit(void)
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

EXPORT int cogetch(void)
{
	return getchar();
}

#elif _WIN32
#include <conio.h>

EXPORT int cokbhit(void)
{
	return kbhit();
}

EXPORT int cogetch(void)
{
	return getch();
}
#endif

EXPORT inline void cofgcolor(CO_Color color)
{
	printf("\033[%dm", color);
}

EXPORT inline void cobgcolor(CO_Color color)
{
	printf("\033[%dm", color + 10);
}

EXPORT inline void cocolor(CO_Color fg, CO_Color bg)
{
	printf("\033[%d;%dm", fg, bg + 10);
}

EXPORT inline void coclear(void)
{
	printf("\033[1;1H\033[2J");
}

EXPORT inline void comove(size_t row, size_t col)
{
	printf("\033[%lu;%luH", row, col);
	fflush(stdout);
}

#ifdef __cplusplus
}
#endif
