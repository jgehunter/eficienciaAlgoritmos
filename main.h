
#ifndef MAIN_H
#define MAIN_H

struct lista {
	int clave;
	float miembro;
    /*  char *first_name;*/
    /*  char *last_name;*/
};

#ifdef _WIN32
#include "timeWindows.h"
#endif

#ifdef __APPLE__
#include "timeApple.h"
#endif

#ifdef _linux
#include "timeLinux.h"
#endif

#endif
