/* fight, buy or death routines */

#include <stdio.h>
#include <string.h>

struct room
{
	char *contents;
	char *id;
};

extern struct room dungeon[34];
extern int ah, ee, ff, gg, hh, lf, tc, vf, uu, vv, ww, dd, ss, bl, isfrog, level[512];
extern int c[3][4], p[16], r[3], t[8], attack, alive, x_axis, y_axis, z_axis;
extern int bf, tt, rf, of, wc, master_game, escape;
extern char *strength, *intelligence, *dexterity, *bright, *dim, *pad, *qpad;
extern char *dots, *bell, *frog[42], *gold[14], *sss[10], *species[4], *treasure[16];
extern char *clrs, *bad_response, *cause[8], *effect[8], sot[128];
int q1, q3, jj;
char ms[30];

go_fight(void)
{
int i, j, q, q2;

int fighting = 1;

q1 = 1 + attack / 2;
q2 = attack + 4 + z_axis / 2 + 2 * master_game;
q3 = 1;
strcpy (ms, dungeon[attack + 11].contents);
jj = 2;
if (ms[2] == ' ') jj = 3;

if ((c[0][3] > t[0]) || (bl) || (ww < roll(9) + roll(9))) monster_attack();

while (fighting == 1) /* while still fighting*/
{
sprintf (sot, "\n%sYou're facing %s", pad, dungeon[attack + 11].contents);
printw (sot);
border ("!", 1 + q2 / 2);
sprintf (sot, "\n%sYou may (A)ttack or (R)etreat.\n", pad);
printw (sot);
if (q3 == 1)
{
	sprintf (sot, "%sYou can also attempt a (B)ribe.\n", pad);
	printw (sot);
	}
if (vv > 14)
{
	sprintf (sot, "%sYou can also (C)ast a spell.\n", pad);
	printw (sot);
	}
sprintf (sot, "\n%sYour %s%s%s is %s%i%s", pad, bright, strength, dim, bright, uu, dim);
printw (sot);
sprintf (sot, " and your %s%s%s is %s%i%s.\n", bright, dexterity, dim, bright, ww, dim);
printw (sot);
sprintf (sot, "\nCommand #%i? ", tt);
printw (sot);
tt = tt + 1;
i = fancy_input(4044);

switch (i)
{
	case 41:
	if (ff == 0)
	{
		sprintf (sot, "\n%s** POUNDING ON %s WON'T HURT IT!\n", pad, dungeon[attack +11].contents);
		printw (sot);
		}
	else
	{
		if (bf)
		{
			sprintf (sot, "\n%s ** YOU CAN'T BEAT IT TO DEATH WITH A BOOK!\n", pad);
			printw (sot);
			}
		else
		{
			if (ww < roll(20) + bl * 3)
			{
				sprintf (sot, "\n%sYou missed, too bad!\n", pad);
				printw (sot);
				}
			else
			{
				sprintf (sot, "\n%s%s********** YOU HIT THE EVIL ", pad, bright);
				printw (sot);
				for (j = jj; j <= strlen(ms) - 1; ++j)
				{
					sprintf (sot, "%c", ms[j]);
					printw (sot);
					}
				sprintf (sot, "!%s%s\n", dim, bell);
				printw (sot);
				q2 = q2 - ff;
				if (((attack == 9) || (attack == 12)) && (roll(8) == 1))
				{
					sprintf (sot, "\n%s%s********** OH NO!", bright, pad);
					printw (sot);
					sprintf (sot, " YOUR %s BROKE!%s%s\n", cause[ff], dim, bell);
					printw (sot);
					ff = 0;
					}
				if (q2 <= 0)
				{
					monster_death();
					fighting = 0;
					}
				}
			}
		}
	if (fighting == 1) monster_attack();
	break;

	case 43:
	if (vv < 15)
	{
		sprintf (sot, "\n%s** YOU CAN'T CAST A SPELL NOW!\n", pad);
		printw (sot);
		}
	else
	{
		sprintf (sot, "\nWhich spell -\n");
		printw (sot);
		sprintf (sot, "%s(W)eb, (F)ireball or (D)eathspell? ", pad);
		printw (sot);
		j = fancy_input(4047);
		if (j == 47)
		{
			uu = uu - 1;
			wc = roll(8) + 1;
			if (uu < 1) alive = 0;
			}
		if (j == 46)
		{
			q = roll(7) + roll(7);
			uu = uu - 1;
			vv = vv - 1;
			if ((uu < 1) || (vv < 1)) alive = 0;
			else
			{
				sprintf (sot, "\n%sIt does %i POINTS worth of damage.\n", pad, q);
				printw (sot);
				q2 = q2 - q;
				if (q2 <= 0)
				{
					monster_death();
					fighting = 0;
					}
				}
			}
		if (j == 45)
		{
			printw ("Death . . . ");
			if (vv < roll(4) + 15)
			{
				printw ("YOURS!\n");
				vv = 0;
				alive = 0;
				sleep(3);
				}
			else
			{
				printw ("HIS!\n");
				q2 = 0;
				monster_death();
				fighting = 0;
				}
			}
		if ((alive == 1) && (fighting == 1)) monster_attack();
		}
	break;

	case 44:
	monster_attack();
	if (alive == 1)
	{
		sprintf (sot, "\n%s%s       YOU HAVE ESCAPED!%s\n", bright, qpad, dim);
		printw (sot);
		do
		{
			sprintf (sot, "\nDo you want to go -\n%s(N)orth, (E)ast, (S)outh or (W)est? ", pad);
			printw (sot);
			j = fancy_input(1620);
			if ((j < 17) || (j > 20))
			{
				sprintf (sot, "\n%s** DON'T PRESS YOUR LUCK, %s!\n", pad, species[dd - 1]);
				printw (sot);
				}
			}
		while ((j < 17) || (j > 20));

		if (j == 17) y_axis = y_axis - 1;
		if (j == 19) y_axis = y_axis + 1;
		y_axis = below_nine(y_axis);
		if (j == 18) x_axis = x_axis + 1;
		if (j == 20) x_axis = x_axis - 1;
		x_axis = below_nine(x_axis);
		escape = 1;
		}
	fighting = 0;
	break;

	default:
	if ((i == 40) || (q3 > 1))
	{
		sprintf (sot, "\n%s\n", bad_response);
		printw (sot);
		}
	else
	{
		if (tc == 0)
		{
			sprintf (sot, "\n%sALL I WANT IS YOUR LIFE!\n", pad);
			printw (sot);
			monster_attack();
			}
		else
		{
			j = 0;
			do
			{
				do
				{
					q = roll(8);
					}
				while (t[q - 1] == 0);
				sprintf (sot, "\nI want %s. Will you give it to me? ", dungeon[q + 24].contents);
				printw (sot);
				j = fancy_input(102);
				if ((j != 1) && (j != 2))
				{
					sprintf (sot, "\n%s\n", bad_response);
					printw (sot);
					}
				}
			while ((j != 1) && (j != 2));
			if (j == 2)
			{
				t[q - 1] = 0;
				tc = tc - 1;
				sprintf (sot, "\n%sOK, just don't tell anyone else.\n", pad);
				printw (sot);
				vf = vf - (level[func_d() - 1] == 25);
				fighting = 0;
				}
			else monster_attack();				
			}
		}
	break;
	}
if (alive == 0) fighting = 0;
}
return 0;
}

