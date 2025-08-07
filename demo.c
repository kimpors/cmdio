#include "cmdio.h"

static size_t x;
static size_t y;

int main(void)
{
	co_getpos(&x, &y);

	printf("x: %ld, y: %ld", x, y);
	return 0;
}
