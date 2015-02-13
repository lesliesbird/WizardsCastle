/*          The Wizard's Castle           */
/* written in C by Leslie S. Bird 11/2/09 */
/* original BASIC by Joseph R. Power 1980 */
/* extended by Verne R. Walrafen 2/29/84  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* global variable defines */

int level[512], c[3][4], o[3], p[16], r[3], t[8], w[15][3];
int x_axis, y_axis, z_axis, temp, master_game, dd, ee, ff, fl, gg, hh, wc, new_game;
int ah, bf, ot, tt, vf, lf, tc, rf, of, bl, ss, pf, uu, vv, ww;
int attack, isfrog, gotfrog, startnewgame, alive, done, quit, escape;

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

/* ready to begin */
while (quit == 0)
{
	
	++new_game;
	if (master_game >= 2)
	{
		printf ("\n     You are now entering the %sMASTER CLASS%s game!\n", bright, dim);
		printf ("\n%sIn the future, after selection of character,\n", pad);
		printf ("%syou may select %sMASTER CLASS%s by using commands\n", pad, bright, dim);
		printf ("%s\50%s/%s\51 and then \50%sZOT%s\51 at the Entrance.", pad, bright, dim, bright, dim);
		printf (" %sWELL DONE!%s\n", bright, dim);
		printf ("\n   A MONSTER GUARDS THE FROG THAT IS THE PRINCE%s.\n", sss[ss - 2]);
		printf ("\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
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
					printf ("\n");
					border ("-", 52);
					printf ("%s%s%s", pad, dungeon[roll_12() - 1].contents, bright);
					printf (" just ripped off%s ", dim);
					printf ("%s%s!%s\n", dungeon[17 + n].contents, bright, dim);
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
		printf ("\n");
		border ("-", 52);
		printf ("   A THIEF just stole %s%i%s", bright, n, dim);
		printf (" of your %sGOLD PIECES%s!!\n", bright, dim);
		border ("-", 52);
		}
	
	printf ("\n %s = %s%i%s", strength, bright, uu, dim);
	printf (" %s = %s%i%s", intelligence, bright, vv, dim);
	printf (" %s = %s%i%s\n", dexterity, bright, ww, dim);
	printf (" Treasures = %s%i%s", bright, tc, dim);
	printf ("  Flares = %s%i%s", bright, fl, dim);
	printf ("  Gold pieces = %s%i%s\n", bright, gg, dim);
	printf ("    Weapon = %s%s%s", bright, cause[ff], dim);
	printf ("  Armor = %s%s%s", bright, cause[ee + 4], dim);
	if (lf)
		printf ("  and a %sLAMP%s.\n", bright, dim);
	else
		printf ("\n");
	n = c[0][3] + c[1][3] + c[2][3];
	if (n)
	{
		printf ("  Curses = %s.", bright);
		for (m = 1; m <= 3; ++m)
		{
			index2 = 0;
			if (t[m * 2 - 	2])
				index2 = 3;
			if (c[m - 1][3])
				printf (".%s", curse[m + index2 - 1]);
			}
		if (n)
			printf (".%s\n", dim);
		}
	if (rf + of != 0)
	{
		printf ("  Magic implements = %s", bright);
		if (rf)
			printf ("RUNESTAFF! ");
		if (of)
			printf ("***ORB OF ZOT***!");
		printf ("\n%s", dim);
		if (pf)
		{
			printf ("  The %s%s PRINCE", bright, royal[3 * (ss - 1) - 1]);
			printf ("%s%s is at your side!\n", sss[ss - 2], dim);
			}
		}
	if (bl == 0)
	{
		i = y_axis;
		j = x_axis;
		printf ("\n");
		
		for (n = i - 1; n <= i + 1; ++n)
		{
			y_axis = below_nine(n);
			if (n == i)
				printf ("%sHere you find:   ", pad);
			else
				printf ("%s%s  ", qpad, qpad);
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
					printf ("%s", dim);
					}
				else printf ("%s", bright);
				printf ("%s%s", dungeon[index - 1].id, dim);
				printf ("  ");
				}
			if (n == i)
				printf (" %s.\n", dungeon[index2 - 1].contents);
			else
				printf ("\n");
			}
		y_axis = i;
		x_axis = j;
		}

	if (tt - (tt/500) * 500 == 0)
	{
		printf ("\n");
		border ("-", 52);
		printf ("%sYou hear a voice whisper%sZOT!%s\n", qpad, dots, bell);
		border ("-", 52);
		}
	wc = 0;
	index = func_e();
	level[func_d() - 1] = index;
	isfrog = 0;
	escape = 0;

	/* what do these rooms contain? */

	if ((index == 1) && (roll(9) == 1))
		printf ("\n%sThere are some %s eggs here.\n", pad, monster[roll(7) - 1]);

	if (((index <= 6) || (index >= 11)) && (index <= 12))
	{
	
		if (roll(6) == 1)
		{
			n = roll(35);
			isfrog = (n + 4) / 5;
			printf ("\n%s%s%sOn the floor is a%s %s!%s\n", bell, pad, bright, frog[n - 1], frog[34 + isfrog], dim);
			printf ("    ");
			border ("-", 52);
			}
		}
	if (index == 7) /* gold pieces */
	{
		printf ("\n%s  They are %s.\n", qpad, gold[roll(14) - 1]);
		index2 = index;
		index = roll(z_axis * 50);
		find_money(index);
		gg = gg + index;
		printf ("%sYou found %i gold pieces, you now have %i.\n", pad, index, gg);
		index = index2;
		level[func_d() - 1] = 1;
		}
	if (index == 8) /* flares */
	{
		index2 = roll(5);
		fl = fl + index2;
		printf ("\n%sYou found %i flares, you now have %i.\n", pad, index2, fl);
		level[func_d() - 1] = 1;
		}
	if (index == 9) /* a warp! */
	{
		if ((o[0] == x_axis) && (o[1] == y_axis) && (o[2] == z_axis) && (temp == 33) && (of == 0))
		{
			printf ("\n");
			border ("*", 52);
			printf ("%s    GREAT UNMITIGATED ZOT!\n", qpad);
			printf ("%s  YOU JUST FOUND ***THE ORB OF ZOT***!\n", pad);
			printf ("%sThe RUNESTAFF has disappeared!%s\n", qpad, bell);
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
				printf ("\n%s   You are protected by the RUNESTAFF!\n", pad);
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
		printf ("\n            %s is now yours!\n", dungeon[index - 1].contents);
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
		printf ("\nYou may (I)gnore, (A)ttack or (T)rade with VENDOR.\n");
		printf ("\nCommand #%i? ", tt);
		++tt;
		temp = fancy_input(3739);
		if (temp == 39)
		{
			printf ("\n%sYOU'LL BE SORRY THAT YOU DID THAT!\n", pad);
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
return 0;
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
			printf("\n");
			border ("-", 52);
			printf ("%sYou just received the curse of %s%s\n", pad, curse[n - 1], bell);
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
			printf ("\n%sYou ", pad);
			if (bl)
			{
				printf ("stepped on ");
				if (roll(6) == 1) printf ("some %s eggs", monster[roll(7) - 1]);
				else
				{
					n = roll(35);
					printf ("a%s %s", frog[n - 1], frog[34 + (n + 4) / 5]);
					}
				}
			else
			{
				n = roll(10);
				if (n < 6) printf ("hear ");
				if (n < 8) printf ("%s", noise[n - 1]);
				else
				{
					if (n == 8) printf ("find some crushed %s eggs", monster[roll(7) - 1]);
					}
				if (n > 8)
				{
					printf ("smell ");
					if (n == 9) printf ("%s", dungeon[roll_12() - 1].contents);
					else
					{
						printf ("something dead...%s",dungeon[roll_12() - 1].contents);
						}
					}
				}
			printf ("!\n");
			}
		if (bl + t[3] == 2)
		{
			printf ("\n%s%s%s CURES YOUR BLINDNESS!%s\n", pad, bright, dungeon[28].contents, dim);
			bl = 0;
			}
		if (bf + t[5] == 2)
		{
			printf ("\n%s%s%s DISSOLVES THE BOOK!%s\n", pad, bright, dungeon[30].contents, dim);
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
		printf ("\nCommand #%i? ", tt);
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
				printf ("\n%s** THERE ARE NO STAIRS GOING UP FROM HERE!\n", pad);
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
				printf ("\n%s** THERE ARE NO STAIRS GOING DOWN FROM HERE!\n", pad);
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
				printf ("\n%s** YOU CAN'T TELEPORT WITHOUT THE RUNESTAFF!\n", pad);
				check_events();
				}
			else
			{
				do
				{
					printf ("%sGive the room number [ W}E N}S U}D ] as XYZ: ", bright);
					scanf ("%s", &buf);
					printf ("%s", dim);
					n = atoi(buf);
					x_axis = n / 100;
					y_axis = n / 10 - 10 * x_axis;
					z_axis = n - 10 * y_axis - 100 * x_axis;
					if ((n < 111) || (n > 888)) printf ("\n%s** TRY NUMBERS FROM 111 TO 888.\n\n", pad);
					}
				while ((n < 111) || (n > 888));
				getch();
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
			printf ("\n");
			border ("*", 52);
			printf ("%s                  CONGRATULATIONS!\n", bright);
			printf ("I thought you'd never find the blasted light switch!\n");
			printf ("%sALL CASTLE ROOMS ARE NOW NICE AND BRIGHT.\n", pad);
			border ("*", 52);
			if (master_game == 0) master_game = 1;
			printf ("     The RUNESTAFF just reappeared.  Lucky %s!\n", species[dd - 1]);
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
					printf ("\n");
					border ("-", 52);
					printf ("   You must have ALL treasures to rescue PRINCE%s.\n", sss[ss - 2]);
					border ("-", 52);
					printf ("\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
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
			printf ("%s   THE %s***ORB OF POWER***%s CAN REVEAL MANY THINGS!\n", clrs, bright, dim);
			printf ("\n%sThe following commands are available:%s\n", bright, dim);
			printf ("   (C)atch  (G)aze   (L)ook   (Q)uit     (U)p\n");
			printf ("   (D)own   (H)elp   (M)ap    (R)elease  (W)est\n");
			printf ("   (E)ast   Dr(I)nk  (N)orth  (S)outh\n");
			printf ("   (F)lare  (K)iss   (O)pen   (T)eleport\n");
			printf ("\n%sThe contents of rooms are as follows:%s\n", bright, dim);
			printf ("   Empty Room(.)    (F)lares          (S)inkhole\n");
			printf ("  (B)ook            (G)old Pieces     (T)reasures\n");
			printf ("  (C)hest           (M)onster/STAFF    Stairs (U)p\n");
			printf ("   Stairs (D)own     Crystal (O)rb    (V)endor\n");
			printf ("  (E)ntrance/Exit    Magic (P)ool     (W)arp/ORB\n");
			printf ("\n%sThe magical properties of treasures are:%s\n", bright, dim);
			printf (" %s%sNo lethargy  %s%s%s.None\n", treasure[8 * t[0]], dots, treasure[8 * t[1] + 1], dots, dots);
			printf (" %s%s.No leech  %s...Blindness cure\n", treasure[8 * t[2] + 2], dots, treasure[8 * t[3] + 3]);
			printf (" %s..No forgetting  %s.Dissolve books\n", treasure[8 * t[4] + 4], treasure[8 * t[5] + 5]);
			printf (" %s%s%s..None  %s%s%s...None\n", treasure[8 * t[6] + 6], dots, dots, treasure[8 * t[7] + 7], dots, dots);
			printf ("\n   You've got the treasures shown in %sCAPITAL%s letters!\n", bright, dim);
			printf ("\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
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
		printf ("\n%s** IF YOU WANT A DRINK, FIND A POOL!\n",pad);
		check_events();
		}
	else
	{
		q = roll(8);
		printf ("\n%sYou take a drink and ", pad);
		if (q > 6)
		{
			ss = ss + 1;
			if (ss == 4) ss = 2;
			dd = roll(4);
			printf ("turn into a %s%s!\n", sss[ss], species[dd - 1]);
			}
		if (q <= 6) printf ("feel ");
		if (q == 1)
		{
			printf ("STRONGER.\n");
			uu = below_nineteen(uu + roll(3));
			}
		if (q == 2)
		{
			printf ("WEAKER.\n");
			uu = uu - roll(3);
			if (uu < 1) alive = 0;
			}
		if (q == 3)
		{
			printf ("DUMBER.\n");
			vv = vv - roll(3);
			if (vv < 1) alive = 0;
			}
		if (q == 4)
		{
			printf ("SMARTER.\n");
			vv = below_nineteen(vv + roll(3));
			}
		if (q == 5)
		{
			printf ("NIMBLER.\n");
			ww = below_nineteen(ww + roll(3));
			}
		if (q == 6)
		{
			printf ("CLUMSIER.\n");
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
	printf ("\n%sYou hold nothing kissable!\n", pad);
	isfrog = 0;
	gotfrog = 0;
	return 0;
	}

if ((isfrog == 3) && (roll(3) > 1))
{
	printf ("\n%sYou're weird!  You want a bad case of warts?\n", pad);
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
				printf ("%sYOU FOUND THE %s WITCH OF THE %s!\n", pad, sss[n / 2 + 6], sss[n]);					
				if (n < 6)
				{
					printf ("\nYou get maximum %s, %s, %s...\n", strength, intelligence, dexterity);
					uu = 18;
					vv = 18;
					ww = 18;
					ee = 3;
					ff = 3;
					gg = gg + 5000;
					printf ("also SWORD, PLATE ARMOR, and 5,000 %s!\n", gold[roll(14) - 1]);
					border ("-", 52);
					}
				else
				{
					printf ("\nYou lose the RUNESTAFF and all lights just went out!\n");
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
				printf ("%sYOU FOUND THE %s PRINCE%s.\n", pad, royal[3 * (ss - 2) + n - 1], sss[ss - 2]);
				border ("-", 52);
				if (n == 3) pf = 1;
				}
			level[3] = 2;
			w[n - 1][0] = 0;
			printf ("\n%s   Press RETURN when ready to continue, %s%s. ", bright, species[dd - 1], dim);
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
			printf ("\n%sNothing happens!\n", pad);
			isfrog  = 0;
			}
		}     
	}

if ((isfrog > 2) || (k == 1))
{
	n = roll_12();
	printf ("\n%s The %s just turned into %s!\n", pad, frog[34 + isfrog], dungeon[n - 1].contents);
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
		printf ("\n%sNothing happens!\n", pad);
		}
	else
	{
		n = roll(1000);
		find_money(n);
		printf ("For releasing me I give you %i %s!\n", n, gold[roll(14) - 1]);
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
		printf ("\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		check_events();
		}
	else
	{
		if (isfrog == 0)
		{
			printf ("\n%sThere is nothing here to catch!\n", pad);
			}
		else
		{
			if ((isfrog > 3) && (isfrog < 6))
			{
				n = 11;
				if (master_game == 2) n = 16;
				printf ("\n%sNot much challenge.  Written on the shell is...\n", pad);
				printf ("\n%s%s%s!%s\n", bright, pad, hint[roll(n) - 1], dim);
				gotfrog = 1;
				}

			if ((ww > 15) && (isfrog > 5) && (roll(3) == 1))
			{
				printf ("\n%sYou are left holding a tail in your hand!\n", pad);
				isfrog = 0;
				}

			else
			{
				if ((ww > 17) && (isfrog > 5) && (roll(2) == 1))
                                {
					printf ("\n%sWell, you caught me%sNOW WHAT?\n", pad, dots);
					gotfrog = 1;
					}

				if ((gotfrog == 0) && ((master_game < 2) || (isfrog > 5)))
				{
					printf ("\n%sThe critter simply eludes your grasp!\n", pad);
					isfrog = 0;
					}
				else
				{
					if ((isfrog > 0) && (gotfrog == 0))
					{
						printf ("\n%sWell, you caught me%sNOW WHAT?\n", pad, dots);
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
		printf ("\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		check_events();
		return 0;
		}
	ident();
	printf ("\n%s%s", pad, bright);
	for (x_axis = 1; x_axis <= 8; ++x_axis)
	{
		printf (" %i   ", x_axis);
		}
	printf ("\n\n");
	for (y_axis = 1; y_axis <= 8; ++y_axis)
	{
		printf ("  %s%i  ", bright, y_axis);
		for (x_axis = 1; x_axis <= 8; ++x_axis)
		{
			q = level[func_d() - 1];
			if (q > 99) q = 34;
			if ((x == x_axis) && (y == y_axis))
			{
				printf ("%s<%s%s%s>%s  ", dim, bright, dungeon[q - 1].id, dim, bright);
				}
			else
			{
				printf (" ");
				if (q == 34) printf ("%s", dim);
				printf ("%s%s", dungeon[q - 1].id, bright);
				printf ("   ");
				}
			}
		printf ("\n\n");
		}
	x_axis = x;
	y_axis = y;
	printf ("%s", dim);
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
		printf ("\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		check_events();
		return 0;
		}
	if (fl == 0)
	{
		printf ("\n%s** HEY, BRIGHT ONE, YOU'RE OUT OF FLARES!\n", pad);
		check_events();
		return 0;
		}
	fl = fl - 1;
	y = y_axis;
	x = x_axis;
	for (i = y - 1; i <= y + 1; ++i)
	{
		printf ("%s%s%s  ", qpad, qpad, bright);
		y_axis = below_nine(i);
		for (j = x - 1; j <= x + 1; ++j)
		{
			x_axis = below_nine(j);
			q = func_e();
			level[func_d() - 1] = q;
			if (q == 34) printf ("%s", dim);
			printf ("%s%s", dungeon[q - 1].id, bright);
			printf ("  ");
			}
		printf ("\n");
		}
	printf ("%s", dim);
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
		printf ("\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		check_events();
		return 0;
		}
	if (lf == 0)
	{
		printf ("\n%s** YOU DON'T HAVE A LAMP, %s!\n", pad, species[dd - 1]);
		check_events();
		return 0;
		}
	printf ("\nWhere do you want to shine the lamp (N,E,S,W)? ");
	i = fancy_input(1620);
	x = x_axis;
	y = y_axis;
	y_axis = below_nine(y_axis - (i == 17) + (i == 19));
	x_axis = below_nine(x_axis - (i == 20) + (i == 18));
	if (x - x_axis + y - y_axis == 0)
	{
		printf ("\n** THAT'S NOT A DIRECTION, %s!\n", species[dd - 1]);
		check_events();
		return 0;
		}
	printf ("\n%sThe lamp shines into (%i,%i) LEVEL %i.\n", pad, x_axis, y_axis, z_axis);
	level[func_d() - 1] = func_e();
	printf ("\nThere you will find %s.\n", dungeon[level[func_d() - 1] - 1].contents);
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
		printf ("\n%s** THE ONLY THING OPENED WAS YOUR BIG MOUTH!\n", pad);
		check_events();
		return 0;
		}
	if (level[func_d()- 1] == 12)
	{
		printf ("\n%sYou open the book and\n", pad);
		q = roll(6);
		switch (q)
		{
			case 2:
			printf ("%sIt's another volume of Zot's poetry! - YECH!!\n", pad);
			break;

			case 3:
			printf ("%sIt's an old copy of PLAY%s!\n", pad, species[roll(4) - 1]);
			break;

			case 4:
			printf ("%sIt's a MANUAL of %s%s%s!\n", pad, bright, dexterity, dim);
			ww = 18;
			break;

			case 5:
			printf ("%sIt's a MANUAL of %s%s%s!\n", pad, bright, strength, dim);
			uu = 18;
			break;

			case 6:
			printf ("%sthe book sticks to your hands -\n", qpad);
			printf ("%s%sNOW YOU ARE UNABLE TO DRAW YOUR WEAPON!%s\n", qpad, bright, dim);
			bf = 1;
			break;

			default:
			printf ("%s%sFLASH!%s OH NO! You are now a BLIND %s!\n", bright, pad, dim, species[dd - 1]);
			bl = 1;
			break;
			}
		level[func_d() - 1] = 1;
		check_events();
		return 0;
		}
	printf ("\n%sYou open the chest and find\n", pad);
	q = roll(4);
	switch (q)
	{
		case 2:
		printf ("%sKABOOM! IT EXPLODES!!\n", pad);
		i = roll(z_axis);
		check_damage(i);
		level[func_d() - 1] = 1;
		if ((uu < 1) || (ww < 1)) alive = 0;
		if (alive) check_events();
		break;

		case 3:
		printf ("%sGAS! You stagger from the room!\n", pad);
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
		printf ("    %i %s!  You now have %i.\n", q, gold[roll(14) - 1], gg);
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
		printf ("\n%s** YOU CAN'T SEE ANYTHING, YOU DUMB %s!\n", pad, species[dd - 1]);
		check_events();
		return 0;
		}
	if (level[func_d() - 1] != 11)
	{
		printf ("\n%s** IT'S HARD TO GAZE WITHOUT AN ORB!\n", pad);
		check_events();
		return 0;
		}
	printf ("\n%sYou see ", pad);
	if (master_game + of == 1)
	{
		printf ("a Vendor with a message!\n");
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
			printf ("%s***THE ORB OF ZOT***%s\n", bright, dim);
			printf ("%sAT (%i,%i) LEVEL %i!\n", qpad, a, b, c);
			}
		else
		{
			printf ("yourself drinking from a pool -\n");
			printf ("%sand becoming %s!\n", qpad, dungeon[roll_12() - 1].contents);
			}
		break;

		case 3:
		printf ("yourself drinking from a pool -\n");
		printf ("%sand becoming %s!\n", qpad, dungeon[roll_12() - 1].contents);
		break;

		case 4:
		printf ("%s gazing back at you!\n", dungeon[roll_12() - 1].contents);
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
		printf ("%s at (%i,%i) LEVEL %i!\n", dungeon[i - 1].contents, x_axis, y_axis, z_axis);
		x_axis = a;
		y_axis = b;
		z_axis = c;
		break;

		case 6:
		printf ("a soap opera rerun!\n");
		break;

		default:
		printf ("yourself in a BLOODY HEAP!\n");
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
	printf ("\nDo you really want to quit now? ");
	i = fancy_input(102);
	if (i != 2)
	{
		printf ("\n%s** THEN DON'T SAY THAT YOU DO!\n", pad);
		check_events();
		return 0;
		}
	splash();
	printf ("\nDo you want to save this game? ");
	i = fancy_input(102);
	if (i == 2)
	{
		printf ("%sPlease enter filename of game.%s ", bright, dim);
		scanf ("%s", &zotsav);
		getch();
		printf ("\n");
		infile = fopen (zotsav, "r");
		if (infile != NULL)
		{
			printf ("%sError. File exists, unable to save.%s\n", bright, dim);
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

	printf ("%s", clrs);
	if (master_game == 0) printf ("\n%sturning on the lights?\n", leaving);
	if ((master_game < 2) && (tc < 8)) printf ("\n%sall the treasures?\n", leaving);
	if (pf == 0) printf ("\n%sthe %s PRINCE%s? ", leaving, royal[(3 * (ss - 1)) - 1], sss[ss - 2]);
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
		printf ("\n");
		border ("*", 52);
		printf ("%sSO THAT ALL MAY KNOW OF YOUR SUCCESS%s\n", pad, dots);
		printf ("%sHere is a small wedding gift.\n");
		printf ("%s%s%s%s...the CULLINAN diamond!%s\n", bright, qpad, qpad, pad, dim);
		border ("*", 52);
		printf ("%s   Have a great life you two!\n", qpad);
		printf ("\nAre you and the %s%s PRINCE%s%s ready to leave? ", bright, royal[(3 * (ss - 1)) - 1], sss[ss - 2], dim);
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
		printf ("\n%sAt the time you died you had:\n",pad);
		}
	else
	{
		printf ("\n  You left the castle with");
		if (of == 0) printf ("out");
		printf (" the %s***ORB OF ZOT***%s.\n", bright, dim);
		if (of == 0)
		{
			printf ("\n%sA LESS THAN AWE-INSPIRING DEFEAT.\n", pad);
			printf ("\n%sWhen you left the castle, you had:\n", pad);
			}
		else
		{
			printf ("\n%sAN INCREDIBLY GLORIOUS VICTORY!!\n", pad);
			printf ("\n%sIn addition, you got out with the following:\n", pad);
			}
		}
	if (alive == 1) printf ("%syour miserable life!\n", qpad);
	for (i = 1; i <= 8; ++i)
	{
		if (t[i - 1]) printf ("%s%s%s\n", bright, qpad, dungeon[i + 24].contents);
		}
	printf ("%s%s%s and %s", dim, qpad, cause[ff], cause[ee + 4]);
	if (lf) printf (" and a lamp.");
	printf ("\n");
	printf ("\n%sYou also had %i FLARES and %i GOLD PIECES\n", pad, fl, gg);
	if (rf) printf ("%sand the RUNESTAFF\n", qpad);
	printf ("%sand it took you %i turns!\n", qpad, tt);
	printf ("\n  Are you foolish enough to re-enter the castle? ");
	i = fancy_input(304);
	if (i == 4)
	{
		printf ("\n%s%sMAYBE DUMB %s IS NOT SO DUMB AFTER ALL!%s\n", bright, pad, species[dd - 1], dim);
		done = 1;
		startnewgame = 1;
		quit = 1;
		}
	else
	{
		printf ("\n%s%s%sSOME %sS NEVER LEARN!%s\n", bright, pad, qpad, species[dd - 1], dim);
		printf ("\n     Please be patient while the castle is restocked.\n");
		initialize();
		done = 1;
		startnewgame = 1;
		}
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
			printf ("%s%s********** YOUR ARMOR HAS BEEN DESTROYED!%s\n", pad, bright, dim);
			printf ("\n%sGOOD LUCK!\n", pad);
			}
		}
	if (ww > 0) ww = ww - q / 2;
	uu = uu - q;
	return 0;
	}

