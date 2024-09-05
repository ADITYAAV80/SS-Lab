/*
NAME: 1b.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
DATE: 8 AUG 2024
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
	int ret = link(path,name);
	if (ret==-1){
		perror("perror");
	}
	else{
		printf("Hardlink created successfully\n");
	}
}

/* OUTPUT

Enter the path of hardlink : ../../../Desktop/demo.py
Enter the name of hardlink : cproghardlink
Hardlink created successfully

Enter the path of hardlink : ../../../Desktop/demo.py
Enter the name of hardlink : cproghardlink
perror: File exists

*/