monster_attack(void)
{
	int j;
	q3 = 2;
	if (wc > 0)
	{
		wc = wc - 1;
		if (wc == 0)
		{
			sprintf (sot, "\n%sTHE WEB JUST BROKE!\n", pad);
			printw (sot);
			}
		}
	sprintf (sot, "\n%sThe ", qpad);
	printw (sot);
	for (j = jj; j <= strlen(ms) - 1; ++j)
	{
		sprintf (sot, "%c", ms[j]);
		printw (sot);
		}
	if (wc > 0)
	{
		printw (" is stuck and can't attack now!\n");
		return 0;
		}
	printw (" attacks!\n");
	if (ww >= roll(7) + roll(7) + roll(7) + bl * 3)
	{
		sprintf (sot, "\n%sWhat luck, he missed you!\n", qpad);
		printw (sot);
		return 0;
		}
	sprintf (sot, "\n%s%s********** OUCH! HE HIT YOU!%s%s\n", bright, qpad, dim, bell);
	printw (sot);
	check_damage(q1);
	if ((uu < 1) || (ww < 1)) alive = 0;
	return 0;
	}

monster_death(void)
{
	int n, q;

	sprintf (sot, "\n%s%s ", pad, dungeon[attack + 11].contents);
	printw (sot);
	sprintf (sot, "lies dead at your feet!%s\n", bell);
	printw (sot);
	if (hh <= tt - 60)
	{
		sprintf (sot, "\n%sYou spend an hour eating ", pad);
		printw (sot);
		sprintf (sot, "%s%s.\n", dungeon[attack + 11].contents, effect[roll(8) - 1]);
		printw (sot);
		hh = tt;
		}
	if (((x_axis == r[0]) && (y_axis == r[1]) && (z_axis == r[2])) && (rf != 1))
	{
		printw ("\n");
		border ("*", 52);
		sprintf (sot, "%s  GREAT ZOT! YOU'VE FOUND THE RUNESTAFF!%s\n", pad, bell);
		printw (sot);
		border ("*", 52);
		printw ("\n");
		rf = 1;
		}
	else
	{
		if (attack == 13)
		{
			sprintf (sot, "\n%sYOU GET ALL HIS WARES:\n", pad);
			printw (sot);
			sprintf (sot, "%sPlate Armor\n", qpad);
			printw (sot);
			ee = 3;
			ah = 21;
			sprintf (sot, "%sA Sword\n", qpad);
			printw (sot);
			ff = 3;
			sprintf (sot, "%sA Strength Potion\n", qpad);
			printw (sot);
			uu = below_nineteen(uu + roll(6));
			sprintf (sot, "%sAn Intelligence Potion\n", qpad);
			printw (sot);
			vv = below_nineteen(vv + roll(6));
			sprintf (sot, "%sA Dexterity Potion\n", qpad);
			printw (sot);
			ww = below_nineteen(ww + roll(6));
			sprintf (sot, "%sA Lamp\n", qpad);
			printw (sot);
			lf = 1;
			}
		}
	q = roll(attack * 100 + z_axis * 50);
	if ((attack == 9) || (attack == 12)) q = q + 100 * (z_axis / 2);
	find_money(q);
	sprintf (sot, "%sYou get his hoard of %i %s!%s\n", pad, q, gold[roll(14) - 1], bell);
	printw (sot);
	gg = gg + q;
	if (master_game > 1)
	{
		n = roll(10);
		isfrog = (n + 4) / 5;
		sprintf (sot, "\n%s%s%sOn the floor is a%s FROG!%s\n", bell, pad, bright, frog[n - 1], dim);
		printw (sot);
		printw ("    ");
		border ("-", 52);
		}
	if ((attack == 9) && (master_game + of == 1))
	{
		printw ("\n");
		border ("-",52);
		sprintf (sot, "%s%sThis castle has electric power!%s\n", bright, pad, dim);
		printw (sot);
		border ("-", 52);
		}
	if ((attack == 12) && (master_game + of == 1))
	{
		printw ("\n");
		border ("-", 52);
		sprintf (sot, "%s%sWhere would YOU put the light switch?%s\n", bright, pad, dim);
		printw (sot);
		border ("-", 52);
		}
	level[func_d() - 1] = 1;
	return 0;
	}

