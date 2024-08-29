/*
NAME: 27c.c
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

	printf("Using execle:\n");
	char *envp[] = {NULL};
	int ret = execle("/bin/ls", "ls", "-Rl", NULL,envp);
	if (ret== -1){
		perror("execle error");
	}
}

/* OUTPUT

1) Compile and execute : 27c.c

Using execle:
.:
total 60
-rw-r--r-- 1 root   root     745 Aug 29 23:14 27a.c
-rwxrwxr-x 1 aditya aditya 16040 Aug 29 23:12 27a.out
-rw-r--r-- 1 root   root     892 Aug 29 23:24 27b.c
-rwxrwxr-x 1 aditya aditya 16048 Aug 29 23:22 27b.out
-rw-r--r-- 1 aditya aditya   650 Aug 29 23:27 27c.c
-rwxrwxr-x 1 aditya aditya 16096 Aug 29 23:28 27c.out

*/
