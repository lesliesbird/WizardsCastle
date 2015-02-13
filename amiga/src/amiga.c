/* amiga functions for window i/o */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int gamewin;

getch(void)
{
	char c;
	read (gamewin, &c, 1);
	return c;
	}

printw(char *s)
{
	write (gamewin, s, strlen(s));
	return 0;
	}
  
scanw(char s[128])
{
	char c;
	int i = 0;
	while (c != 13)
	{
		read (gamewin, &c, 1);
		if (c != 8) write (gamewin, &c, 1);
		else
		if (i > 0) write (gamewin, "\10 \10", 3);
		if (c != 13)
		{
			if (c != 8)
			{
				s[i] = c;
				++i;
				}
			else
			{
				if (i > 0) i = i - 1;
				s[i] = '\0';
				}
			}
		}
	s[i] = '\0';
	printw ("\n");
	return s;
	}

