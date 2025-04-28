
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "process_state.h"

int main(void) {
	pid_t pid;
	char process_st;

	pid = getpid();
	process_st = process_state(pid);

	if (process_st == '?') {
		fprintf(stderr, "Failed to get the process state.");
	}

	if (process_st == 'R')
		fprintf(stdout, "Test passed:\npid\t %d\nState\t %c\n", pid, process_st);
	else
		fprintf(stderr, "Test failed: Expected 'R', but got '%c'. Process should be in 'R' state.\n", process_st);

	return 0;
}
