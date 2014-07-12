#include <stdio.h>
#include <SDL2/SDL.h>
#include "info.h"

int main (int arg, char** args)
{
	SDL_Init(SDL_INIT_GAMECONTROLLER);

	SDL_version complied, linked;
	SDL_VERSION(&complied);
	SDL_GetVersion(&linked);

	printf("Compiled with SDL2 version : %d.%d.%d\n", complied.major, complied.minor, complied.patch);
	printf("Running with SDL2 version : %d.%d.%d\n", linked.major, linked.minor, linked.patch);


	printSysInfo();
	printCPUInfo();
	printBatteryInfo();
	printHints();
	printDisplayInfo();
	printVideoInfo();
	printJoyStickInfo();
	printAudioInfo();

	SDL_Quit();
	return 0;
}
