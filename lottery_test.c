#include "types.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "user.h"
#include "memlayout.h"
#include "x86.h"
#include "traps.h"
#include "spinlock.h"

#define CHILDRENS 50

int tickets[CHILDRENS];
int pids[CHILDRENS];

int create_process(int tickets) {
    int pid = fork();
    //cprintf("returned pid: %d\n", pid);
    if (pid == 0) {
        nice(tickets);
	yield();
        exit();
    } else if (pid != -1) {
        return pid;
    } else {
        printf(2, "error in fork\n");
        return -1;
    }
}


void execute_test() {
    nice(100);
    for (int i = 0; i < CHILDRENS; i++) {
	int n = randomNumberGenerator();
	if (n < 0) n = -n; //To handle negative number
	n = n % 100;
	tickets[i] = n;
        pids[i] = create_process(tickets[i]);
    }

    nice(25);
    for (int i = 0; i < 50; i++) {
	yield();
        int done = 1;
        for (int i = 0; i < CHILDRENS; ++i) {
            done = 0;
        }
        if (done)
            break;

	cps();
    }

    nice(100);


    sleep(100);

    for (int i = 0; i < CHILDRENS; ++i) {
        kill(pids[i]);
    }
    for (int i = 0; i < CHILDRENS; ++i) {
        wait();
    }
}

void run_test() {
    execute_test();
}

int 
main (int argc, char* argv[])
{


	run_test();

	
	exit();
}