go_buy(void)
{
	int a, i, q, done_buying = 0;

	if (master_game + of == 0)
	{
		sprintf (sot, "\n%s%sOld ZOT thought narcissism was a BRIGHT idea.%s\n", pad, bright, dim);
		printw (sot);
		}
	if (tc > 0)
	{
		sprintf (sot, "\nDo you want purchase offers on your treasures? ");
		printw (sot);
		i = fancy_input(102);
		if (i == 2)
		{
			sprintf (sot, "\n%s   Gold%s%s Highest  Last   Current Sell?\n", bright, qpad, pad);
			printw (sot);
			sprintf (sot, "  Balance  Treasures    Offer   Offer   Offer   Y/N\n");
			printw (sot);
			sprintf (sot, "  -------  ----------  ------- ------- ------ -----\n");
			printw (sot);
			sprintf (sot, "%s", dim);
			printw (sot);
			for (q = 1;  q <= 8; ++q)
			{
				a = roll(q * 1500);
				if (t[q - 1] > 0)
				{
					if (gg < 1000) sprintf (sot, "    %5i", gg);
					else sprintf (sot, "   %2i,%03i", gg / 1000,  gg % 1000);
					printw (sot);
					sprintf (sot, "  %s  \t", treasure[q + 7]);
					printw (sot);
					if (p[q + 7] < 1000) sprintf (sot, " %5i", p[q + 7]);
					else sprintf (sot, "%2i,%03i", p[q + 7] / 1000, p[q + 7] % 1000);
					printw (sot);
					if (p[q - 1] < 1000) sprintf (sot, "   %5i", p[q - 1]);
					else sprintf (sot, "  %2i,%03i", p[q - 1] / 1000, p[q - 1] % 1000);
					printw (sot);
					if (a < 1000) sprintf (sot, "  %5i  ", a);
					else sprintf (sot, " %2i,%03i  ", a / 1000, a % 1000);
					printw (sot);
					i = fancy_input(102);
					if (i == 2)
					{
						tc = tc - 1;
						t[q - 1] = 0;
						gg = gg + a;
						}
					p[q - 1] = a;
					if (a > p[q + 7]) p[q + 7] = a;
					}
				if (gg > 20000) break;
				}
			}
		}				
	if (gg < 1000)
	{
		sprintf (sot, "\n%sYOU'RE TOO POOR TO BUY ANYTHING, %s.\n", pad, species[dd - 1]);
		printw (sot);
		return 0;
		}
	if (gg >= 1250) /* buy armor or weapon */
	{
		if (((gg < 1500) && (ee == 0)) || (((gg > 1499) && (gg < 2000)) && (ee < 2)) || ((gg >= 2000) && (ee < 3)))
		{
			do
			{
				sprintf (sot, "\n%sOK, %s, you have %i gold pieces\n%sand %s armor.\n", pad, species[dd - 1], gg, qpad, cause[ee + 4]);
				printw (sot);
				sprintf (sot, "\nThese are the types of ARMOR you can buy:\n");
				printw (sot);
				sprintf (sot, "%s(N)one ", bright);
				printw (sot);
				if (ee < 1)
				{
					sprintf (sot, "(L)eather-1250 ");
					printw (sot);
					}
				if ((gg > 1499) && (ee < 2))
				{
					sprintf (sot, "(C)hainmail-1500 ");
					printw (sot);
					}
				if (gg > 1999)
				{
					sprintf (sot, "(P)late-2000");
					printw (sot);
					}
				sprintf (sot, "%s\n", dim);
				printw (sot);
				do
				{
					sprintf (sot, "\nCommand #%i? ", tt);
					printw (sot);
					++tt;
					i = fancy_input(913);
					if ((i == 9) && (ee < 1))
					{
						gg = gg - 1250;
						ee = 1;
						ah = 7;
						done_buying = 1;
						}
					if ((i == 10) && (gg < 1500))
					{
						sprintf (sot, "\n%s** YOU HAVEN'T GOT THAT MUCH CASH ON HAND!\n\n", pad);
						printw (sot);
						}
					if (((i == 10) && (ee < 2)) && (gg > 1499))
					{
						gg = gg - 1500;
						ee = 2;
						ah = 14;
						done_buying = 1;
						}
					if ((i == 11) && (gg < 2000))
					{
						sprintf (sot, "\n%s** YOU CAN'T AFFORD PLATE ARMOR!\n\n", pad);
						printw (sot);
						}
					if ((i == 11) && (gg > 1999))
					{
						gg = gg - 2000;
						ee = 3;
						ah = 21;
						done_buying = 1;
						}
					if (i == 13) done_buying = 1;
					if ((i < 9) || (i > 13))
					{
						sprintf (sot, "\n%s\n", bad_response);
						printw (sot);
						}
					}
				while ((i < 9) || (i > 13));
				}
			while (done_buying == 0);
			}
		done_buying = 0;
		if (((gg < 1500) && (ff == 0)) || (((gg > 1499) && (gg < 2000)) && (ff < 2)) || ((gg >= 2000) && (ff < 3)))
		{
			do
			{
				sprintf (sot, "\n%sYou have %i gold pieces left.\n%swith %s in hand.\n", pad, gg, qpad, cause[ff]);
				printw (sot);
				sprintf (sot, "\nThese are the types of WEAPON you can buy:\n");
				printw (sot);
				sprintf (sot, "%s(N)one ", bright);
				printw (sot);
				if (ff < 1)
				{
					sprintf (sot, "(D)agger-1250 ");
					printw (sot);
					}
				if ((gg > 1499) && (ff < 2))
				{
					sprintf (sot, "(M)ace-1500 ");
					printw (sot);
					}
				if (gg > 1999)
				{
					sprintf (sot, "(S)word-2000");
					printw (sot);
					}
				sprintf (sot, "%s\n", dim);
				printw (sot);
				do
				{
					sprintf (sot, "\nCommand #%i? ", tt);
					printw (sot);
					++tt;
					i = fancy_input(1215);
					if ((i == 14) && (ff < 1))
					{
						gg = gg - 1250;
						ff = 1;
						done_buying = 1;
						}
					if ((i == 15) && (gg < 1500))
					{
						sprintf (sot, "\n%s** SORRY, I'M AFRAID I DON'T GIVE CREDIT!\n\n", pad);
						printw (sot);
						}
					if (((i == 15) && (ff < 2)) && (gg > 1499))
					{
						gg = gg - 1500;
						ff = 2;
						done_buying = 1;
						}
					if ((i == 12) && (gg < 2000))
					{
						sprintf (sot, "\n%s** YOUR DUNGEON EXPRESS CARD -\n%s%sYOU LEFT HOME WITHOUT IT!\n", pad, qpad, pad);
						printw (sot);
						}
					if ((i == 12) && (gg > 1999))
					{
						gg = gg - 2000;
						ff = 3;
						done_buying = 1;
						}
					if (i == 13) done_buying = 1;
					if ((i < 12) || (i > 15))
					{
						sprintf (sot, "\n%s\n", bad_response);
						printw (sot);
						}
					}
				while ((i < 12) || (i > 15));
				}
			while (done_buying == 0);
			}
		done_buying = 0;
		}
	if ((gg > 999) && (uu + vv + ww < 54))
	{
		sprintf (sot, "\nDo you want to buy some -\n");
		printw (sot);
		}
	if ((gg > 999) && (uu < 18))
	{
		do
		{
			i = buy_points(strength, uu);
			if (i == 2)
			{
				gg = gg - 1000;
				uu = below_nineteen(uu + roll(6));
				}
			}
		while ((uu < 18) && (gg > 999) && (i == 2));
		}
	if ((gg > 999) && (vv < 18))
	{
		do
		{
			i = buy_points(intelligence, vv);
			if (i == 2)
			{
				gg = gg - 1000;
				vv = below_nineteen(vv + roll(6));
				}
			}
		while ((vv < 18) && (gg > 999) && (i == 2));
		}
	if ((gg > 999) && (ww < 18))
	{
		do
		{
			i = buy_points(dexterity, ww);
			if (i == 2)
			{
				gg = gg - 1000;
				ww = below_nineteen(ww + roll(6));
				}
			}
		while ((ww < 18) && (gg > 999) && (i == 2));
		}
	if ((gg > 999) && (lf == 0))
	{
		sprintf (sot, "\nDo you want a lamp for 1,000 gold pieces? ");
		printw (sot);
		i = fancy_input(102);
		if (i == 2)
		{
			sprintf (sot, "\n%sIt's guaranteed to outlive you!\n", pad);
			printw (sot);
			gg = gg - 1000;
			lf = 1;
			}
		}
	return 0;
	}

