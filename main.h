
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
#else
#error "SO no permitido"
#endif

#endif
