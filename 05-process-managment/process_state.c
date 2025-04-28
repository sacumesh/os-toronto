#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "process_state.h"

char process_state(pid_t pid){
	FILE *file;
	char path[100];
	char line[256];
	char p_state;

	

	snprintf(path, sizeof(path), "/proc/%d/status", pid);

	file = fopen(path, "r");

	if (!file) {
		fprintf(stderr, "%s\n", "File open failed");
	}

	p_state = '?';
	while (fgets(line, sizeof(line), file)) {
		if (!strncmp(line, "State:", 6)) {
			sscanf(line, "State:\t%c", &p_state);
			break;
			}
		}

		fclose(file);


	return p_state;
}
