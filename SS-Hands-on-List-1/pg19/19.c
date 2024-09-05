/*
NAME: 19.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
19. Write a program to find out time taken to execute getpid system call.
Use time stamp counter.
DATE: AUG 22 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char *argv[]){

	clock_t s_time= clock();
	double start_time = (double)s_time/CLOCKS_PER_SEC;
	printf("Start time is : %f mili seconds\n",start_time*1000);

	pid_t x = getpid();

	clock_t e_time= clock();
	double end_time = (double)e_time/CLOCKS_PER_SEC;
	printf("End time is : %f mili seconds\n",end_time*1000);

	double total_time = end_time - start_time;
	printf("Total time taken is : %f mili seconds\n",total_time*1000);

}

/* OUTPUT

1) Compile and run : 19.c

aditya@laptop:~/SS-Lab/pg19$ ./pg19.out
Start time is : 2.007000 mili seconds
End time is : 2.130000 mili seconds
Total time taken is : 0.123000 mili seconds

*/
