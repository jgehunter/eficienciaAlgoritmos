
#ifndef MAIN_H
#define MAIN_H

struct lista {
	int clave;
	float miembro;
    /*  char *first_name;*/
    /*  char *last_name;*/
};

/* #ifdef _WIN32
#include "timeWindows.h"
#elif defined(_MACH_)
#include "timeApple.h"
#elif defined(_linux_)
#include "timeLinux.h"
#else
   #error "SO no permitido"
#endif*/

#ifdef _WIN32
#include "timeWindows.h"
#endif

#ifdef _MACH
#include "timeApple.h"
#endif

#ifdef _linux
#include "timeLinux.h"
#endif



#endif
