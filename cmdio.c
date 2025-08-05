#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "cmdio.h"

#ifdef __cplusplus
extern "C" {
#endif

int SPREFIX(kbhit)(void)
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

void SPREFIX(getpos)(size_t *x, size_t *y)
{
	int oldf;
	struct termios old, new;
	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);

	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	char s[] = "\033[6n";

	printf("\033[6n");
	scanf("\033[%ld,%ldR", x, y);

	tcsetattr(STDIN_FILENO, TCSANOW, &old);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
}

int SPREFIX(getch)(void)
{
	return getchar();
}

inline void SPREFIX(size)(struct winsize *size)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, size);
}

inline void SPREFIX(fgcolor)(PREFIX(Color) color)
{
	printf("\033[%dm", color);
}

inline void SPREFIX(bgcolor)(PREFIX(Color) color)
{
	printf("\033[%dm", color + 10);
}

inline void SPREFIX(color)(PREFIX(Color) fg, PREFIX(Color) bg)
{
	printf("\033[%d;%dm", fg, bg + 10);
}

inline void SPREFIX(clear)(void)
{
	printf("\033[1;1H\033[2J");
}

inline void SPREFIX(move)(size_t col, size_t row)
{
	printf("\033[%lu;%luH", row, col);
	fflush(stdout);
}

#ifdef __cplusplus
}
#endif
