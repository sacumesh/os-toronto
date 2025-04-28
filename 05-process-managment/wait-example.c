#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "process_state.h"


int main(void) {
    pid_t pid;
    pid_t wait_pid;
    int wstatus;

    pid = fork();

    if (pid == -1) {
        return errno;
    } if (pid == 0) {
       sleep(2);
       return 4;
    } else {
        printf("Calling wait\n");
        wait_pid = wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            printf("Wait returned for an exited process! pid: %d, status: %d\n", wait_pid, WEXITSTATUS(wstatus));
        } else {
            return ECHILD;
        }
    }






    return 0;
}