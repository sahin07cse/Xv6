#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main (int nArg, char* cArg[])
{ 
	if (nArg < 2) 
		exit();
	int value = nice(atoi(cArg[1]));
	
	getNice();
	
	exit();
}
