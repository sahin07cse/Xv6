#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main (int argc, char* argv[])
{ 
	if (argc < 2) 
		exit();

	printf("Nice Value:   %d", atoi(argv[1]));
	
	int value = nice(atoi(argv[1]));
	
	value = nice(1000); 
        
    value = nice(50);
    value = nice(200);
	printf("Nice value of the current process is %d", value);
	exit();
}
