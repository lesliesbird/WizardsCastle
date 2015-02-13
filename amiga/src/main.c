/*          The Wizard's Castle           */
/* written in C by Leslie S. Bird 11/2/09 */
/* original BASIC by Joseph R. Power 1980 */
/* extended by Verne R. Walrafen 2/29/84  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <workbench/startup.h>

/* global variable defines */

int level[512], c[3][4], o[3], p[16], r[3], t[8], w[15][3];
int x_axis, y_axis, z_axis, temp, master_game, dd, ee, ff, fl, gg, hh, wc, new_game;
int ah, bf, ot, tt, vf, lf, tc, rf, of, bl, ss, pf, uu, vv, ww;
int attack, isfrog, gotfrog, startnewgame, alive, done, quit, escape, gamewin;

struct room
{
	char *contents;
	char *id;
};

struct room dungeon[34];
char *cause[8], *effect[8], *species[4], *bad_response, *gold[14], *treasure[16];
char *frog[42], *hint[16], *royal[6], *curse[6], *sss[10], *monster[7], *noise[7];
char *command[52], *pad, *qpad, *dots;
char *strength, *intelligence, *dexterity;
char *dim, *bright, *bell, *clrs;
FILE *infile, *outfile;
char sot[128];

main()
{
int index, index2, i, j, n, m, justfound = 0;

srand(time(NULL));

dim = "\33\1330m";
bright = "\33\1331m";
bell = "\7";
clrs = "\33\1332J";

/* set up constant string arrays */
defines();
new_game = 0;

initialize();
gamewin = open("RAW:0/0/480/240/The Wizard's Castle", 2, 0);
if (gamewin == -1)
{
	printf ("Error opening game window.\n");
	exit(1);
	}

/* ready to begin */
while (quit == 0)
{
	
	++new_game;
	if (master_game >= 2)
	{
		sprintf (sot, "\n     You are now entering the %sMASTER CLASS%s game!\n", bright, dim);
		printw (sot);
		sprintf (sot, "\n%sIn the future, after selection of character,\n", pad);
		printw (sot);
		sprintf (sot, "%syou may select %sMASTER CLASS%s by using commands\n", pad, bright, dim);
		printw (sot);
		sprintf (sot, "%s\50%s/%s\51 and then \50%sZOT%s\51 at the Entrance.", pad, bright, dim, bright, dim);
		printw (sot);
		sprintf (sot, " %sWELL DONE!%s\n", bright, dim);
		printw (sot);
		sprintf (sot, "\n   A MONSTER GUARDS THE FROG THAT IS THE PRINCE%s.\n", sss[ss - 2]);
		printw (sot);
		sprintf (sot, "\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
		printw (sot);
		getch();
		}

	else
	{
		if (new_game <= 1)
		{
			splash();
			intro();
			}
		}
	for (index = 1; index <= 512; ++index)
	{
		level[index - 1] = 101;
		}
	level[3] = 2;
	for (z_axis = 1; z_axis <= 7; ++z_axis)
	{
		for (n = 1; n <= 2; ++n)
		{
			index = 104;
			setup_xy(index);
			level[func_d() + 63] = 103;
			}
		}
	for (z_axis = 1; z_axis <= 8; ++z_axis)
	{
		for (index = 113; index <= 124; ++index)
		{
			setup_xy(index);
			}
		for (n = 1; n <= 3; ++n)
		{
			for (index = 105; index <= 112; ++index)
			{
				if ((index != 108) || (master_game != 2))
					setup_xy(index);
				}
			index = 125;
			setup_xy(index);
			}
		}
	if (master_game != 0)
	/* set up a master class game */
	{
		master_class();
		}
	else
	/* set up a beginner class game */
	{
		beginner_class();
		}

	while (startnewgame == 0){
	if (bl == 0) ident();

	if ((master_game >= 2) && (vv + ww <= 35))
	{
		for (n = 8; n <= 15; ++n)
		{
			if ((w[n - 1][0] == x_axis) && (w[n - 1][1] == y_axis) && (w[n - 1][2] == z_axis))
			{
				if (t[n - 8])
				{
					sprintf (sot, "\n");
					printw (sot);
					border ("-", 52);
					sprintf (sot, "%s%s%s", pad, dungeon[roll_12() - 1].contents, bright);
					printw (sot);
					sprintf (sot, " just ripped off%s ", dim);
					printw (sot);
					sprintf (sot, "%s%s!%s\n", dungeon[17 + n].contents, bright, dim);
					printw (sot);
					border ("-", 52);
					tc = tc - 1;
					t[n - 8] = 0;
					n = 16;
					}
				}
			}
		}
	
	if ((gg >= 1) && ((gg >= 20000 - master_game * 5000) || (roll(80) == 1)))
	{
		n = roll(gg / 3);
		gg = gg - n;
		printw ("\n");
		border ("-", 52);
		sprintf (sot, "   A THIEF just stole %s%i%s", bright, n, dim);
		printw (sot);
		sprintf (sot, " of your %sGOLD PIECES%s!!\n", bright, dim);
		printw (sot);
		border ("-", 52);
		}
	
	sprintf (sot, "\n %s = %s%i%s", strength, bright, uu, dim);
	printw (sot);
	sprintf (sot, " %s = %s%i%s", intelligence, bright, vv, dim);
	printw (sot);
	sprintf (sot, " %s = %s%i%s\n", dexterity, bright, ww, dim);
	printw (sot);
	sprintf (sot, " Treasures = %s%i%s", bright, tc, dim);
	printw (sot);
	sprintf (sot, "  Flares = %s%i%s", bright, fl, dim);
	printw (sot);
	sprintf (sot, "  Gold pieces = %s%i%s\n", bright, gg, dim);
	printw (sot);
	sprintf (sot, "    Weapon = %s%s%s", bright, cause[ff], dim);
	printw (sot);
	sprintf (sot, "  Armor = %s%s%s", bright, cause[ee + 4], dim);
	printw (sot);
	if (lf)
	{
		sprintf (sot, "  and a %sLAMP%s.\n", bright, dim);
		printw (sot);
		}
	else
		printw ("\n");
	n = c[0][3] + c[1][3] + c[2][3];
	if (n)
	{
		sprintf (sot, "  Curses = %s.", bright);
		printw (sot);
		for (m = 1; m <= 3; ++m)
		{
			index2 = 0;
			if (t[m * 2 - 	2])
				index2 = 3;
			if (c[m - 1][3])
			{
				sprintf (sot, ".%s", curse[m + index2 - 1]);
				printw (sot);
				}
			}
		if (n)
		{
			sprintf (sot, ".%s\n", dim);
			printw (sot);
			}
		}
	if (rf + of != 0)
	{
		sprintf (sot, "  Magic implements = %s", bright);
		printw (sot);
		if (rf)
			printw ("RUNESTAFF! ");
		if (of)
			printw ("***ORB OF ZOT***!");
		sprintf (sot, "\n%s", dim);
		printw (sot);
		if (pf)
		{
			sprintf (sot, "  The %s%s PRINCE", bright, royal[3 * (ss - 1) - 1]);
			printw (sot);
			sprintf (sot, "%s%s is at your side!\n", sss[ss - 2], dim);
			printw (sot);
			}
		}
	if (bl == 0)
	{
		i = y_axis;
		j = x_axis;
		printw ("\n");
		
		for (n = i - 1; n <= i + 1; ++n)
		{
			y_axis = below_nine(n);
			if (n == i)
			{
				sprintf (sot, "%sHere you find:   ", pad);
				printw (sot);
				}
			else
			{
				sprintf (sot, "%s%s  ", qpad, qpad);
				printw (sot);
				}
			for (m = j - 1; m <= j + 1; ++m)
			{
				x_axis = below_nine(m);
				index = level[func_d() - 1];
				if ((n == i) && (m == j))
				{
					index = func_e();
					index2 = index;
					}
				if (index >= 34)
				{
					index = 34;
					sprintf (sot, "%s", dim);
					}
				else sprintf (sot, "%s", bright);
				printw (sot);
				sprintf (sot, "%s%s", dungeon[index - 1].id, dim);
				printw (sot);
				printw ("  ");
				}
			if (n == i) sprintf (sot, " %s.\n", dungeon[index2 - 1].contents);
			else sprintf (sot, "\n");
			printw (sot);
			}
		y_axis = i;
		x_axis = j;
		}

	if (tt - (tt/500) * 500 == 0)
	{
		printw ("\n");
		border ("-", 52);
		sprintf (sot, "%sYou hear a voice whisper%sZOT!%s\n", qpad, dots, bell);
		printw (sot);
		border ("-", 52);
		}
	wc = 0;
	index = func_e();
	level[func_d() - 1] = index;
	isfrog = 0;
	escape = 0;

	/* what do these rooms contain? */

	if ((index == 1) && (roll(9) == 1))
	{
		sprintf (sot, "\n%sThere are some %s eggs here.\n", pad, monster[roll(7) - 1]);
		printw (sot);
        }

	if (((index <= 6) || (index >= 11)) && (index <= 12))
	{
	
		if (roll(6) == 1)
		{
			n = roll(35);
			isfrog = (n + 4) / 5;
			sprintf (sot, "\n%s%s%sOn the floor is a%s %s!%s\n", bell, pad, bright, frog[n - 1], frog[34 + isfrog], dim);
			printw (sot);
			printw ("    ");
			border ("-", 52);
			}
		}
	if (index == 7) /* gold pieces */
	{
		sprintf (sot, "\n%s  They are %s.\n", qpad, gold[roll(14) - 1]);
		printw (sot);
		index2 = index;
		index = roll(z_axis * 50);
		find_money(index);
		gg = gg + index;
		sprintf (sot, "%sYou found %i gold pieces, you now have %i.\n", pad, index, gg);
		printw (sot);
		index = index2;
		level[func_d() - 1] = 1;
		}
	if (index == 8) /* flares */
	{
		index2 = roll(5);
		fl = fl + index2;
		sprintf (sot, "\n%sYou found %i flares, you now have %i.\n", pad, index2, fl);
		printw (sot);
		level[func_d() - 1] = 1;
		}
	if (index == 9) /* a warp! */
	{
		if ((o[0] == x_axis) && (o[1] == y_axis) && (o[2] == z_axis) && (temp == 33) && (of == 0))
		{
			printw ("\n");
			border ("*", 52);
			sprintf (sot, "%s    GREAT UNMITIGATED ZOT!\n", qpad);
			printw (sot);
			sprintf (sot, "%s  YOU JUST FOUND ***THE ORB OF ZOT***!\n", pad);
			printw (sot);
			sprintf (sot, "%sThe RUNESTAFF has disappeared!%s\n", qpad, bell);
			printw (sot);
			justfound = 1;
			rf = 0;
			of = 1;
			o[0] = 0;
			border ("*", 52);
			level[func_d() - 1] = 1;
			check_events();
			}
		else /* fell into the warp */
		{
			if (rf)
			{
				sprintf (sot, "\n%s   You are protected by the RUNESTAFF!\n", pad);
				printw (sot);
				}
			else
			{
				x_axis = roll(8);
				y_axis = roll(8);
				z_axis = roll(8);
				sleep (3);
				}
			}
		}
	if (index == 10) /* sinkhole */
	{
		z_axis = below_nine(z_axis + 1);
		sleep (3);
		}
	if ((index > 25) && (index < 34))
	{
		sprintf (sot, "\n            %s is now yours!\n", dungeon[index - 1].contents);
		printw (sot);
		t[index - 26] = 1;
		tc = tc + 1;
		level[func_d() - 1] = 1;
		}
	if ((index > 12) && (index < 26)) /* monster */
	{
		wc = 0;
		attack = level[func_d() - 1] - 12;
		if ((attack < 13) || (vf == 1)) go_fight();
		}
	if ((index == 25) && (vf == 0)) /* vendor */
	{
		sprintf (sot, "\nYou may (I)gnore, (A)ttack or (T)rade with VENDOR.\n");
		printw (sot);
		sprintf (sot, "\nCommand #%i? ", tt);
		printw (sot);
		++tt;
		temp = fancy_input(3739);
		if (temp == 39)
		{
			sprintf (sot, "\n%sYOU'LL BE SORRY THAT YOU DID THAT!\n", pad);
			printw (sot);
			vf = 1;
			go_fight();
			}
		else
		{
			if (temp == 38) go_buy();
			}
		}
	if ((escape == 0) && (alive == 1))/* monster escape kludge */
	{
		if ((index != 10) && (index != 9)) check_events();
		if (justfound)
		{
			justfound = 0;
			process_command();
			}
		if ((index != 10) && ((index != 9) || ((index == 9) && (rf)))) process_command();
		}
	if (alive == 0) go_die();
	}

}
close (gamewin);
return 0;
}

int wbmain(struct WBStartup *wbs)
{
	main();
	}

check_events(void)
{
	int m, n, xtemp, ytemp, ztemp;

	if (c[1][3] > t[2])
	{
		gg = gg - roll(5);
		if (gg < 0) gg = 0;
		}
	if (c[2][3] > t[4])
	{
		xtemp = x_axis;
		ytemp = y_axis;
		ztemp = z_axis;
		x_axis = roll(8);
		y_axis = roll(8);
		z_axis = roll(8);
		level[func_d() - 1] = func_e() + 100;
		x_axis = xtemp;
		y_axis = ytemp;
		z_axis = ztemp;
		}
	for (n = 1; n<= 3; ++n)
	{
		m = 0;
		if ((x_axis == c[n - 1][0]) && (y_axis == c[n - 1][1]) && (z_axis == c[n - 1][2]) && (c[n - 1][3] == 0))
		{
			c[n - 1][3] = 1;
			m = 1;
			}
		if (m)
		{
			printw ("\n");
			border ("-", 52);
			sprintf (sot, "%sYou just received the curse of %s%s\n", pad, curse[n - 1], bell);
			printw (sot);
			border ("-", 52);
			}
		}
	if ((master_game == 1) && (tc == 8))
	{
		master_game = 2;
		startnewgame = 1;
		}
	else
	{
		if (roll(5) == 1)
		{
			sprintf (sot, "\n%sYou ", pad);
			printw (sot);
			if (bl)
			{
				printw ("stepped on ");
				if (roll(6) == 1) sprintf (sot, "some %s eggs", monster[roll(7) - 1]);
				else
				{
					n = roll(35);
					sprintf (sot, "a%s %s", frog[n - 1], frog[34 + (n + 4) / 5]);
					}
				printw (sot);
				}
			else
			{
				n = roll(10);
				if (n < 6)
				{
					sprintf (sot, "hear ");
					printw (sot);
					}
				if (n < 8)
				{
					sprintf (sot, "%s", noise[n - 1]);
					printw (sot);
					}
				else
				{
					if (n == 8)
					{
						sprintf (sot, "find some crushed %s eggs", monster[roll(7) - 1]);
						printw (sot);
						}
					}
				if (n > 8)
				{
					printw ("smell ");
					if (n == 9) sprintf (sot, "%s", dungeon[roll_12() - 1].contents);
					else
					{
						sprintf (sot, "something dead...%s",dungeon[roll_12() - 1].contents);
						}
					printw (sot);
					}
				}
			printw ("!\n");
			}
		if (bl + t[3] == 2)
		{
			sprintf (sot, "\n%s%s%s CURES YOUR BLINDNESS!%s\n", pad, bright, dungeon[28].contents, dim);
			printw (sot);
			bl = 0;
			}
		if (bf + t[5] == 2)
		{
			sprintf (sot, "\n%s%s%s DISSOLVES THE BOOK!%s\n", pad, bright, dungeon[30].contents, dim);
			printw (sot);
			bf = 0;
			}
		}

	return 0;
	}

process_command(void)
{
	int n;
	char buf[10];
	done = 0;

	while (done == 0)
	{
		sprintf (sot, "\nCommand #%i? ", tt);
		printw (sot);
		++tt;
		temp = fancy_input(1636);
		if (temp == 29) take_a_drink();
		if (temp == 28) kiss_frog();
		if (temp == 30) release_frog();
		if (temp == 27) catch_frog();

		if (temp == 20) /* go west or exit castle */
		{
			if (level[func_d() - 1] == 2) are_you_leaving();
			else go_move();
			}

		if ((temp == 17) || (temp == 18) || (temp == 19)) go_move();
		if (temp == 22) /* stairs up */
		{
			if (level[func_d() - 1] == 3)
			{
				z_axis = z_axis - 1;
				done = 1;
				}
			else
			{
				sprintf (sot, "\n%s** THERE ARE NO STAIRS GOING UP FROM HERE!\n", pad);
				printw (sot);
				check_events();
				}
			}

		if (temp == 23) /* stairs down */
		{
			if (level[func_d() - 1] == 4)
			{
				z_axis = z_axis + 1;
				done = 1;
				}
			else
			{
				sprintf (sot, "\n%s** THERE ARE NO STAIRS GOING DOWN FROM HERE!\n", pad);
				printw (sot);
				check_events();
				}
			}

		if (temp == 24) show_map();
		if (temp == 26) flares();
		if (temp == 21) lamp();
		if (temp == 31) open_thing();
		if (temp == 32) gaze_orb();
		if (temp == 35) save_game();
		if (temp == 33) /* teleport */
		{
			if (rf == 0)
			{
				sprintf (sot, "\n%s** YOU CAN'T TELEPORT WITHOUT THE RUNESTAFF!\n", pad);
				printw (sot);
				check_events();
				}
			else
			{
				do
				{
					sprintf (sot, "%sGive the room number [ W}E N}S U}D ] as XYZ: ", bright);
					printw (sot);
					scanw (&buf);
					sprintf (sot, "%s", dim);
					printw (sot);
					n = atoi(buf);
					x_axis = n / 100;
					y_axis = n / 10 - 10 * x_axis;
					z_axis = n - 10 * y_axis - 100 * x_axis;
					if ((n < 111) || (n > 888))
					{
						sprintf (sot, "\n%s** TRY NUMBERS FROM 111 TO 888.\n\n", pad);
						printw (sot);
						}
					}
				while ((n < 111) || (n > 888));
				done = 1;
				}
			}

		if (temp == 36) /* master class game */
		{
			of = 1;
			tc = 8;
			for (n = 1; n <= 8; ++n)
			{
				t[n - 1] = 1;
				}
			done = 1;
			}

		if ((temp == 34) && (of == 1) && (level[func_d() - 1] == 2)) /* use orb */
		{
			printw ("\n");
			border ("*", 52);
			sprintf (sot, "%s                  CONGRATULATIONS!\n", bright);
			printw (sot);
			sprintf (sot, "I thought you'd never find the blasted light switch!\n");
			printw (sot);
			sprintf (sot, "%sALL CASTLE ROOMS ARE NOW NICE AND BRIGHT.\n", pad);
			printw (sot);
			border ("*", 52);
			if (master_game == 0) master_game = 1;
			sprintf (sot, "     The RUNESTAFF just reappeared.  Lucky %s!\n", species[dd - 1]);
			printw (sot);
			rf = 1;
			sleep(3);
			for (n = 1; n <= 512; ++n)
			{
				if (level[n - 1] > 100) level[n - 1] = level[n - 1] - 100;
				}
			if (master_game != 2)
			{
				if ((master_game == 1) && (tc == 8))
				{
					master_game = 2;
					done = 1;
					startnewgame = 1;
					}
				else
				{
					printw ("\n");
					border ("-", 52);
					sprintf (sot, "   You must have ALL treasures to rescue PRINCE%s.\n", sss[ss - 2]);
					printw (sot );
					border ("-", 52);
					sprintf (sot, "\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
					printw (sot);
					getch();
					done = 1;
					}
				}
			else
			{
				done = 1;
				}
			}
		if (temp == 25) /* help */
		{
			sprintf (sot, "%s   THE %s***ORB OF POWER***%s CAN REVEAL MANY THINGS!\n", clrs, bright, dim);
			printw (sot);
			sprintf (sot, "\n%sThe following commands are available:%s\n", bright, dim);
			printw (sot);
			sprintf (sot, "   (C)atch  (G)aze   (L)ook   (Q)uit     (U)p\n");
			printw (sot);
			sprintf (sot, "   (D)own   (H)elp   (M)ap    (R)elease  (W)est\n");
			printw (sot);
			sprintf (sot, "   (E)ast   Dr(I)nk  (N)orth  (S)outh\n");
			printw (sot);
			sprintf (sot, "   (F)lare  (K)iss   (O)pen   (T)eleport\n");
			printw (sot);
			sprintf (sot, "\n%sThe contents of rooms are as follows:%s\n", bright, dim);
			printw (sot);
			sprintf (sot, "   Empty Room(.)    (F)lares          (S)inkhole\n");
			printw (sot);
			sprintf (sot, "  (B)ook            (G)old Pieces     (T)reasures\n");
			printw (sot);
			sprintf (sot, "  (C)hest           (M)onster/STAFF    Stairs (U)p\n");
			printw (sot);
			sprintf (sot, "   Stairs (D)own     Crystal (O)rb    (V)endor\n");
			printw (sot);
			sprintf (sot, "  (E)ntrance/Exit    Magic (P)ool     (W)arp/ORB\n");
			printw (sot);
			sprintf (sot, "\n%sThe magical properties of treasures are:%s\n", bright, dim);
			printw (sot);
			sprintf (sot, " %s%sNo lethargy  %s%s%s.None\n", treasure[8 * t[0]], dots, treasure[8 * t[1] + 1], dots, dots);
			printw (sot);
			sprintf (sot, " %s%s.No leech  %s...Blindness cure\n", treasure[8 * t[2] + 2], dots, treasure[8 * t[3] + 3]);
			printw (sot);
			sprintf (sot, " %s..No forgetting  %s.Dissolve books\n", treasure[8 * t[4] + 4], treasure[8 * t[5] + 5]);
			printw (sot);
			sprintf (sot, " %s%s%s..None  %s%s%s...None\n", treasure[8 * t[6] + 6], dots, dots, treasure[8 * t[7] + 7], dots, dots);
			printw (sot);
			sprintf (sot, "\n   You've got the treasures shown in %sCAPITAL%s letters!\n", bright, dim);
			printw (sot);
			sprintf (sot, "\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
			printw (sot);
			getch();
			done = 1;  
			}

		if ((temp < 17) || (temp > 36) || (temp == 34)) done = 1;
		if (alive == 0) done = 1;
		}
	return 0;
	}

take_a_drink(void)
{
	int q;
	isfrog = 0;
	gotfrog = 0;
	if (level[func_d() - 1] != 5)
	{
		sprintf (sot, "\n%s** IF YOU WANT A DRINK, FIND A POOL!\n",pad);
		printw (sot);
		check_events();
		}
	else
	{
		q = roll(8);
		sprintf (sot, "\n%sYou take a drink and ", pad);
		printw (sot);
		if (q > 6)
		{
			ss = ss + 1;
			if (ss == 4) ss = 2;
			dd = roll(4);
			sprintf (sot, "turn into a %s%s!\n", sss[ss], species[dd - 1]);
			printw (sot);
			}
		if (q <= 6) printw ("feel ");
		if (q == 1)
		{
			printw ("STRONGER.\n");
			uu = below_nineteen(uu + roll(3));
			}
		if (q == 2)
		{
			printw ("WEAKER.\n");
			uu = uu - roll(3);
			if (uu < 1) alive = 0;
			}
		if (q == 3)
		{
			printw ("DUMBER.\n");
			vv = vv - roll(3);
			if (vv < 1) alive = 0;
			}
		if (q == 4)
		{
			printw ("SMARTER.\n");
			vv = below_nineteen(vv + roll(3));
			}
		if (q == 5)
		{
			printw ("NIMBLER.\n");
			ww = below_nineteen(ww + roll(3));
			}
		if (q == 6)
		{
			printw ("CLUMSIER.\n");
			ww = ww - roll(3);
			if (ww < 1) alive = 0;
			}
		if (alive == 1) check_events();
		}	
	return 0;
	}

kiss_frog(void)
{
int n, k;
if ((gotfrog == 0) || (isfrog == 0))
{
	sprintf (sot, "\n%sYou hold nothing kissable!\n", pad);
	printw (sot);
	isfrog = 0;
	gotfrog = 0;
	return 0;
	}

if ((isfrog == 3) && (roll(3) > 1))
{
	sprintf (sot, "\n%sYou're weird!  You want a bad case of warts?\n", pad);
	printw (sot);
	return 0;
	}

if (isfrog <= 2)
{
	for (n = 1; n <= 7; ++n)
	{
		if ((w[n - 1][0] == x_axis) && (w[n - 1][1] == y_axis) && (w[n - 1][2] == z_axis))
		{
			border ("-", 52);
			if (n >= 4)
			{
				sprintf (sot, "%sYOU FOUND THE %s WITCH OF THE %s!\n", pad, sss[n / 2 + 6], sss[n]);
				printw (sot);					
				if (n < 6)
				{
					sprintf (sot, "\nYou get maximum %s, %s, %s...\n", strength, intelligence, dexterity);
					printw (sot);
					uu = 18;
					vv = 18;
					ww = 18;
					ee = 3;
					ff = 3;
					gg = gg + 5000;
					sprintf (sot, "also SWORD, PLATE ARMOR, and 5,000 %s!\n", gold[roll(14) - 1]);
					printw (sot);
					border ("-", 52);
					}
				else
				{
					sprintf (sot, "\nYou lose the RUNESTAFF and all lights just went out!\n");
					printw (sot);
					border ("-", 52);
					rf = 0;
					for (k = 1; k <= 512; ++k)
					{
						if (level[k - 1] < 99) level[k - 1] = level[k - 1] + 100;
						}
					}
				}
			else
			{
				sprintf (sot, "%sYOU FOUND THE %s PRINCE%s.\n", pad, royal[3 * (ss - 2) + n - 1], sss[ss - 2]);
				printw (sot);
				border ("-", 52);
				if (n == 3) pf = 1;
				}
			level[3] = 2;
			w[n - 1][0] = 0;
			sprintf (sot, "\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
			printw (sot);
			getch();
			done = 1;
			gotfrog = 0;
			isfrog = 0;
			return 0;
			}
		}
	if (done == 0)
	{
		gotfrog = 0;
		k = roll(5);
		if (k > 1)
		{
			sprintf (sot, "\n%sNothing happens!\n", pad);
			printw (sot);
			isfrog  = 0;
			}
		}     
	}

if ((isfrog > 2) || (k == 1))
{
	n = roll_12();
	sprintf (sot, "\n%s The %s just turned into %s!\n", pad, frog[34 + isfrog], dungeon[n - 1].contents);
	printw (sot);
	level[func_d() - 1] = n;
	attack = n - 12;
	isfrog = 0;
	go_fight();
	}
return 0;
}

release_frog(void)
{
	int n;
	if ((gotfrog != 1) || (isfrog < 6) || (roll(2) > 1))
	{
		sprintf (sot, "\n%sNothing happens!\n", pad);
		printw (sot);
		}
	else
	{
		n = roll(1000);
		find_money(n);
		sprintf (sot, "For releasing me I give you %i %s!\n", n, gold[roll(14) - 1]);
		printw (sot);
		gg = gg + n;
		isfrog = 0;
		gotfrog = 0;
		}
	return 0;			
	}

catch_frog(void)
{
	int n;
	gotfrog = 0;
	if (bl)
	{
		sprintf (sot, "\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		}
	else
	{
		if (isfrog == 0)
		{
			sprintf (sot, "\n%sThere is nothing here to catch!\n", pad);
			printw (sot);
			}
		else
		{
			if ((isfrog > 3) && (isfrog < 6))
			{
				n = 11;
				if (master_game == 2) n = 16;
				sprintf (sot, "\n%sNot much challenge.  Written on the shell is...\n", pad);
				printw (sot);
				sprintf (sot, "\n%s%s%s!%s\n", bright, pad, hint[roll(n) - 1], dim);
				printw (sot);
				gotfrog = 1;
				}

			if ((ww > 15) && (isfrog > 5) && (roll(3) == 1))
			{
				sprintf (sot, "\n%sYou are left holding a tail in your hand!\n", pad);
				printw (sot);
				isfrog = 0;
				}

			else
			{
				if ((ww > 17) && (isfrog > 5) && (roll(2) == 1))
                                {
					sprintf (sot, "\n%sWell, you caught me%sNOW WHAT?\n", pad, dots);
					printw (sot);
					gotfrog = 1;
					}

				if ((gotfrog == 0) && ((master_game < 2) || (isfrog > 5)))
				{
					sprintf (sot, "\n%sThe critter simply eludes your grasp!\n", pad);
					printw (sot);
					isfrog = 0;
					}
				else
				{
					if ((isfrog > 0) && (gotfrog == 0))
					{
						sprintf (sot, "\n%sWell, you caught me%sNOW WHAT?\n", pad, dots);
						printw (sot);
						gotfrog = 1;
						}
					}
				}
			}
		}
	return 0;
	}

show_map(void)
{
	int q, x, y;
	gotfrog = 0;
	isfrog = 0;
	x = x_axis;
	y = y_axis;

	if (bl)
	{
		sprintf (sot, "\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	ident();
	sprintf (sot, "\n%s%s", pad, bright);
	printw (sot);
	for (x_axis = 1; x_axis <= 8; ++x_axis)
	{
		sprintf (sot, " %i   ", x_axis);
		printw (sot);
		}
	printw ("\n\n");
	for (y_axis = 1; y_axis <= 8; ++y_axis)
	{
		sprintf (sot, "  %s%i  ", bright, y_axis);
		printw (sot);
		for (x_axis = 1; x_axis <= 8; ++x_axis)
		{
			q = level[func_d() - 1];
			if (q > 99) q = 34;
			if ((x == x_axis) && (y == y_axis))
			{
				sprintf (sot, "%s<%s%s%s>%s  ", dim, bright, dungeon[q - 1].id, dim, bright);
				printw (sot);
				}
			else
			{
				printw (" ");
				if (q == 34)
				{
					sprintf (sot, "%s", dim);
					printw (sot);
					}
				sprintf (sot, "%s%s", dungeon[q - 1].id, bright);
				printw (sot);
				printw ("   ");
				}
			}
		printw ("\n\n");
		}
	x_axis = x;
	y_axis = y;
	sprintf (sot, "%s", dim);
	printw (sot);
	return 0;
	}

go_move(void)
{
	gotfrog = 0;
	isfrog = 0;
	if (temp == 17) y_axis = y_axis - 1;
	if (temp == 19) y_axis = y_axis + 1;
	y_axis = below_nine(y_axis);
	if (temp == 18) x_axis = x_axis + 1;
	if (temp == 20) x_axis = x_axis - 1;
	x_axis = below_nine(x_axis);
	done = 1;
	return 0;
	}

flares(void)
{
	int i, j, q, x, y;
	gotfrog = 0;
	isfrog = 0;
	if (bl)
	{
		sprintf (sot, "\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	if (fl == 0)
	{
		sprintf (sot, "\n%s** HEY, BRIGHT ONE, YOU'RE OUT OF FLARES!\n", pad);
		printw (sot);
		check_events();
		return 0;
		}
	fl = fl - 1;
	y = y_axis;
	x = x_axis;
	for (i = y - 1; i <= y + 1; ++i)
	{
		sprintf (sot, "%s%s%s  ", qpad, qpad, bright);
		printw (sot);
		y_axis = below_nine(i);
		for (j = x - 1; j <= x + 1; ++j)
		{
			x_axis = below_nine(j);
			q = func_e();
			level[func_d() - 1] = q;
			if (q == 34)
			{
				sprintf (sot, "%s", dim);
				printw (sot);
				}
			sprintf (sot, "%s%s", dungeon[q - 1].id, bright);
			printw (sot);
			printw ("  ");
			}
		printw ("\n");
		}
	sprintf (sot, "%s", dim);
	printw (sot);
	y_axis = y;
	x_axis = x;
	check_events();
	return 0;
	}

lamp(void)
{
	int i, x, y;
	gotfrog = 0;
	isfrog = 0;
	if (bl)
	{
		sprintf (sot, "\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	if (lf == 0)
	{
		sprintf (sot, "\n%s** YOU DON'T HAVE A LAMP, %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	sprintf (sot, "\nWhere do you want to shine the lamp (N,E,S,W)? ");
	printw (sot);
	i = fancy_input(1620);
	x = x_axis;
	y = y_axis;
	y_axis = below_nine(y_axis - (i == 17) + (i == 19));
	x_axis = below_nine(x_axis - (i == 20) + (i == 18));
	if (x - x_axis + y - y_axis == 0)
	{
		sprintf (sot, "\n** THAT'S NOT A DIRECTION, %s!\n", species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	sprintf (sot, "\n%sThe lamp shines into (%i,%i) LEVEL %i.\n", pad, x_axis, y_axis, z_axis);
	printw (sot);
	level[func_d() - 1] = func_e();
	sprintf (sot, "\nThere you will find %s.\n", dungeon[level[func_d() - 1] - 1].contents);
	printw (sot);
	x_axis = x;
	y_axis = y;
	check_events();
	return 0;
	}

open_thing(void)
{
	int i, q;
	gotfrog = 0;
	isfrog = 0;
	if ((level[func_d() - 1] != 6) && (level[func_d() - 1] != 12))
	{
		sprintf (sot, "\n%s** THE ONLY THING OPENED WAS YOUR BIG MOUTH!\n", pad);
		printw (sot);
		check_events();
		return 0;
		}
	if (level[func_d()- 1] == 12)
	{
		sprintf (sot, "\n%sYou open the book and\n", pad);
		printw (sot);
		q = roll(6);
		switch (q)
		{
			case 2:
			sprintf (sot, "%sIt's another volume of Zot's poetry! - YECH!!\n", pad);
			printw (sot);
			break;

			case 3:
			sprintf (sot, "%sIt's an old copy of PLAY%s!\n", pad, species[roll(4) - 1]);
			printw (sot);
			break;

			case 4:
			sprintf (sot, "%sIt's a MANUAL of %s%s%s!\n", pad, bright, dexterity, dim);
			printw (sot);
			ww = 18;
			break;

			case 5:
			sprintf (sot, "%sIt's a MANUAL of %s%s%s!\n", pad, bright, strength, dim);
			printw (sot);
			uu = 18;
			break;

			case 6:
			sprintf (sot, "%sthe book sticks to your hands -\n", qpad);
			printw (sot);
			sprintf (sot, "%s%sNOW YOU ARE UNABLE TO DRAW YOUR WEAPON!%s\n", qpad, bright, dim);
			printw (sot);
			bf = 1;
			break;

			default:
			sprintf (sot, "%s%sFLASH!%s OH NO! You are now a BLIND %s!\n", bright, pad, dim, species[dd - 1]);
			printw (sot);
			bl = 1;
			break;
			}
		level[func_d() - 1] = 1;
		check_events();
		return 0;
		}
	sprintf (sot, "\n%sYou open the chest and find\n", pad);
	printw (sot);
	q = roll(4);
	switch (q)
	{
		case 2:
		sprintf (sot, "%sKABOOM! IT EXPLODES!!\n", pad);
		printw (sot);
		i = roll(z_axis);
		check_damage(i);
		level[func_d() - 1] = 1;
		if ((uu < 1) || (ww < 1)) alive = 0;
		if (alive) check_events();
		break;

		case 3:
		sprintf (sot, "%sGAS! You stagger from the room!\n", pad);
		printw (sot);
		sleep(3);
		i = roll(4) + 16;
		level[func_d() - 1] = 1;
		y_axis = below_nine(y_axis - (i == 17) + (i == 19));
		x_axis = below_nine(x_axis - (i == 20) + (i == 18));
		done = 1;
		break;

		default:
		q = roll(z_axis * 250);
		find_money(q);
		gg = gg + q;
		sprintf (sot, "    %i %s!  You now have %i.\n", q, gold[roll(14) - 1], gg);
		printw (sot);
		level[func_d() - 1] = 1;
		check_events();
		break;
		}
	return 0;
	}

gaze_orb(void)
{
	int a, b, c, i, q;
	gotfrog = 0;
	isfrog = 0;
	if (bl)
	{
		sprintf (sot, "\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		printw (sot);
		check_events();
		return 0;
		}
	if (level[func_d() - 1] != 11)
	{
		sprintf (sot, "\n%s** IT'S HARD TO GAZE WITHOUT AN ORB!\n", pad);
		printw (sot);
		check_events();
		return 0;
		}
	sprintf (sot, "\n%sYou see ", pad);
	printw (sot);
	if (master_game + of == 1)
	{
		sprintf (sot, "a Vendor with a message!\n");
		printw (sot);
		check_events();
		return 0;
		}
	q = roll(6);
	switch (q)
	{
		case 2:
		a = roll(8);
		b = roll(8);
		c = roll(8);
		if (roll(3) == 1)
		{
			a = o[0];
			b = o[1];
			c = o[2];
			}
		if (master_game == 0)
		{
			sprintf (sot, "%s***THE ORB OF ZOT***%s\n", bright, dim);
			printw (sot);
			sprintf (sot, "%sAT (%i,%i) LEVEL %i!\n", qpad, a, b, c);
			printw (sot);
			}
		else
		{
			sprintf (sot, "yourself drinking from a pool -\n");
			printw (sot);
			sprintf (sot, "%sand becoming %s!\n", qpad, dungeon[roll_12() - 1].contents);
			printw (sot);
			}
		break;

		case 3:
		sprintf (sot, "yourself drinking from a pool -\n");
		printw (sot);
		sprintf (sot, "%sand becoming %s!\n", qpad, dungeon[roll_12() - 1].contents);
		printw (sot);
		break;

		case 4:
		sprintf (sot, "%s gazing back at you!\n", dungeon[roll_12() - 1].contents);
		printw (sot);
		break;

		case 5:
		a = x_axis;
		b = y_axis;
		c = z_axis;
		x_axis = roll(8);
		y_axis = roll(8);
		z_axis = roll(8);
		i = func_e();
		level[func_d() - 1] = i;
		sprintf (sot, "%s at (%i,%i) LEVEL %i!\n", dungeon[i - 1].contents, x_axis, y_axis, z_axis);
		printw (sot);
		x_axis = a;
		y_axis = b;
		z_axis = c;
		break;

		case 6:
		sprintf (sot, "a soap opera rerun!\n");
		printw (sot);
		break;

		default:
		sprintf (sot, "yourself in a BLOODY HEAP!\n");
		printw (sot);
		uu = uu - roll(2);
		if (uu < 1) alive = 0;
		break;
		}
	if (alive == 1) check_events();
	return 0;
	}

save_game(void)
{
	int a, i;
	char zotsav[40];

	gotfrog = 0;
	isfrog = 0;
	sprintf (sot, "\nDo you really want to quit now? ");
	printw (sot);
	i = fancy_input(102);
	if (i != 2)
	{
		sprintf (sot, "\n%s** THEN DON'T SAY THAT YOU DO!\n", pad);
		printw (sot);
		check_events();
		return 0;
		}
	splash();
	sprintf (sot, "\nDo you want to save this game? ");
	printw (sot);
	i = fancy_input(102);
	if (i == 2)
	{
		sprintf (sot, "%sPlease enter filename of game.%s ", bright, dim);
		printw (sot);
		scanw (&zotsav);
		printw ("\n");
		infile = fopen (zotsav, "r");
		if (infile != NULL)
		{
			sprintf (sot, "%sError. File exists, unable to save.%s\n", bright, dim);
			printw (sot);
			fclose (infile);
			}
		else
		{
			outfile = fopen (zotsav, "w");
			for (i = 1; i <= 512; ++i)
			{
				fprintf (outfile, "%i\n", level[i - 1]);
				}
			for (i = 1; i <= 8; ++i)
			{
				fprintf (outfile, "%i\n", t[i - 1]);
				}
			for (i = 1; i <= 16; ++i)
			{
				fprintf (outfile, "%i\n", p[i - 1]);
				}
			for (i = 1; i <= 3; ++i)
			{
				fprintf (outfile, "%i\n", r[i - 1]);
				fprintf (outfile, "%i\n", o[i - 1]);
				for (a = 1; a <= 4; ++a)
				{
					fprintf (outfile, "%i\n", c[i - 1][a - 1]);
					}
				for (a = 1; a <= 15; ++a)
				{
					fprintf (outfile, "%i\n", w[a - 1][i - 1]);
					}
				}
			fprintf (outfile, "%i\n", ah);
			fprintf (outfile, "%i\n", bf);
			fprintf (outfile, "%i\n", bl);
			fprintf (outfile, "%i\n", dd);
			fprintf (outfile, "%i\n", ee);
			fprintf (outfile, "%i\n", ff);
			fprintf (outfile, "%i\n", fl);
			fprintf (outfile, "%i\n", gg);
			fprintf (outfile, "%i\n", hh);
			fprintf (outfile, "%i\n", lf);
			fprintf (outfile, "%i\n", master_game);
			fprintf (outfile, "%i\n", new_game);
			fprintf (outfile, "%i\n", of);
			fprintf (outfile, "%i\n", pf);
			fprintf (outfile, "%i\n", rf);
			fprintf (outfile, "%i\n", ss);
			fprintf (outfile, "%i\n", tt);
			fprintf (outfile, "%i\n", tc);
			fprintf (outfile, "%i\n", uu);
			fprintf (outfile, "%i\n", vv);
			fprintf (outfile, "%i\n", vf);
			fprintf (outfile, "%i\n", ww);
			fprintf (outfile, "%i\n", wc);
			fprintf (outfile, "%i\n", x_axis);
			fprintf (outfile, "%i\n", y_axis);
			fprintf (outfile, "%i\n", z_axis);

			fclose (outfile);
			}
		}
	end_game();
	return 0;
	}

are_you_leaving(void)
{
	int i;
	char *leaving = "     Leaving without ";
	gotfrog = 0;
	isfrog = 0;

	sprintf (sot, "%s", clrs);
	printw (sot);
	if (master_game == 0)
	{
		sprintf (sot, "\n%sturning on the lights?\n", leaving);
		printw (sot);
		}
	if ((master_game < 2) && (tc < 8))
	{
		sprintf (sot, "\n%sall the treasures?\n", leaving);
		printw (sot);
		}
	if (pf == 0)
	{
		sprintf (sot, "\n%sthe %s PRINCE%s? ", leaving, royal[(3 * (ss - 1)) - 1], sss[ss - 2]);
		printw (sot);
		}
	if (pf == 0) i = fancy_input(102);
	if (i == 1)
	{
		check_events();
		return 0;
		}
	if (pf == 0)
	{
		end_game();
		}
	else
	{
		printw ("\n");
		border ("*", 52);
		sprintf (sot, "%sSO THAT ALL MAY KNOW OF YOUR SUCCESS%s\n", pad, dots);
		printw (sot);
		sprintf (sot, "%sHere is a small wedding gift.\n");
		printw (sot);
		sprintf (sot, "%s%s%s%s...the CULLINAN diamond!%s\n", bright, qpad, qpad, pad, dim);
		printw (sot);
		border ("*", 52);
		sprintf (sot, "%s   Have a great life you two!\n", qpad);
		printw (sot);
		sprintf (sot, "\nAre you and the %s%s PRINCE%s%s ready to leave? ", bright, royal[(3 * (ss - 1)) - 1], sss[ss - 2], dim);
		printw (sot);
		i = fancy_input(102);
		if (i == 2)
		{
			end_game();
			}
		else
		{
			check_events();
			}
		}
	return 0;
	}

end_game(void)
{
	int i;
	if (alive == 0)
	{
		sprintf (sot, "\n%sAt the time you died you had:\n",pad);
		printw (sot);
		}
	else
	{
		sprintf (sot, "\n  You left the castle with");
		printw (sot);
		if (of == 0)
        {
               sprintf (sot, "out");
               printw (sot);
               }
		sprintf (sot, " the %s***ORB OF ZOT***%s.\n", bright, dim);
		printw (sot);
		if (of == 0)
		{
			sprintf (sot, "\n%sA LESS THAN AWE-INSPIRING DEFEAT.\n", pad);
			printw (sot);
			sprintf (sot, "\n%sWhen you left the castle, you had:\n", pad);
			printw (sot);
			}
		else
		{
			sprintf (sot, "\n%sAN INCREDIBLY GLORIOUS VICTORY!!\n", pad);
			printw (sot);
			sprintf (sot, "\n%sIn addition, you got out with the following:\n", pad);
			printw (sot);
			}
		}
	if (alive == 1)
	{
		sprintf (sot, "%syour miserable life!\n", qpad);
		printw (sot);
		}
	for (i = 1; i <= 8; ++i)
	{
		if (t[i - 1])
		{
			sprintf (sot, "%s%s%s\n", bright, qpad, dungeon[i + 24].contents);
			printw (sot);
			}
		}
	sprintf (sot, "%s%s%s and %s", dim, qpad, cause[ff], cause[ee + 4]);
	printw (sot);
	if (lf)
	{
		sprintf (sot, " and a lamp.");
		printw (sot);
		}
	printw ("\n");
	sprintf (sot, "\n%sYou also had %i FLARES and %i GOLD PIECES\n", pad, fl, gg);
	printw (sot);
	if (rf)
	{
		sprintf (sot, "%sand the RUNESTAFF\n", qpad);
		printw (sot);
		}
	sprintf (sot, "%sand it took you %i turns!\n", qpad, tt);
	printw (sot);
	sprintf (sot, "\n  Are you foolish enough to re-enter the castle? ");
	printw (sot);
	i = fancy_input(304);
	if (i == 4)
	{
		sprintf (sot, "\n%s%sMAYBE DUMB %s IS NOT SO DUMB AFTER ALL!%s\n", bright, pad, species[dd - 1], dim);
		printw (sot);
		done = 1;
		startnewgame = 1;
		quit = 1;
		}
	else
	{
		sprintf (sot, "\n%s%s%sSOME %sS NEVER LEARN!%s\n", bright, pad, qpad, species[dd - 1], dim);
		printw (sot);
		sprintf (sot, "\n     Please be patient while the castle is restocked.\n");
		printw (sot);
		initialize();
		done = 1;
		startnewgame = 1;
		}
	sleep(4);
	return 0;
	}

check_damage(int q)
{
	if (ee > 0)
	{
		q = q - ee;
		ah = ah - ee;
		if (q < 0)
		{
			ah = ah - q;
			q = 0;
			}
		if (ah < 0)
		{
			ah = 0;
			ee = 0;
			sprintf (sot, "%s%s********** YOUR ARMOR HAS BEEN DESTROYED!%s\n", pad, bright, dim);
			printw (sot);
			sprintf (sot, "\n%sGOOD LUCK!\n", pad);
			printw (sot);
			}
		}
	if (ww > 0) ww = ww - q / 2;
	uu = uu - q;
	return 0;
	}

