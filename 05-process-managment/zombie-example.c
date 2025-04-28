
#include "process_state.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>



int main(void) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        return errno;
    } if (pid == 0) {
        sleep(2);
    } else {
        sleep(1);
        printf("Child process state: %c\n", process_state(pid));
        sleep(2);
        printf("Child process state: %c\n", process_state(pid));
    }

    return 0;
}