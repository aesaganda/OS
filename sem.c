#include <semaphore.h>
#include <stdio.h>

void main(){
    sem_t *sem;

    sem = sem_open("SEM", O_CREAT, 0666, 1);

    // acquire the semaphore
    sem_wait(sem);

    // critical section
    sem_post(sem);
}