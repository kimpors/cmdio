#include "cmdio.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int cokbhit(void)
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
#elif _WIN32
#include <conio.h>

int cokbhit(void)
{
	reutrn kbhit();
}
#endif

inline void coclear(void)
{
	printf("\e[1;1H\e[2J");
}

inline void comove(size_t row, size_t col)
{
	printf("\e[%lu;%luH", row, col);
	fflush(stdout);
}

#ifdef __cplusplus
}
#endif
