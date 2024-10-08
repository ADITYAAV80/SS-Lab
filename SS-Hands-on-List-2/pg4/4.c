/*
NAME: 4.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM: 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. 
DATE: 05 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<x86intrin.h>

int main(){

	unsigned long long start,end,diff;

	start = __rdtsc();
	for (int i=0;i<100;++i){
		getppid();
	}
	end = __rdtsc();

	printf("Time taken to execute 100 getppid() system call %f ns\n",(end-start)/4.4);
	// my system frequency is 4400 Mhz
	return 0;
}

/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg4$ ./4.out
Time taken to execute 100 getppid() system call 44916.363636 ns

*/
