#include "info.h"

void printBatteryInfo()
{
	printf("\nBattery Info\n");

	int secs  = 0, pct = 0;
	SDL_PowerState state = SDL_GetPowerInfo( &secs , &pct );
	switch ( state )
	{
		case ( SDL_POWERSTATE_ON_BATTERY ):
			printf("\tBattery Status : Discharging %d%% %dmins\n", pct , secs / 60 );
			break;
		case ( SDL_POWERSTATE_CHARGING ):
			printf( "\tBattery Status : Charging %d%% %dmins\n", pct , secs / 60);
			break;
		case ( SDL_POWERSTATE_CHARGED ):
			printf( "\tBattery Status : Charged %d%% %dmins\n", pct , secs / 60 );
			break;
		case ( SDL_POWERSTATE_NO_BATTERY ):
			printf( "\tBattery Status : No Battery\n");
			break;
		case ( SDL_POWERSTATE_UNKNOWN ):
			printf( "\tBattery Status : Unknown\n");
	}
}