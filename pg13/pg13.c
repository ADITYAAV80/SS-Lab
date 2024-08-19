/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char * argv[]){

	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO,&readfds);

	struct timeval timewait;
	timewait.tv_sec = 10;
	timewait.tv_usec =0;
	printf("Waiting for stdin 10 seconds...\n");

	int r = select(STDIN_FILENO+1,&readfds, NULL,NULL, &timewait);
	
	printf("%d",r);
	if (r== -1){
		perror("\nError in select");
		return -1;
	}

	else if (r==0){
		printf("\nNo input received within 10 seconds\n");
	}

	else{
		if(FD_ISSET(STDIN_FILENO,&readfds)){
			char buf[1024];
			int r = read(0,buf,sizeof(buf));
			printf("\nInput is available on stdin:%s\n",buf);
		}
		else{
			printf("\nerror reading input");
		}
	}
	close(STDIN_FILENO);
	return 0;
}
