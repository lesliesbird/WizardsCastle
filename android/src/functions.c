/* BASIC functions for Wizard's Castle */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *bright, *clrs, *dim, *pad, *qpad, *sss[10], *species[4];
extern int x_axis, y_axis, z_axis, ot, dd, ss;
extern int level[512], w[15][3], master_game;

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
                printf ("%s%s", bright, s);
                }
        printf ("%s\n", dim);
        return 0;
        }

alloc_points(char *s)
{
        int i;
        char buf[10];

        do
        {
                printf ("%sHow many points added to %s? ", bright, s);
                scanf ("%s", &buf);
                printf ("%s", dim);
                i = atoi(buf);
                if ((i < 0) || (i > ot))
                        printf ("\n** ");
                }
        while ((i < 0) || (i > ot));
        ot = ot - i;
        return i;
        }

ident(void)
{
	
        printf ("\n--- You are a %s%s%s%s", bright, sss[ss], species[dd - 1], dim);
        printf (" at (%s%i%s,", bright, x_axis, dim);
        printf ("%s%i%s) LEVEL %s%i%s ---\n", bright, y_axis, dim, bright, z_axis, dim);
        return 0;
        }

splash(void)
{
	printf ("%s", clrs);
	border ("*", 52);
	printf ("\n%s%s * * * THE WIZARD'S CASTLE * * *\n", qpad, bright);
	printf ("\n%s%s%s  Reinvented: 11/20/09\n", qpad, pad, dim);
	printf ("\n%s%s%s  By: Leslie S. Bird\n\n", qpad, pad, bright);
	border ("*", 52);
	return 0;
	}

find_money(int q)
{
	int j, n, m;
	printf ("%s", bright);
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
	printf ("%s", dim);
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

