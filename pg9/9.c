/*
NAME: 9.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
DATE: 10 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char * argv[]){

	if (argc<=1){
		printf("Please enter file name in CLI\n");
		exit(0);
	}
	struct stat file_stat;

	if ( stat(argv[1],&file_stat) < 0){
		perror("Error");
	}

	printf("Inode number : %ld\n",file_stat.st_ino);
	printf("No of hard links : %ld\n",file_stat.st_nlink);
	printf("User ID : %d\n",file_stat.st_uid);
	printf("Group ID : %d\n", file_stat.st_gid);
	printf("Size : %ld\n",file_stat.st_size);
	printf("Block Size: %ld\n",file_stat.st_blksize);
	printf("No of blocks: %ld\n",file_stat.st_blocks);
	printf("Time of last access:%s",ctime(&file_stat.st_atime));
	printf("Time of last modification:%s",ctime(&file_stat.st_mtime));
	printf("Time of last change:%s",ctime(&file_stat.st_ctime));

}

/* OUTPUT

1) Compile and run code: 9.c
2) During execution supply a file as argument: ./9.out [file_name]

aditya@laptop:~/SS-Lab/pg9$ ./9.out
Please enter file name in CLI

aditya@laptop:~/SS-Lab/pg9$ ./9.out file1.txt
Inode number : 5256481
No of hard links : 1
User ID : 1000
Group ID : 1000
Size : 161
Block Size: 4096
No of blocks: 8
Time of last access:Sat Aug 10 23:17:07 2024
Time of last modification:Sat Aug 10 23:13:17 2024
Time of last change:Sat Aug 10 23:13:17 2024

Additional info:
time.h consists of ctime function which connverts date format in numerical format to string format (human readable)

*/
