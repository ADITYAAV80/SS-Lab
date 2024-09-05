/*
NAME: 24.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
24. Write a program to create an orphan process.
DATE: 22 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    pid_t pid = fork();
    if (pid > 0) {
	sleep(1);
        printf("Parent process has pid %d but is exiting.\n", getpid());
        exit(0);
    }

    if(pid==0){
     printf("Child process with pid %d whose parent is now %d.\n",getpid(), getppid());
     sleep(5);
     printf("Child process with pid %d  is now orphaned and adopted by %d.\n",getpid(), getppid());
     exit(0);
    }
}

/* OUTPUT

1) Compile and Execute the program: 24.c
2) Parent executes first and sleeps
3) Child executes and has a parent
4) Child sleeps and parent exits and hence Child starts executing again but it doesn't have a parent
5) Child exits

aditya@laptop:~/SS-Lab/pg24$ ./24.out
Child process with pid 24367 whose parent is now 24366.
Parent process has pid 24366 but is exiting.

aditya@laptop:~/SS-Lab/pg24$ Child process with pid 24367  is now orphaned and adopted by 1663.

*/
