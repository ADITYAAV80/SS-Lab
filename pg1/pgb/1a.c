/*

NAME: 1a.c 
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
DATE: 8TH AUG 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<unistd.h>

int main(){

	char path[256],name[256];
	printf("Enter the path of softlink : ");
	scanf("%s",path);
	printf("Enter the name of softlink : ");
	scanf("%s",name);
	int ret = symlink(path,name);
	if (ret==-1){
		perror("perror");
	}
	else{
		printf("Softlink created\n");
	}
}

/* OUTPUT

Enter the path of softlink : ../../../Desktop/demo.py
Enter the name of softlink : cprogsoftlink
Softlink created

Enter the path of softlink : ../../../Desktop/demo.py
Enter the name of softlink : cprogsoftlink
perror: File exists

*/
