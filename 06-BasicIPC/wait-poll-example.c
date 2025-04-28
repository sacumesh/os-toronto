#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        return errno;
    } 

    if (pid == 0) {
        sleep(2);
        return 0;
    } else {
        pid_t wait_pid = 0;
        int wstatus;

        unsigned int count = 0;
        while (wait_pid == 0) {
            sleep(1);
            ++count;
            printf("Calling wait (attemp %u)\n", count);
            wait_pid = waitpid(pid, &wstatus, WNOHANG);
        }

        if (wait_pid == -1) {
            int err = errno;
            perror("wait_pid");
            exit(err);
        }

        if (WIFEXITED(wstatus)) {
            printf("Wait returned for an exited process! pid: %d, status: %d", wait_pid, WEXITSTATUS(wstatus));
        } else {
            return ECHILD;
        }
    }

}