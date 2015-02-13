/* specialized character input */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

fancy_input(int p)
{
        int n, o;
        char c, buf;
	extern char *command[52];

        buf = getch();

        c = toupper(buf);

        o = p / 100;

        for (n = o; n <= p - o * 100; ++n)
        {
                if (c == command[n - 1][0])
                        o = n;
                }

        for (n = 1; n <= strlen(command[o - 1]) - 1; ++n)
        {
                printf ("%c", command[o - 1][n]);
                }
        printf ("\n");
        return o;
        }

