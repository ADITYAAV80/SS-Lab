#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	int status;

	int f1 = fork();
	if(f1==0){
		printf("Child 1 created with pid %d\n",getpid());
		sleep(2);
		printf("Child 1 exited\n");
		exit(0);
	}
	int f2 = fork();
	if(f2==0){
		printf("Child 2 created with pid %d\n",getpid());
		sleep(20);
		printf("Child 2 exited\n");
		exit(0);
	}
	int f3=fork();
	if(f3==0){
		printf("Child 3 created with pid %d\n",getpid());
		sleep(1);
		printf("Child 3 exited\n");
		exit(0);
	}

	int w = waitpid(f2,&status,0);
	if (w<0){
		perror("error waitpid :");
	}
	printf("Parent process has finished execution\n");
}
