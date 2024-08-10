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

int main(int argc, char * argv[]){

	struct stat file_stat;
	
	if ( stat(argv[1],&file_stat) < 0){
		perror("Error");
	}

	printf("%ld",file_stat.st_ino);
}
