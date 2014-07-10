#ifndef INFO_H_
#define INFO_H_

#include <stdio.h>
#include <SDL2/SDL.h>

#define BOOL(i) ( i != 0 ? "true" : "false" )

void printCPUInfo();

void printSysInfo();

void printHints();

#endif
