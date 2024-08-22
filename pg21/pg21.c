#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	if(fork()){
		printf("PARENT PROCESS\n");
		printf("PID of parent ID : %d\n",getpid());
	}
	else{
		printf("CHILD PROCESS\n");
		printf("PID of child ID : %d\n",getpid());
		printf("PID of it's parent : %d\n",getppid());
	}
}
