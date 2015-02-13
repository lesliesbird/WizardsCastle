/* set up games for master and beginner classes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *cause[8], *effect[8], *species[4], *bad_response, *gold[14], *treasure[16];
extern char *frog[42], *hint[16], *royal[6], *curse[6], *sss[10], *monster[7], *noise[7];
extern char *command[52], *pad, *qpad, *dots;
extern char *strength, *intelligence, *dexterity;

extern int level[512], c[3][4], o[3], p[16], r[3], t[8], w[15][3];
extern int x_axis, y_axis, z_axis, temp, master_game, dd, ee, ff, fl, gg, hh, wc, new_game, alive, quit;
extern int ah, bf, ot, tt, vf, lf, tc, rf, of, bl, vv, ss, pf, uu, vv, ww, startnewgame;
extern char *dim, *bright, *bell;
extern FILE *infile, *outfile;

master_class(void)
{

int n, m;
startnewgame = 0;
alive = 1;
quit = 0;

for (n = 1; n <= 512; ++n)
{
	if (level[n - 1] > 99) level[n - 1] = level[n - 1] - 100;
	}

for (n = 1; n <= 7; ++n)
{
	do
	{
		x_axis = roll(8);
		y_axis = roll(8);
		z_axis = roll(8);

		for (m = 1; m <= n; ++m)
		{
			if ((w[m - 1][0] == x_axis) && (w[m - 1][1] == y_axis) && (w[m - 1][2] == z_axis))
			{
				x_axis = roll(8);
				y_axis = roll(8);
				z_axis = roll(8);
				m = 1;
				}
			}
		}
        while (((level[func_d() - 1] < 13) || (level[func_d() - 1] > 24)) || ((x_axis == z_axis) && (y_axis == z_axis)));

	w[n - 1][0] = x_axis;
	w[n - 1][1] = y_axis;
	w[n - 1][2] = z_axis;
	}

for (n = 8; n <= 15; ++n)
{
	x_axis = roll(8);
	y_axis = roll(8);
	z_axis = roll(8);
	
	for (m = 1; m <= n; ++m)
	{
		if ((w[m - 1][0] == x_axis) && (w[m - 1][1] == y_axis) && (w[m - 1][2] == z_axis))
		{
			
			x_axis = roll(8);
			y_axis = roll(8);
			z_axis = roll(8);
			m = 1;
			}
		}
	w[n - 1][0] = x_axis;
	w[n - 1][1] = y_axis;
	w[n - 1][2] = z_axis;
	}

x_axis = 1;
y_axis = 4;
z_axis = 1;

return 0;
}

beginner_class(void)
{
int a, i;
char buf[10], zotsav[40];

startnewgame = 0;
alive = 1;
quit = 0;

for (i = 126; i <= 133; ++i)
{
	z_axis = roll(8);
	setup_xy(i);
	}
i = roll_12() + 100;
z_axis = roll(8);
setup_xy(i);

r[0] = x_axis;
r[1] = y_axis;
r[2] = z_axis;

i = 109;
z_axis = roll(8);
setup_xy(i);

o[0] = x_axis;
o[1] = y_axis;
o[2] = z_axis;

i = 101;

for (a = 1; a <= 3; ++a)
{
	z_axis = roll(8);
	setup_xy(i);
	c[a - 1][0] = x_axis;
	c[a - 1][1] = y_axis;
	c[a - 1][2] = z_axis;
	c[a - 1][3] = 0;
	}
bf = 0;
ot = 8;
tt = 1;
vf = 0;
lf = 0;
tc = 0;
gg = 60;
rf = 0;
of = 0;
bl = 0;
vv = 8;
ss = 0;
pf = 0;

for (i = 1; i <= 8; ++i)
{
	p[i - 1] = 0;
	p[i + 7] = 0;
	t[i - 1] = 0;
	}

printf ("\n\nIs this an (O)ld game continued or a (N)ew game? ");
temp = fancy_input(5152);
if (temp == 52)
{
	printf ("%sPlease enter filename of game.%s ", bright, dim);
	scanf ("%s", &zotsav);
	getch();
	infile = fopen (zotsav, "r");
	if (infile == NULL)
	{
		printf ("%sError. Unable to load file!%s\n", bright, dim);
		exit(1);
		}
	for (i = 1; i <= 512; ++i)
	{
		fscanf (infile, "%i", &level[i - 1]);
		}
	for (i = 1; i <= 8; ++i)
	{
		fscanf (infile, "%i", &t[i - 1]);
		}
	for (i = 1; i <= 16; ++i)
	{
		fscanf (infile, "%i", &p[i - 1]);
		}
	for (i = 1; i <= 3; ++i)
	{
		fscanf (infile, "%i", &r[i - 1]);
		fscanf (infile, "%i", &o[i - 1]);
		for (a = 1; a <= 4; ++a)
		{
			fscanf (infile, "%i", &c[i - 1][a - 1]);
			}
		for (a = 1; a <= 15; ++a)
		{
			fscanf (infile, "%i", &w[a - 1][i - 1]);
			}
		}
	fscanf (infile, "%i", &ah);
	fscanf (infile, "%i", &bf);
	fscanf (infile, "%i", &bl);
	fscanf (infile, "%i", &dd);
	fscanf (infile, "%i", &ee);
	fscanf (infile, "%i", &ff);
	fscanf (infile, "%i", &fl);
	fscanf (infile, "%i", &gg);
	fscanf (infile, "%i", &hh);
	fscanf (infile, "%i", &lf);
	fscanf (infile, "%i", &master_game);
	fscanf (infile, "%i", &new_game);
	fscanf (infile, "%i", &of);
	fscanf (infile, "%i", &pf);
	fscanf (infile, "%i", &rf);
	fscanf (infile, "%i", &ss);
	fscanf (infile, "%i", &tt);
	fscanf (infile, "%i", &tc);
	fscanf (infile, "%i", &uu);
	fscanf (infile, "%i", &vv);
	fscanf (infile, "%i", &vf);
	fscanf (infile, "%i", &ww);
	fscanf (infile, "%i", &wc);
	fscanf (infile, "%i", &x_axis);
	fscanf (infile, "%i", &y_axis);
	fscanf (infile, "%i", &z_axis);

	fclose (infile);
	}	
else
{
	splash();
	printf ("%sOnly shaded questions require use of the RETURN key!\n", bell);
	dd = 2;
	uu = 6;
	ww = 10;
	printf ("\nAll right, bold one.\n");
	printf ("%sYou may be (D)warf, (E)lf, Hu(M)an or (H)obbit.\n", pad);
	printf ("\nCommand #%i? ", tt);
	++tt;
	temp = fancy_input(508);

	if (temp == 6)
	{
		dd = 4;
		uu = 10;
		ww = 6;
		}
	if (temp == 7)
	{
		dd = 3;
		uu = 8;
		ww = 8;
		}
	if (temp == 8)
	{
		dd = 1;
		uu = 4;
		ww = 12;
		ot = 4;
		}
	while (temp < 49)
	{
		printf ("\nWhich sex do you prefer? ");
		temp = fancy_input(4850);
		if (temp == 48)
			printf ("\n%s** CUTE %s, REAL CUTE. TRY M OR F.\n", pad, species[dd - 1]);
		}
	if (temp == 50)
		ss = 2;
	if (temp == 49)
		ss = 3;

	printf ("\nOK, %s, you have the following attributes:\n", species[dd - 1]);
	printf ("%s%s = %i %s = %i %s = %i\n", pad, strength, uu, intelligence, vv, dexterity, ww);
	printf ("%sand %i other points to allocate as you wish.\n\n", pad, ot);
	
	uu = uu + alloc_points(strength);
	if (ot > 0)
		vv = vv + alloc_points(intelligence);
	if (ot > 0)
	{
		ww = ww + alloc_points(dexterity);
		if (ot > 0)
			ww = ww + ot;
		}
	getch();
	printf ("\nOK, %s, you have 60 gold pieces.\n", species[dd - 1]);	
	fl = 0;
	wc = 0;
	printf ("\nThese are the types of ARMOR you can buy:\n");
	printf ("%s(N)one (L)eather-10 (C)hainmail-20 (P)late-30\n", pad);
	printf ("\nCommand #%i? ", tt);
	++tt;
	temp = fancy_input(913);
	
	if (temp == 13)
		ee = 0;
	if (temp == 9)
		ee = 1;
	if (temp == 10)
		ee = 2;
	if (temp == 11)
		ee = 3;

	gg = gg - ee * 10;
	ah = ee * 7;
	printf ("\nOK, bold %s, you have %i gold pieces left.\n", species[dd - 1], gg);
	printf ("\nThese are the types of WEAPONS you can buy:\n");
	printf ("%s(N)one (D)agger-10 (M)ace-20 (S)word-30\n",pad);
	printf ("\nCommand #%i? ", tt);
	++tt;
	temp = fancy_input(1215);

	if (temp == 12)
		ff = 3;
	if (temp == 13)
		ff = 0;
	if (temp == 14)
		ff = 1;
	if (temp == 15)
		ff = 2;

	gg = gg - ff * 10;

	if (gg > 19)
	{
		printf ("\nDo you want a lamp for 20 gold pieces? ");
		tt = 8;
		temp = fancy_input(102);
		if (temp == 2)
		{
			lf = 1;
			gg = gg - 20;
			}
		}
	if (gg >= 1)
	{
		printf ("\nOK, %s, you have %i gold pieces left.\n", species[dd - 1], gg);
		tt = 9;
		do
		{
			printf ("\nFlares cost 1 gold piece each.\n");
			printf ("          %sHow many do you want? ", bright);
			scanf ("%s", &buf);
			printf ("%s", dim);
			temp = atoi(buf);
			if (temp > gg)
				printf ("\n%s** YOU CAN ONLY AFFORD %i.\n", pad, gg);
			}
		while (temp > gg);
		getch();
		if (temp < 0)
			temp = 0;
		fl = fl + temp;
		gg = gg - temp;
		}

	splash();
	x_axis = 1;
	y_axis = 4;
	z_axis = 1;
	printf ("\n%sOK, %s, You are now entering the castle!\n\n", pad, species[dd - 1]);

	border ("-", 52);
	printf ("\n   The HELP menu is reached using (H)elp command.\n");
	printf ("%s   Castle level numbers increase as you go DOWN!%s\n\n", bright, dim);
	border ("-", 52);
	printf ("\n%s   Press RETURN when ready to continue, %s. ", bright, species[dd - 1]);
	getch();
	printf ("%s", dim);
	}

return 0;
}

