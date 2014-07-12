#include "info.h"

void printDisplayInfo()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	printf("Display Info\n");

	printf("\tNumber of Displays : %d\n", SDL_GetNumVideoDisplays());

	printf("\n");

	for( int i = 0; i < SDL_GetNumVideoDisplays(); i++ )
	{

		printf("\tDisplay Index : %d\n" ,i );
		printf("\tDisplay Name  : %s\n", SDL_GetDisplayName(i));

		SDL_DisplayMode desk;
		SDL_GetDesktopDisplayMode( i , &desk );

		SDL_Rect rect;
		SDL_GetDisplayBounds( i , &rect );
		printf("\tDesktop Display Position : { %d , %d }\n", rect.x, rect.y);

		printf("\tNative Display Resolution : %dx%d\n" , desk.w, desk.h);
		printf("\tNative Display Refresh : %dhz\n", desk.refresh_rate);
		printf("\tNative Display Format : ");
		switch ( desk.format )
		{
			case ( SDL_PIXELFORMAT_RGB888 ):
				printf("RGB-888\n");
				break;
			case ( SDL_PIXELFORMAT_RGB565 ):
				printf("RGB-565\n");
				break;
			default:
				printf("%d", desk.format);
				break;
		}
		printf("\n");
		for ( int n = 0; n < SDL_GetNumDisplayModes( i ); n++ )
		{
			SDL_DisplayMode dm;
			SDL_GetDisplayMode( i , n , &dm );
			printf("\tDisplay Mode : %d\n",n);
			printf("\tDisplay Resolution : %dx%d\n", dm.w, dm.h);
			printf("\tDisplay Refresh : %dhz\n", dm.refresh_rate);
			printf("\tDisplay Format : ");
			switch ( dm.format )
			{
				case ( SDL_PIXELFORMAT_RGB888 ):
					printf("RGB-888\n");
					break;
				case ( SDL_PIXELFORMAT_RGB565 ):
					printf("RGB-565\n");
					break;
				default:
					printf("%d",desk.format);
					break;
			}
			printf("\n");
		}
		printf("\n");
	}
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void printVideoInfo()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	printf("Video Info\n");

	printf("\tCurrent Video Driver : %s\n", SDL_GetCurrentVideoDriver());
	int vid_drivers = SDL_GetNumVideoDrivers();
	for ( int n = 0; n < vid_drivers; n++ )
	{
		printf("\tAvailable Video Driver %d : %s\n", n, SDL_GetVideoDriver(n));
	}
	printf("\n");
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}