#include <stdio.h>
#include <SDL2/SDL.h>

int main (int arg, char** args)
{
	SDL_Init(SDL_INIT_GAMECONTROLLER);

	SDL_version complied, linked;
	SDL_VERSION(&complied);
	SDL_GetVersion(&linked);

	printf("SDL2 Compiled with %d.%d.%d\n", complied.major, complied.minor, complied.patch);
	printf("SDL2 Linked with %d.%d.%d\n", linked.major, linked.minor, linked.patch);

	SDL_Quit();
	return 0;
}
