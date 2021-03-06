#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main (int argc, char* argv[])
{ 

	int value = pseudorandomgen();
	//printf("returned random value is %d\n", value);
	exit();
}
