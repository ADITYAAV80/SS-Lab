/*
NAME: 1a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
 a. ITIMER_REAL
 b. ITIMER_VIRTUAL
 c. ITIMER_PROF
DATE: 04 SEP 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>

void handler(int signum){

        if (signum==SIGALRM){
                printf("SIGALRM TRIGGERED::Interval timer expired\n");
        }
        else if (signum ==SIGVTALRM){
                printf("SIGVTALRM TRIGGERED::Interval timer expired\n");
        }
        else if (signum ==SIGPROF){
                printf("SIGPROF TRIGGERED::Interval timer expired\n");
        }


}

int main(int argc, char * argv[]){

	struct itimerval timer;
	signal(SIGALRM, handler);

	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 5;
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL,&timer,NULL);

	while(1){
		sleep(100);//does not affect the alarm time
	}

	return 0;
}
