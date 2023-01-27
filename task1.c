#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // int pid;
    pid_t pid;

    pid = fork();

    if (pid > 0)
    {
        // parent
        wait(NULL); // parent waits till all child processes done
        printf("parent: %d, this_pid: %d\n", pid, getpid());
    }

    if (pid == 0)
    {
        // child
        printf("child: %d, this_pid: %d\n", pid, getpid());
    }

    if (pid < 0)
    {
        // error
    }
}