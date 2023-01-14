#include <string.h>
#include <3ds.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main()
{
	gfxInitDefault();
	//gfxSet3D(true); //Uncomment if using stereoscopic 3D
	consoleInit(GFX_TOP, NULL); //Change this line to consoleInit(GFX_BOTTOM, NULL) if using the bottom screen.

	//var
	int speedX = 0;
        int speedY = 12;

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		//Your code goes here

		u32 kDown = hidKeysDown();
		if (kDown & KEY_RIGHT)
                {
                        printf("\e[1;1H\e[2J");
                        speedX++;
                        gotoxy(speedX, speedY);
                        printf("#");
                }

		if (kDown & KEY_LEFT)
                {
                        printf("\e[1;1H\e[2J");
                        speedX--;
                        gotoxy(speedX, speedY);
                        printf("#");
                }

		if (kDown & KEY_A)
                {
                        printf("\e[1;1H\e[2J");
                        speedY++;
                        gotoxy(speedX, speedY);
                        printf("#");

			printf("\e[1;1H\e[2J");
                        speedY++;
                        gotoxy(speedX, speedY);
                        printf("#");

			printf("\e[1;1H\e[2J");
                        speedY++;
                        gotoxy(speedX, speedY);
                        printf("#");

			printf("\e[1;1H\e[2J");
                        speedY++;
                        gotoxy(speedX, speedY);
                        printf("#");

			printf("\e[1;1H\e[2J");
                        speedY--;
                        gotoxy(speedX, speedY);
                        printf("#");

			 printf("\e[1;1H\e[2J");
                        speedY--;
                        gotoxy(speedX, speedY);
                        printf("#");

			 printf("\e[1;1H\e[2J");
                        speedY--;
                        gotoxy(speedX, speedY);
                        printf("#");

			 printf("\e[1;1H\e[2J");
                        speedY--;
                        gotoxy(speedX, speedY);
                        printf("#");
                }

		if (speedX == 12)
		{
			gotoxy(0,0);
			printf("You won!");
		}




		if (kDown & KEY_START)
			break; //Break in order to return to hbmenu

		// Flush and swap frame-buffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
