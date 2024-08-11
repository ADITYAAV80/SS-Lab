/*
NAME: Aditya AV
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
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char * argv[]){

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
