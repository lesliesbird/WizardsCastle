/* BASIC functions for Wizard's Castle */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *bright, *clrs, *dim, *pad, *qpad, *sss[10], *species[4], sot[128];
extern int x_axis, y_axis, z_axis, ot, dd, ss;
extern int level[512], w[15][3], master_game, gamewin;

roll(int s)
{
	return (rand() % s) + 1;
	}

below_nine(int s)
{
	if (s == 9) s = 1;
	if (s == 0) s = 8;
	return s;
	}

below_nineteen(int s)
{
	if (s > 18) s = 18;
	return s;
	}

func_d(void)
{
	return ((64 * (z_axis - 1)) + (8 * (x_axis - 1)) + y_axis);
	}

func_e(void)
{
	int i = 0;

	if (level[func_d() - 1] > 99) i = -1;
	return (level[func_d() - 1] + 100 * i);
	}

roll_12(void)
{
	return (roll(12) + 12);
	}

setup_xy(int s)
{	
	do
	{
		x_axis = roll(8);
		y_axis = roll(8);
		}
	while ((level[func_d() - 1] != 101) || ((x_axis == z_axis) && (y_axis == z_axis)));
	level[func_d() - 1] = s;
	return 0;
	}

border(char *s, int a)
{
        int i;

        for (i = 1; i <= a; ++i)
        {
                sprintf (sot, "%s%s", bright, s);
                printw (sot);
                }
        sprintf (sot, "%s\n", dim);
        printw (sot);
        return 0;
        }

alloc_points(char *s)
{
        int i;
        char buf[10];

        do
        {
                sprintf (sot, "%sHow many points added to %s? ", bright, s);
                printw (sot);
                scanw (&buf);
                sprintf (sot, "%s", dim);
                printw (sot);
                i = atoi(buf);
                if ((i < 0) || (i > ot))
                        sprintf (sot, "\n** ");
                        printw (sot);
                }
        while ((i < 0) || (i > ot));
        ot = ot - i;
        return i;
        }

ident(void)
{
	
        sprintf (sot, "\n--- You are a %s%s%s%s", bright, sss[ss], species[dd - 1], dim);
        printw (sot);
        sprintf (sot, " at (%s%i%s,", bright, x_axis, dim);
        printw (sot);
        sprintf (sot, "%s%i%s) LEVEL %s%i%s ---\n", bright, y_axis, dim, bright, z_axis, dim);
        printw (sot);
        return 0;
        }

splash(void)
{
	sprintf (sot, "%s", clrs);
	printw (sot);
	border ("*", 52);
	sprintf (sot, "\n%s%s * * * THE WIZARD'S CASTLE * * *\n", qpad, bright);
	printw (sot);
	sprintf (sot, "\n%s%s%s  Reinvented: 11/20/09\n", qpad, pad, dim);
	printw (sot);
	sprintf (sot, "\n%s%s%s  By: Leslie S. Bird\n\n", qpad, pad, bright);
	printw (sot);
	border ("*", 52);
	return 0;
	}

find_money(int q)
{
	int j, n, m;
	sprintf (sot, "%s", bright);
	printw (sot);
	j = q / 500;
	n = (q - (j * 500) - 1) / 10 + 1;
	border ("@", n);
	n = 50;
	if (j)
	{
		for (m = 1; m <= j; ++m)
		{
			border ("@", 50);
			}
		}
	sprintf (sot, "%s", dim);
	printw (sot);
	return 0;
	}

initialize(void)
{
	int m, n;

	master_game = 0;

	for (n = 1; n <= 15; ++n)
	{
		for (m = 1; m <= 3; ++m)
		{
			w[n - 1][m - 1] = 0;
			}
		}
	return 0;
	}

