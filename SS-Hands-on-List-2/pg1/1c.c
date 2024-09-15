/*
NAME: 1b.c
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
	signal(SIGPROF, handler);

	timer.it_value.tv_sec = 2;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 5;
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_PROF,&timer,NULL);
	int count = 0;
	while(1){
		for (long long i = 0; i < 1000000000; ++i);
                sleep(1);
		//slightly faster as it calculates the time sleep 
		//system call was executed
	}
	return 0;
}
