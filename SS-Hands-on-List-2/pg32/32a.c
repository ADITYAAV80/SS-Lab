/*
NAME:32a.c
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
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int tno = 0;
sem_t mutex;

void* sellTicket(void* arg) {

    while (1) {
        sem_wait(&mutex); 
        if (tno <= 50) {
            tno++;
            printf("Ticket %d sold. Acessed by thread %ld\n", tno,pthread_self());
        }
        sem_post(&mutex); 
        if (tno > 50){
		break;
	}
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t seller1, seller2;

    sem_init(&mutex, 0, 1);

    pthread_create(&seller1, NULL, sellTicket, NULL);
    pthread_create(&seller2, NULL, sellTicket, NULL);

    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);

    sem_destroy(&mutex);

    return 0;
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg32$ ./a.out
Ticket 1 sold. Acessed by thread 140497123276480
Ticket 2 sold. Acessed by thread 140497123276480
Ticket 3 sold. Acessed by thread 140497123276480
Ticket 4 sold. Acessed by thread 140497123276480
Ticket 5 sold. Acessed by thread 140497123276480
Ticket 6 sold. Acessed by thread 140497123276480
Ticket 7 sold. Acessed by thread 140497123276480
Ticket 8 sold. Acessed by thread 140497123276480
Ticket 9 sold. Acessed by thread 140497123276480
Ticket 10 sold. Acessed by thread 140497123276480
Ticket 11 sold. Acessed by thread 140497123276480
Ticket 12 sold. Acessed by thread 140497123276480
Ticket 13 sold. Acessed by thread 140497123276480
Ticket 14 sold. Acessed by thread 140497123276480
Ticket 15 sold. Acessed by thread 140497123276480
Ticket 16 sold. Acessed by thread 140497123276480
Ticket 17 sold. Acessed by thread 140497123276480
Ticket 18 sold. Acessed by thread 140497123276480
Ticket 19 sold. Acessed by thread 140497123276480
Ticket 20 sold. Acessed by thread 140497123276480
Ticket 21 sold. Acessed by thread 140497123276480
Ticket 22 sold. Acessed by thread 140497123276480
Ticket 23 sold. Acessed by thread 140497123276480
Ticket 24 sold. Acessed by thread 140497123276480
Ticket 25 sold. Acessed by thread 140497123276480
Ticket 26 sold. Acessed by thread 140497123276480
Ticket 27 sold. Acessed by thread 140497123276480
Ticket 28 sold. Acessed by thread 140497123276480
Ticket 29 sold. Acessed by thread 140497123276480
Ticket 30 sold. Acessed by thread 140497123276480
Ticket 31 sold. Acessed by thread 140497123276480
Ticket 32 sold. Acessed by thread 140497123276480
Ticket 33 sold. Acessed by thread 140497123276480
Ticket 34 sold. Acessed by thread 140497123276480
Ticket 35 sold. Acessed by thread 140497123276480
Ticket 36 sold. Acessed by thread 140497123276480
Ticket 37 sold. Acessed by thread 140497123276480
Ticket 38 sold. Acessed by thread 140497114883776
Ticket 39 sold. Acessed by thread 140497114883776
Ticket 40 sold. Acessed by thread 140497114883776
Ticket 41 sold. Acessed by thread 140497114883776
Ticket 42 sold. Acessed by thread 140497114883776
Ticket 43 sold. Acessed by thread 140497114883776
Ticket 44 sold. Acessed by thread 140497114883776
Ticket 45 sold. Acessed by thread 140497114883776
Ticket 46 sold. Acessed by thread 140497114883776
Ticket 47 sold. Acessed by thread 140497114883776
Ticket 48 sold. Acessed by thread 140497114883776
Ticket 49 sold. Acessed by thread 140497114883776
Ticket 50 sold. Acessed by thread 140497114883776
Ticket 51 sold. Acessed by thread 140497114883776

*/