buy_points(char *z, int n)
{
	int i;

	sprintf (sot, "%s ( now %i )\t", z, n);
	printw (sot);
	sprintf (sot, "for 1,000 (of %2i,%03i)? ", gg / 1000, gg % 1000);
	printw (sot);
	i = fancy_input(102);
	return i;
	}

go_die(void)
{
	int i;

	border ("*", 52);
	sprintf (sot, "%s\n%sA noble effort, oh formerly living %s!%s\n", clrs, pad, species[dd - 1], bell);
	printw (sot);
	sprintf (sot, "\n%sYou died due to lack of", pad);
	printw (sot);
	if (uu < 1)
	{
		sprintf (sot, " %s", strength);
		printw (sot);
		uu = 8;
		}
	if (vv < 1)
	{
		sprintf (sot, " %s", intelligence);
		printw (sot);
		vv = 8;
		}
	if (ww < 1)
	{
		sprintf (sot, " %s", dexterity);
		printw (sot);
		ww = 8;
		}
	printw (".\n");
	printw ("\nDo you want me to attempt to REINCARNATE you? ");
	i = fancy_input(304);
	if (i == 4)
	{
		end_game();
        return 0;
		}
	printw ("\n");
	border ("-", 52);
	sprintf (sot, "%s%s  OK, don't blame me if it doesn't work!\n", bright, pad);
	printw (sot);
	if (roll(3) > 1)
	{
		sprintf (sot, "\n%s%s    Well I'll be%s%sIT WORKED!%s\n", dim, qpad, dots, bright, dim);
		printw (sot);
		ss = roll(2) + 1;
		dd = roll(4);
		x_axis = roll(8);
		y_axis = roll(8);
		z_axis = roll(8);
		bl = 1;
		sprintf (sot, "\n  Sorry, but you came back as a %sBLIND %s%s!%s\n", bright, sss[ss], species[dd - 1], dim);
		printw (sot);
		border ("-", 52);
		alive = 1;
		check_events();
		}
	else
	{
		sprintf (sot, "\n%s   Oh well, at least I tried!\n", qpad);
		printw (sot);
		border ("-", 52);
		end_game();
		}
	return 0;
	}

