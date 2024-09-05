/*
NAME: 29.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
DATE: 30 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sched.h>

int main(){

	int cur_sched, new_sched;
	pid_t pid = getpid();

	cur_sched = sched_getscheduler(pid);

	if( cur_sched == -1){
		perror("Scheduling policy retrieval error");
		exit(0);
	}
	printf("Current scheduling is ");
	if ( cur_sched == SCHED_FIFO){
		printf("FIFO Scheduling\n");
	}
	else if (cur_sched == SCHED_RR){
		printf("Round Robin Scheduling\n");
	}
	else if (cur_sched == SCHED_OTHER){
		printf("Round Robin with Time Sharing Scheduling\n");
	}
	else{
		printf("Unknown\n");
	}


	struct sched_param param;
	param.sched_priority = 1;
	if (sched_setscheduler(pid,SCHED_RR,&param) == -1){
		perror("Scheduling policy setting error");
		exit(0);
	}

        new_sched = sched_getscheduler(pid);

        if(new_sched == -1){
                perror("Scheduling policy retrieval error");
                exit(0);
        }
        printf("New scheduling is ");
        if (new_sched == SCHED_FIFO){
                printf("FIFO Scheduling ");
        }
        else if (new_sched == SCHED_RR){
                printf("RR Scheduling ");
        }
	else if (new_sched == SCHED_OTHER){
		printf("Round Robin with time sharing Scheduling ");
	}
        else{
                printf("Unknown\n");
        }
	printf("with priority %d \n",param.sched_priority);
	return 0;
}

/* OUTPUT

1) Compile and execute : 29.c
2) While executing use sudo to bypass permission error

aditya@laptop:~/SS-Lab/pg29$ ./29.out
Current scheduling is Round Robin with Time Sharing Scheduling
Scheduling policy setting error: Operation not permitted

*/
