/*
NAME:32b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
DATE: 19 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define SHM_KEY 1234
#define SHM_SIZE 100

int shmid;
char *shm_ptr;
sem_t mutex;

void* writeToSharedMemory(void* arg) {

	char* message = (char*)arg;
    	sem_wait(&mutex);
	//crtical section 
    	strcpy(shm_ptr, message);
    	sem_post(&mutex); 
    	pthread_exit(NULL);
}

int main() {

    //key is static, obtaining shared memory ID
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory id %d\n",shmid); 

    //attaching shared memory to physical memory and getting pointer to start of shared memory
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    //initializing semaphores
    sem_init(&mutex, 0, 1);

    pthread_t thread1, thread2;
    char* message1 = "Message from Thread 1";
    char* message2 = "Message from Thread 2";

    pthread_create(&thread1, NULL, writeToSharedMemory, (void*)message1);
    printf("Content of shared memory: %s\n", shm_ptr);

    pthread_create(&thread2, NULL, writeToSharedMemory, (void*)message2);
    printf("Content of shared memory: %s\n", shm_ptr);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Content of shared memory: %s\n", shm_ptr);

    shmdt(shm_ptr);

}

/* 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg32$ ./a.out
Shared memory id 163877
Content of shared memory: Message from Thread 2
Content of shared memory: Message from Thread 1
Content of shared memory: Message from Thread 2

*/
