/*
NAME: 1.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)
DATE: 8 AUG 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <sys/stat.h>
#include <stdio.h>
int main(){

	const char *path="/tmp/fifo";
	mode_t mode = 0666;
	int ret = mkfifo(path, mode);
	if(ret==-1){
		perror("mknod");
	}
	else{
		printf("FIFO created at path:%s\n",path);
	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/pg1/pgb$ cat file1.txt
This file will be copied in file2.txt using fifo

aditya@laptop:~/SS-Lab/pg1/pgb$ ./1c.out
FIFO created at path:/tmp/myfifo

aditya@laptop:~/SS-Lab/pg1/pgb$ cat file1.txt > /tmp/myfifo

Open new terminal go to same location

aditya@laptop:~/SS-Lab/pg1/pgb$ cat /tmp/myfifo > file2.txt

aditya@laptop:~/SS-Lab/pg1/pgb$ diff file1.txt file2.txt [No output indicating files are same]

*/


