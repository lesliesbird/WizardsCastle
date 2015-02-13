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
extern char *dots, *frog[42], *gold[14], *sss[10], *species[4], *treasure[16];
extern char *clrs, *bad_response, *cause[8], *effect[8];
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
printf ("\n%sYou're facing %s", pad, dungeon[attack + 11].contents);
border ("!", 1 + q2 / 2);
printf ("\n%sYou may (A)ttack or (R)etreat.\n", pad);
if (q3 == 1) printf ("%sYou can also attempt a (B)ribe.\n", pad);
if (vv > 14) printf ("%sYou can also (C)ast a spell.\n", pad);
printf ("\n%sYour %s%s%s is %s%i%s", pad, bright, strength, dim, bright, uu, dim);
printf (" and your %s%s%s is %s%i%s.\n", bright, dexterity, dim, bright, ww, dim);
printf ("\nCommand #%i? ", tt);
tt = tt + 1;
i = fancy_input(4044);

switch (i)
{
	case 41:
	if (ff == 0) printf ("\n%s** POUNDING ON %s WON'T HURT IT!\n", pad, dungeon[attack +11].contents);
	else
	{
		if (bf) printf ("\n%s ** YOU CAN'T BEAT IT TO DEATH WITH A BOOK!\n", pad);

		else
		{
			if (ww < roll(20) + bl * 3) printf ("\n%sYou missed, too bad!\n", pad);
			else
			{
				printf ("\n%s%s********** YOU HIT THE EVIL ", pad, bright);
				for (j = jj; j <= strlen(ms) - 1; ++j)
				{
					printf ("%c", ms[j]);
					}
				printf ("!%s\n", dim);
				bell();
				q2 = q2 - ff;
				if (((attack == 9) || (attack == 12)) && (roll(8) == 1))
				{
					printf ("\n%s%s********** OH NO!", bright, pad);
					printf (" YOUR %s BROKE!%s\n", cause[ff], dim);
					bell();
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
		printf ("\n%s** YOU CAN'T CAST A SPELL NOW!\n", pad);
		}
	else
	{
		printf ("\nWhich spell -\n");
		printf ("%s(W)eb, (F)ireball or (D)eathspell? ", pad);
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
				printf ("\n%sIt does %i POINTS worth of damage.\n", pad, q);
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
			printf ("Death . . . ");
			if (vv < roll(4) + 15)
			{
				printf ("YOURS!\n");
				vv = 0;
				alive = 0;
				sleep(3000);
				}
			else
			{
				printf ("HIS!\n");
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
		printf ("\n%s%s       YOU HAVE ESCAPED!%s\n", bright, qpad, dim);
		do
		{
			printf ("\nDo you want to go -\n%s(N)orth, (E)ast, (S)outh or (W)est? ", pad);
			j = fancy_input(1620);
			if ((j < 17) || (j > 20)) printf ("\n%s** DON'T PRESS YOUR LUCK, %s!\n", pad, species[dd - 1]);
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
	if ((i == 40) || (q3 > 1)) printf ("\n%s\n", bad_response);
	else
	{
		if (tc == 0)
		{
			printf ("\n%sALL I WANT IS YOUR LIFE!\n", pad);
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
				printf ("\nI want %s. Will you give it to me? ", dungeon[q + 24].contents);
				j = fancy_input(102);
				if ((j != 1) && (j != 2)) printf ("\n%s\n", bad_response);
				}
			while ((j != 1) && (j != 2));
			if (j == 2)
			{
				t[q - 1] = 0;
				tc = tc - 1;
				printf ("\n%sOK, just don't tell anyone else.\n", pad);
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
		if (wc == 0) printf ("\n%sTHE WEB JUST BROKE!\n", pad);
		}
	printf ("\n%sThe ", qpad);
	for (j = jj; j <= strlen(ms) - 1; ++j)
	{
		printf ("%c", ms[j]);
		}
	if (wc > 0)
	{
		printf (" is stuck and can't attack now!\n");
		return 0;
		}
	printf (" attacks!\n");
	if (ww >= roll(7) + roll(7) + roll(7) + bl * 3)
	{
		printf ("\n%sWhat luck, he missed you!\n", qpad);
		return 0;
		}
	printf ("\n%s%s********** OUCH! HE HIT YOU!%s\n", bright, qpad, dim);
	bell();
	check_damage(q1);
	if ((uu < 1) || (ww < 1)) alive = 0;
	return 0;
	}

monster_death(void)
{
	int n, q;

	printf ("\n%s%s ", pad, dungeon[attack + 11].contents);
	printf ("lies dead at your feet!\n");
	bell();
	if (hh <= tt - 60)
	{
		printf ("\n%sYou spend an hour eating ", pad);
		printf ("%s%s.\n", dungeon[attack + 11].contents, effect[roll(8) - 1]);
		hh = tt;
		}
	if (((x_axis == r[0]) && (y_axis == r[1]) && (z_axis == r[2])) && (rf != 1))
	{
		printf ("\n");
		border ("*", 52);
		printf ("%s  GREAT ZOT! YOU'VE FOUND THE RUNESTAFF!\n", pad);
		bell();
		border ("*", 52);
		rf = 1;
		printf ("\n");
		}
	else
	{
		if (attack == 13)
		{
			printf ("\n%sYOU GET ALL HIS WARES:\n", pad);
			printf ("%sPlate Armor\n", qpad);
			ee = 3;
			ah = 21;
			printf ("%sA Sword\n", qpad);
			ff = 3;
			printf ("%sA Strength Potion\n", qpad);
			uu = below_nineteen(uu + roll(6));
			printf ("%sAn Intelligence Potion\n", qpad);
			vv = below_nineteen(vv + roll(6));
			printf ("%sA Dexterity Potion\n", qpad);
			ww = below_nineteen(ww + roll(6));
			printf ("%sA Lamp\n", qpad);
			lf = 1;
			}
		}
	q = roll(attack * 100 + z_axis * 50);
	if ((attack == 9) || (attack == 12)) q = q + 100 * (z_axis / 2);
	find_money(q);
	printf ("%sYou get his hoard of %i %s!\n", pad, q, gold[roll(14) - 1]);
	bell();
	gg = gg + q;
	if (master_game > 1)
	{
		n = roll(10);
		isfrog = (n + 4) / 5;
		printf ("\n%s%sOn the floor is a%s FROG!%s\n", pad, bright, frog[n - 1], dim);
		bell();
		printf ("    ");
		border ("-", 52);
		}
	if ((attack == 9) && (master_game + of == 1))
	{
		printf ("\n");
		border ("-",52);
		printf ("%s%sThis castle has electric power!%s\n", bright, pad, dim);
		border ("-", 52);
		}
	if ((attack == 12) && (master_game + of == 1))
	{
		printf ("\n");
		border ("-", 52);
		printf ("%s%sWhere would YOU put the light switch?%s\n", bright, pad, dim);
		border ("-", 52);
		}
	level[func_d() - 1] = 1;
	return 0;
	}

go_buy(void)
{
	int a, i, q, done_buying = 0;

	if (master_game + of == 0) printf ("\n%s%sOld ZOT thought narcissism was a BRIGHT idea.%s\n", pad, bright, dim);
	if (tc > 0)
	{
		printf ("\nDo you want purchase offers on your treasures? ");
		i = fancy_input(102);
		if (i == 2)
		{
			printf ("\n%s   Gold%s%s Highest  Last   Current Sell?\n", bright, qpad, pad);
			printf ("  Balance  Treasures    Offer   Offer   Offer   Y/N\n");
			printf ("  -------  ----------  ------- ------- ------ -----\n");
			printf ("%s", dim);
			for (q = 1;  q <= 8; ++q)
			{
				a = roll(q * 1500);
				if (t[q - 1] > 0)
				{
					if (gg < 1000) printf ("    %5i", gg);
					else printf ("   %2i,%03i", gg / 1000,  gg % 1000);
					printf ("  %s  \t", treasure[q + 7]);
					if (p[q + 7] < 1000) printf (" %5i", p[q + 7]);
					else printf ("%2i,%03i", p[q + 7] / 1000, p[q + 7] % 1000);
					if (p[q - 1] < 1000) printf ("   %5i", p[q - 1]);
					else printf ("  %2i,%03i", p[q - 1] / 1000, p[q - 1] % 1000);
					if (a < 1000) printf ("  %5i  ", a);
					else printf (" %2i,%03i  ", a / 1000, a % 1000);
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
		printf ("\n%sYOU'RE TOO POOR TO BUY ANYTHING, %s.\n", pad, species[dd - 1]);
		return 0;
		}
	if (gg >= 1250) /* buy armor or weapon */
	{
		if (((gg < 1500) && (ee == 0)) || (((gg > 1499) && (gg < 2000)) && (ee < 2)) || ((gg >= 2000) && (ee < 3)))
		{
			do
			{
				printf ("\n%sOK, %s, you have %i gold pieces\n%sand %s armor.\n", pad, species[dd - 1], gg, qpad, cause[ee + 4]);
				printf ("\nThese are the types of ARMOR you can buy:\n");
				printf ("%s(N)one ", bright);
				if (ee < 1) printf ("(L)eather-1250 ");
				if ((gg > 1499) && (ee < 2)) printf ("(C)hainmail-1500 ");
				if (gg > 1999) printf ("(P)late-2000");
				printf ("%s\n", dim);
				do
				{
					printf ("\nCommand #%i? ", tt);
					++tt;
					i = fancy_input(913);
					if ((i == 9) && (ee < 1))
					{
						gg = gg - 1250;
						ee = 1;
						ah = 7;
						done_buying = 1;
						}
					if ((i == 10) && (gg < 1500)) printf ("\n%s** YOU HAVEN'T GOT THAT MUCH CASH ON HAND!\n\n", pad);
					if (((i == 10) && (ee < 2)) && (gg > 1499))
					{
						gg = gg - 1500;
						ee = 2;
						ah = 14;
						done_buying = 1;
						}
					if ((i == 11) && (gg < 2000)) printf ("\n%s** YOU CAN'T AFFORD PLATE ARMOR!\n\n", pad);
					if ((i == 11) && (gg > 1999))
					{
						gg = gg - 2000;
						ee = 3;
						ah = 21;
						done_buying = 1;
						}
					if (i == 13) done_buying = 1;
					if ((i < 9) || (i > 13)) printf ("\n%s\n", bad_response);
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
				printf ("\n%sYou have %i gold pieces left.\n%swith %s in hand.\n", pad, gg, qpad, cause[ff]);
				printf ("\nThese are the types of WEAPON you can buy:\n");
				printf ("%s(N)one ", bright);
				if (ff < 1) printf ("(D)agger-1250 ");
				if ((gg > 1499) && (ff < 2)) printf ("(M)ace-1500 ");
				if (gg > 1999) printf ("(S)word-2000");
				printf ("%s\n", dim);
				do
				{
					printf ("\nCommand #%i? ", tt);
					++tt;
					i = fancy_input(1215);
					if ((i == 14) && (ff < 1))
					{
						gg = gg - 1250;
						ff = 1;
						done_buying = 1;
						}
					if ((i == 15) && (gg < 1500)) printf ("\n%s** SORRY, I'M AFRAID I DON'T GIVE CREDIT!\n\n", pad);
					if (((i == 15) && (ff < 2)) && (gg > 1499))
					{
						gg = gg - 1500;
						ff = 2;
						done_buying = 1;
						}
					if ((i == 12) && (gg < 2000)) printf ("\n%s** YOUR DUNGEON EXPRESS CARD -\n%s%sYOU LEFT HOME WITHOUT IT!\n", pad, qpad, pad);
					if ((i == 12) && (gg > 1999))
					{
						gg = gg - 2000;
						ff = 3;
						done_buying = 1;
						}
					if (i == 13) done_buying = 1;
					if ((i < 12) || (i > 15)) printf ("\n%s\n", bad_response);
					}
				while ((i < 12) || (i > 15));
				}
			while (done_buying == 0);
			}
		done_buying = 0;
		}
	if ((gg > 999) && (uu + vv + ww < 54)) printf ("\nDo you want to buy some -\n");
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
		printf ("\nDo you want a lamp for 1,000 gold pieces? ");
		i = fancy_input(102);
		if (i == 2)
		{
			printf ("\n%sIt's guaranteed to outlive you!\n", pad);
			gg = gg - 1000;
			lf = 1;
			}
		}
	return 0;
	}

buy_points(char *z, int n)
{
	int i;

	printf ("%s ( now %i )\t", z, n);
	printf ("for 1,000 (of %2i,%03i)? ", gg / 1000, gg % 1000);
	i = fancy_input(102);
	return i;
	}

go_die(void)
{
	int i;

	border ("*", 52);
	printf ("%s\n%sA noble effort, oh formerly living %s!\n", clrs, pad, species[dd - 1]);
	bell();
	printf ("\n%sYou died due to lack of", pad);
	if (uu < 1)
	{
		printf (" %s", strength);
		uu = 8;
		}
	if (vv < 1)
	{
		printf (" %s", intelligence);
		vv = 8;
		}
	if (ww < 1)
	{
		printf (" %s", dexterity);
		ww = 8;
		}
	printf (".\n");
	printf ("\nDo you want me to attempt to REINCARNATE you? ");
	i = fancy_input(304);
	if (i == 4)
	{
		end_game();
		return 0;
		}
	printf ("\n");
	border ("-", 52);
	printf ("%s%s  OK, don't blame me if it doesn't work!\n", bright, pad);
	if (roll(3) > 1)
	{
		printf ("\n%s%s    Well I'll be%s%sIT WORKED!%s\n", dim, qpad, dots, bright, dim);
		ss = roll(2) + 1;
		dd = roll(4);
		x_axis = roll(8);
		y_axis = roll(8);
		z_axis = roll(8);
		bl = 1;
		printf ("\n  Sorry, but you came back as a %sBLIND %s%s!%s\n", bright, sss[ss], species[dd - 1], dim);
		border ("-", 52);
		alive = 1;
		check_events();
		}
	else
	{
		printf ("\n%s   Oh well, at least I tried!\n", qpad);
		border ("-", 52);
		end_game();
		}
	return 0;
	}

