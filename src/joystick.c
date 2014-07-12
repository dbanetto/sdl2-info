#include "info.h"

void printJoyStickInfo()
{
	SDL_InitSubSystem(SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER);
	printf("Joystick Info\n");
	int num_joy;
	num_joy = SDL_NumJoysticks();
	printf("\t%d JoyStick%c found\n\n", num_joy, (num_joy == 1 ? '\0' : 's'));
	for( int i = 0; i < num_joy; i++ )
	{
		SDL_Joystick* joystick = SDL_JoystickOpen(i);
		printf("\tName : %s\n", SDL_JoystickName(joystick));
		printf("\tJoyStick Name : %s\n" , SDL_JoystickNameForIndex(i));
		printf("\tIs Game Controller : %s\n" , BOOL(SDL_IsGameController(i)));
		printf("\tNumber of Axes : %d\n" , SDL_JoystickNumAxes(joystick));
		printf("\tNumber of Buttons : %d\n" , SDL_JoystickNumButtons(joystick));
		printf("\tNumber of Balls : %d\n" , SDL_JoystickNumBalls(joystick));
		printf("\tNumber of Hats : %d\n" , SDL_JoystickNumHats(joystick));

		SDL_JoystickGUID guid = SDL_JoystickGetDeviceGUID(i);
		printf("\tGUID:");
		for ( int k = 0; k < 16; k++ )
		{
			printf("%x", guid.data[k]);
			if ( k % 4 == 0 && k != 0 )
			{
				printf("-");
			}
		}
		printf("\n");
		SDL_JoystickClose( joystick );
		if ( SDL_IsGameController( i ) == SDL_TRUE )
		{
			printf("\tController Type : %s\n" , SDL_GameControllerNameForIndex( i ) );
		}
		printf("\n");
	}

	SDL_QuitSubSystem(SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER);
}