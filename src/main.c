#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "info.h"
#define VERSION "1.0.0a"

enum PrintFlag {
	INFO_SYS  = 1,
	INFO_CPU  = 2,
	INFO_BAT  = 4,
	INFO_HINT = 8,
	INFO_VID  = 16,
	INFO_JOY  = 32,
	INFO_AUD  = 64
};
#define DEFAULT_INFO INFO_SYS + INFO_CPU + INFO_BAT + INFO_VID + INFO_JOY + INFO_AUD

void printInfo (int flag);
void toLower (char* str);
void printHelp();

int main (int arg, char** args)
{
	SDL_Init(SDL_INIT_GAMECONTROLLER);

	printf("SDL2 Info Version : %s\n" , VERSION);
	int infoflag = 0;
	for (int i = 0; i < arg; i++)
	{
		toLower(args[i]);
		
		if (strcmp(args[i] , "-s") == 0 || strcmp(args[i] , "--system") == 0 )
			infoflag |= INFO_SYS;
		
		if (strcmp(args[i] , "-c") == 0 || strcmp(args[i] , "--cpu") == 0 )
			infoflag |= INFO_CPU;
		
		if (strcmp(args[i] ,  "-b") == 0 || strcmp(args[i] , "--battery") == 0 )
			infoflag |= INFO_BAT;
		
		if (strcmp(args[i] ,"-h") == 0 || strcmp(args[i] , "--hints") == 0 )
			infoflag |= INFO_HINT;
		
		if (strcmp(args[i] , "-d") == 0 || strcmp(args[i] , "--display") == 0 )
			infoflag |= INFO_VID;
		
		if (strcmp(args[i] , "-j") == 0 || strcmp(args[i] , "--joystick") == 0 )
			infoflag |= INFO_JOY;
		
		if (strcmp(args[i] , "-a") == 0 || strcmp(args[i] , "--audio") == 0 )
			infoflag |= INFO_AUD;

		if (strcmp(args[i] , "--help") == 0)
		{
			printHelp();
			return 0;
		}
	}
	if (infoflag == 0)
		infoflag = DEFAULT_INFO;

	printInfo(infoflag);

	SDL_Quit();
	return 0;
}

void toLower (char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void printHelp()
{
	printf("SDL2 Info is a tool to print all the information available through the SDL2 API\n");

	printf("\n");

	printf("Possible Arguments\n");
	printf("\t-s, --system    Prints basic system info\n");
	printf("\t-c, --cpu       Prints CPU feature list\n");
	printf("\t-b, --battery   Prints basic battery info\n");
	printf("\t-h, --hints     Prints SDL2 hint list with values\n");
	printf("\t-d, --display   Prints monitor's display info\n");
	printf("\t-j, --joystick  Prints joystick/controller(s) info\n");
	printf("\t-a, --audio     Prints audio info\n");

	printf("\n");

	printf("Example\n");
	printf("\tsdl2-info -s -b --joystick : prints system, battery and joystick info\n");
	
	printf("\n");

	printf("Default is equivalent to:\n");
	printf("\tsdl2-info -s -c -b -d -j -a\n");
}

void printInfo (int flag)
{
	SDL_version complied, linked;
	SDL_VERSION(&complied);
	SDL_GetVersion(&linked);

	printf("Using SDL2 version : %d.%d.%d\n", linked.major, linked.minor, linked.patch);
	printf("Built with SDL2 version : %d.%d.%d\n", complied.major, complied.minor, complied.patch);
	if (complied.major != linked.major || complied.minor != linked.minor || complied.patch != linked.patch)
	{
		printf("The built and the running SDL2 versions are different. Some features may not be available\n");
	}


	if (flag & INFO_SYS)
	{
		printSysInfo();
	}
	if (flag & INFO_CPU)
	{
		printCPUInfo();
	}
	if (flag & INFO_BAT)
	{
		printBatteryInfo();
	}
	if (flag & INFO_HINT)
	{
		printHints();
	}
	if (flag & INFO_VID)
	{
		printDisplayInfo();
		printVideoInfo();
	}
	if (flag & INFO_JOY)
	{
		printJoyStickInfo();
	}
	if (flag & INFO_AUD)
	{
		
		printAudioInfo();
	}
}