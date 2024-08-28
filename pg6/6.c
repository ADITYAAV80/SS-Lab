/*
NAME: 6.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
DATE: 10 AUG 2024
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

/* OUTPUT

1) Compile and Run : 6.c
2) Enter a input string less than 1024 characters in terminal after running the program
3) The Output will appear in terminal

Additional Info:
1) Read function takes fd [0(stdin)] as  first argument
2) Second argument specifies buffer which is character array of 1024 characters in this case
3) The third argument specifies the number of bytes:  you can either sizeof() function or calculate it manually ( helpful for custom value)
4) It returns the no of bytes read
5) Similar format for write function if we specify more bytes to write than present in buffer then it may print junk value
6) Also no of bytes read will 1 + no of characters you enter as it stores \n 

aditya@laptop:~/SS-Lab/pg6$ ./6.out
Hello
No of bytes read 6
The data stored in buffer
c[0]=H
c[1]=e
c[2]=l
c[3]=l
c[4]=o
c[5]=

Hello
No of bytes written 6

*/

