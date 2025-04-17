#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int x = 5;
    pid_t returned_pid = fork();

    if (returned_pid > 0) {
        x = 3;
        printf("Parent returned pid: %d\n", returned_pid);
        printf("Parent pid: %d\n", getpid());
        printf("Parent parent pid: %d\n", getppid());
    } else if (returned_pid == 0) {
        x = 6;
        printf("Child returned pid: %d\n", returned_pid);
        printf("Child pid: %d\n", getpid());
        printf("Child parent pid: %d\n", getpid());
    } else {
        int err = errno;
        perror("fork failed");
        return err;
    }
    printf("x = %d\n", x);
    return 0;

}
