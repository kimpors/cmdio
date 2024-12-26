#include "cmdio.h"

#ifdef __cplusplus
extern "C" {
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
