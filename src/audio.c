#include "info.h"

void printAudioInfo()
{
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	printf("Audio Drivers\n");
	printf("\tCurrent Audio Drivers : %s\n", SDL_GetCurrentAudioDriver());
	int audio = SDL_GetNumAudioDrivers();
	for ( int i = 0; i < audio; i++ )
	{
		printf("\tAudio Driver %d : %s\n", i, SDL_GetAudioDriver( i ));
	}

	//Audio Devices
	printf("\nAudio Devices\n");
	int count = SDL_GetNumAudioDevices(0);
	for ( int i = 0; i < count; i++ )
	{
		printf("\tAudio device %d : %s\n", i, SDL_GetAudioDeviceName(i, 0));
	}

	printf("\n");
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
}