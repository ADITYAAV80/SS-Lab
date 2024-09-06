/*
NAME:8.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:8. Write a separate program using signal system call to catch the following signals.
               a. SIGSEGV
               b. SIGINT
               c. SIGFPE
               d. SIGALRM (use alarm system call)
               e. SIGALRM (use setitimer system call)
               f. SIGVTALRM (use setitimer system call)
               g. SIGPROF (use setitimer system call)
DATE: 06 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void handler(int signum){

	if(signum==SIGSEGV){
		printf("Segmentation fault signal triggered\n");
		exit(0);
	}else if (signum==SIGINT){
		printf("\nRecieved interrupt\n");
		exit(0);
	}else if (signum==SIGFPE){
		printf("Recieved floating point error interrupt\n");
		exit(0);
	}else if (signum==SIGALRM){
		printf("Recieved real timer signal\n");
		exit(0);
	}else if (signum==SIGVTALRM){
		printf("Recieved virtual time signal\n");
		exit(0);
	}else if (signum==SIGPROF){
		printf("Recieved profiling timer signal\n");
		exit(0);
	}else{
		exit(0);
	}

}

int main(){

	signal(SIGSEGV, handler);
	signal(SIGINT, handler);
	signal(SIGFPE, handler);
	signal(SIGALRM, handler);
	signal(SIGVTALRM, handler);
	signal(SIGPROF, handler);

	printf("Trigger the following signals\n");
	printf(" 1)SIGSEGV\n 2)SIGINT\n 3)SIGFPE\n 4)SIGALRM(alarm)\n 5)SIGALRM(setitimer)\n 6)SIGVTALRM\n 7)SIGPROF\n");
	int c;
	scanf("%d",&c);
	switch(c){
		case 1:
			int *ptr =NULL;
			*ptr= 0;
			break;
		case 2:
			printf("type ctrl+c\n");
			while(1){};
			break;
		case 3:
			int x=0/0;
			break;
		case 4:
			printf("Using alarm system call\n");
			alarm(2);
			while(1){};
			break;
		case 5:
			struct itimerval itimer1;
			itimer1.it_value.tv_sec = 5;
			itimer1.it_value.tv_usec = 0;
			itimer1.it_interval.tv_sec = 2;
			itimer1.it_interval.tv_usec = 0;

			printf("Using set interval timer\n");
			setitimer(ITIMER_REAL,&itimer1,NULL);
			while(1){};
			break;
		case 6:
			struct itimerval itimer2;
			itimer2.it_value.tv_sec = 5;
			itimer2.it_value.tv_usec = 0;
			itimer2.it_interval.tv_sec = 2;
			itimer2.it_interval.tv_usec = 0;
			setitimer(ITIMER_VIRTUAL,&itimer2,NULL);
			while(1){};
			break;
		case 7:
			struct itimerval itimer3;
			itimer3.it_value.tv_sec = 5;
			itimer3.it_value.tv_usec = 0;
			itimer3.it_interval.tv_sec = 2;
			itimer3.it_interval.tv_usec = 0;
			setitimer(ITIMER_PROF,&itimer3,NULL);
			while(1){};
			break;
		}
	return 0;
}

/* OUPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
1
Segmentation fault signal triggered

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
2
type ctrl+c
^C
Recieved interrupt

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
3
Recieved floating point error interrupt

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
4
Using alarm system call
Recieved real timer signal

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
5
Using set interval timer
Recieved real timer signal

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
6
Recieved virtual time signal

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg8$ ./8.out
Trigger the following signals
 1)SIGSEGV
 2)SIGINT
 3)SIGFPE
 4)SIGALRM(alarm)
 5)SIGALRM(setitimer)
 6)SIGVTALRM
 7)SIGPROF
7
Recieved profiling timer signal

*/
