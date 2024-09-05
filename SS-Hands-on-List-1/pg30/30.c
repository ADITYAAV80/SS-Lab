/*
NAME: 30.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
30. Write a program to run a script at a specific time using a Daemon process.
DATE: 30 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){


	time_t curr_time;

	if(argc!=4){
		printf("Please enter 3 arguments in HH24 MI SS format\n");
		exit(0);
	}

	time(&curr_time);

	struct tm * deadline = localtime(&curr_time);
	printf("Current time is %s",ctime(&curr_time));

	deadline->tm_hour = atoi(argv[1]);
	deadline->tm_min = atoi(argv[2]);
	deadline->tm_sec = atoi(argv[3]);

	time_t end_time = mktime(deadline);

	printf("Amount of seconds left :%f\n",difftime(end_time,curr_time));

	if (fork()==0){
		setsid();
		chdir("/");
		umask(0);


		do {
			time(&curr_time);
		} while(difftime(end_time,curr_time)>0);

		printf("Deadline Done\n");
		exit(0);
	}

}

/*

1) Compile and execute : 30.c

aditya@laptop:~/SS-Lab/pg30$ ./a.out
Please enter 3 arguments in HH24 MI SS format

aditya@laptop:~/SS-Lab/pg30$ ./a.out 21 49 0
Current time is Fri Aug 30 21:48:26 2024
Amount of seconds left :34.000000

aditya@laptop:~/SS-Lab/pg30$ echo  hello
hello

aditya@laptop:~/SS-Lab/pg30$ Deadline Done

aditya@laptop:~/SS-Lab/pg30$ ./30.out 21 51 -10
Current time is Fri Aug 30 21:50:48 2024
Amount of seconds left :2.000000

aditya@laptop:~/SS-Lab/pg30$ Deadline Done

*/
