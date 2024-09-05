/*
NAME: 20.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
20. Find out the priority of your running program. Modify the priority with nice command.
DATE: 22 AUG 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	if (argc!=2){
		printf("Please pass the priority value \n");
		exit(0);
	}

	int add_p = atoi(argv[1]);

	int curr_p = nice(0);
	printf("Current priority : %d\n",curr_p);

	int new_p = nice(add_p);
	printf("New priority : %d\n",new_p);

	return 0;
}

/* OUTPUT


aditya@laptop:~/SS-Lab/pg20$ ./20.out
Please pass the priority value 

aditya@laptop:~/SS-Lab/pg20$ ./20.out 6
Current priority : 0
New priority : 6

aditya@laptop:~/SS-Lab/pg20$ ./20.out 20
Current priority : 0
New priority : 19

aditya@laptop:~/SS-Lab/pg20$ ./20.out -5
Current priority : 0
New priority : -1

*/
