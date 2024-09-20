/*
NAME:32c.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
DATE: 20 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


int resource[2];
sem_t semaphore;

void* useResource(void* arg) {
    int resource_id = *(int*)arg;

    sem_wait(&semaphore); 


    printf("Using resource %d.\n", resource_id);
    resource[resource_id] = 0;

    sem_post(&semaphore); 

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];

    sem_init(&semaphore, 0,2);

    for (int i = 0; i < 2; ++i) {
        resource[i] = 1; 
        pthread_create(&threads[i], NULL, useResource, (void*)&i);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg32$ ./32c.out
Using resource 1.
Using resource 2.

*/
