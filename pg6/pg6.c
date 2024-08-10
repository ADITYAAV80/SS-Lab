/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv){
	
	char a[1024];
	int r = read(0, a , sizeof(a));
	if(r != -1){
		printf("No of bytes read %d\n",r);
	}
	else{
		perror("error");
	}
	printf("The data stored in buffer\n");
	for(int i=0; i<r; i++){
		printf("c[%d]=%c\n",i,a[i]);
	}
	int w = write(1, a , r);
	if(w != -1){
		printf("No of bytes written %d\n",w);
	}
	else{
		perror("error");
	}
}
