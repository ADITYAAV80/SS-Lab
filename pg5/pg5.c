/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
5)Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	
	int ret[5];
	printf("pid : %d \n",getpid());
	for(;;){
		ret[1] = open("f1.txt", O_CREAT  );
		if(ret[1] != -1){
			printf("f1_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[2] = open("f2.txt", O_CREAT );
		if(ret[2] != -1){
			printf("f2_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[3] = open("f3.txt", O_CREAT  );
		if(ret[3] != -1){
			printf("f3_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[4] = open("f4.txt", O_CREAT );
		if(ret[4] != -1){
			printf("f4_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
		}

		ret[5] = open("f5.txt", O_CREAT );
		if(ret[5] != -1){
			printf("f5_open\n");
		}
		else{
			printf("ERROR\n");
			sleep(30);
			break;
		}

	}
}
