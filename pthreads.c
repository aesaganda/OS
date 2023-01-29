#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void *ptr);

int main()
{
    pthread_t AES1, AES2;
    char *message1 = "MacBook1";
    char *message2 = "MacBook2";
    int ret1, ret2;

    ret1 = pthread_create(&AES1, NULL, print_message_function, (void *)message1);
    if (ret1 != 0)
    {
        printf("Error creating thread 1\n");
        exit(1);
    }

    ret2 = pthread_create(&AES2, NULL, print_message_function, (void *)message2);
    if (ret2 != 0)
    {
        printf("Error creating thread 2\n");
        exit(1);
    }

    pthread_join(AES1, NULL);
    pthread_join(AES2, NULL);

    printf("Thread 1 returns: %d\n", ret1);
    printf("Thread 2 returns: %d\n", ret2);
    exit(0);
}

void *print_message_function(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s \n", message);
    return NULL;
}
