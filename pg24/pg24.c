/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
24. Write a program to create an orphan process.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); 

    if (pid > 0) {
        printf("Parent process has pid %d but is exiting.\n", getpid());
        exit(0);
    }

    if(pid==0){
     printf("Child process with pid %d whose parent is now %d.\n",getpid(), getppid());
     sleep(10);
     printf("Child process with pid %d  is now orphaned and adopted by %d.\n",getpid(), getppid());
     exit(0);
    }
}
