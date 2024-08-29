/*
NAME: 27d.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
DATE: 29 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	printf("Using execv:\n");
	char *arguments[] = { "ls", "-Rl", NULL};
	int ret = execv("/bin/ls", arguments);
	if (ret== -1){
		perror("execv error");
	}
}

/* OUTPUT

1) Compile and execute : 27d.c

aditya@laptop:~/SS-Lab/pg27$ ./27d.out
Using execv:
.:
total 80
-rw-r--r-- 1 root   root     745 Aug 29 23:14 27a.c
-rwxrwxr-x 1 aditya aditya 16040 Aug 29 23:12 27a.out
-rw-r--r-- 1 root   root     892 Aug 29 23:24 27b.c
-rwxrwxr-x 1 aditya aditya 16048 Aug 29 23:22 27b.out
-rw-r--r-- 1 aditya aditya   993 Aug 29 23:28 27c.c
-rwxrwxr-x 1 aditya aditya 16096 Aug 29 23:28 27c.out
-rw-r--r-- 1 aditya aditya   654 Aug 29 23:35 27d.c
-rwxrwxr-x 1 aditya aditya 16096 Aug 29 23:35 27d.out


*/
