/* replacement sleep function for Amiga */

#include <time.h>

sleep(int keepalive)
{
	int countdown;

	countdown = time(NULL) + keepalive;
	while (time(NULL) < countdown)
	{
		; /* hurry up and wait */
		}
	return 0;
	}

