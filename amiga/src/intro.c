#include <stdio.h>

intro()
{
extern char *dim, *bright, sot[128];

sprintf (sot, "\n\nMany cycles ago, in the kingdom of N'Dic, the gromic\n");
printw (sot);
sprintf (sot, "Wizard ZOT forged his great *ORB* of power.  He soon\n");
printw (sot);
sprintf (sot, "vanished, leaving behind his vast subterranean cast-\n");
printw (sot);
sprintf (sot, "le filled with esurient monsters, fabulous treasures\n");
printw (sot);
sprintf (sot, "and the incredible %s***ORB OF ZOT***%s.  From that time\n", bright, dim);
printw (sot);
sprintf (sot, "hence many a bold youth has ventured into the castle\n");
printw (sot);
sprintf (sot, "but, as of now, NONE has ever emerged victoriously!\n");
printw (sot);
sprintf (sot, "\n                      BEWARE!!\n");
printw (sot);
return 0;
}


