/*
NAME:19.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function
DATE:

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){

	int ret = mknod("mknod_fifo", S_IFIFO| 0666, 0);
	if (ret==-1){
		perror("mknod");
		exit(0);
	}
	ret = mkfifo("mkfifo_fifo", 0666);
	if (ret==-1){
		perror("mkfifo");
		exit(0);
	}

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg19$ ls -l
total 44
-rw-r--r-- 1 root   root    6397 Sep 18 00:21 19abc.txt
-rw-r--r-- 1 root   root     834 Sep 18 00:23 19de.c
-rwxrwxr-x 1 aditya aditya 16088 Sep 18 00:22 19de.out
-rwxrwxr-x 1 aditya aditya 16088 Sep  8 23:08 19.out
prw-rw-r-- 1 aditya aditya     0 Sep 18 00:22 mkfifo_fifo
prw-rw-r-- 1 aditya aditya     0 Sep 18 00:22 mknod_fifo
prw-rw-r-- 1 aditya aditya     0 Sep 18 00:14 myfifo
prw-rw-r-- 1 aditya aditya     0 Sep 18 00:14 myfifo1

*/
