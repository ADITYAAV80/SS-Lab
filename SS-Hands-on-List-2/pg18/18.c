/*
NAME:18.c 
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
DATE: 08 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(){

	int pipefds1[2],pipefds2[2];
	if (pipe(pipefds1) == -1 || pipe(pipefds2) == -1){
		perror("pipe");
		exit(0);
	}

	if(fork()){

		sleep(1);
		close(pipefds2[0]);
		close(pipefds2[1]);
		close(pipefds1[1]);

		dup2(pipefds1[0],0);
		char *args[] = {"wc",NULL};
		int w = execv("/bin/wc", args);

		close(pipefds1[1]);
		wait(0);

	}
	else{

		if(fork()){

			sleep(1);
			close(pipefds1[0]);
			close(pipefds2[1]);

			dup2(pipefds2[0],0);
			dup2(pipefds1[1],1);
			char *args[] = {"grep","^d",NULL};
			int w = execv("/bin/grep", args);

			close(pipefds2[0]);
			close(pipefds1[1]);
			wait(0);

		}
		else{

			close(pipefds1[1]);
			close(pipefds1[0]);
			close(pipefds2[0]);

			dup2(pipefds2[1],1);
			char *args[] = {"ls", "-l", NULL};
			int w =execv("/bin/ls", args);
			close(pipefds2[1]);

		}
	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg18$ ./18.out
      0       0       0

*/

