/* read character from console input */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr (STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr (STDIN_FILENO, TCSANOW, &newt);

	ch = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldt);

	return ch;
	}
