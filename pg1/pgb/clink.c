/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>
int main(){

	char path[256],name[256];
	printf("Enter the path of hardlink : ");
	scanf("%s",path);
	printf("Enter the name of hardlink : ");
	scanf("%s",name);
	link(path,name);
	perror("perror");

}
