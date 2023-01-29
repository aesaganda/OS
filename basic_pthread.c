#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *ptr);

void main()
{
    pthread_t thread;
    char *message = "I am a thread!";

    int ret = pthread_create(&thread, NULL, print_message, (void *)message);

    if (ret)
    {
        printf("Error creating thread!");
        exit(1);
    }

    pthread_join(thread, NULL);

    printf("Thread completed successfully.\n");
    exit(0);
}

void *print_message(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s\n", message);
}