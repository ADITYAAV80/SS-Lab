/*
NAME: 11.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
DATE: 10 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[]){

	if (argc!=2){
		printf("Please enter file name in CLI\n");
		exit(0);
	}

	int fd = open( argv[1], O_CREAT|O_WRONLY, 0777);
	if (fd != -1){
		printf("File created successfully with fd : %d\n",fd);
	}
	else{
		perror("File opening error");
	}
	char buf1[]="Written using fd from open\n";
	int w1 = write(fd,buf1,sizeof(buf1));
	if (w1!=-1){
		printf("Write with open successfull\n");
	}
	else{
		perror("Writing error:");
	}


	int fd_dup = dup(fd);
	if (fd_dup != -1){
		printf("File descriptor duplicated successfully with fd : %d\n",fd_dup);
	}
	else{
		perror("File description duplication error");
	}

	char buf2[]="Written using fd from dup\n";
	int w2 = write(fd_dup,buf2,sizeof(buf2));
	if (w2!=-1){
		printf("Write with dup successfull\n");
	}
	else{
		perror("Writing error:");
	}

	int fd_dup2 = dup2(fd,1000);
	if (fd_dup2 != -1){
		printf("File descriptor duplicated successfully with fd : %d\n",fd_dup2);
	}
	else{
		perror("File description duplication error");
	}

	char buf3[]="Written using fd from dup2\n";
	int w3 = write(fd_dup2,buf3,sizeof(buf3));
	if (w3!=-1){
		printf("Write with dup2 successfull\n");
	}
	else{
		perror("Writing error:");
	}


	int fd_fcntl = fcntl(fd,F_DUPFD);
	if (fd_fcntl != -1){
		printf("File descriptor duplicated successfully with fd : %d\n",fd_fcntl);
	}
	else{
		perror("File description duplication error");
	}

	char buf4[]="Written using fd from fcntl\n";
	int w4 = write(fd_fcntl,buf4,sizeof(buf4));
	if (w4!=-1){
		printf("Write with fcntl successfull\n");
	}
	else{
		perror("Writing error:");
	}

}
/* OUTPUT

1) Compile and run : 11.c
2) Specify file_name in command line : ./11.out [file_name]

aditya@laptop:~/SS-Lab/pg11$ ./a.out file.txt
File created successfully with fd : 3
Write with open successfull
File descriptor duplicated successfully with fd : 4
Write with dup successfull
File descriptor duplicated successfully with fd : 1000
Write with dup2 successfull
File descriptor duplicated successfully with fd : 5
Write with fcntl successfull

aditya@laptop:~/SS-Lab/pg11$ cat file.txt
Written using fd from open
Written using fd from dup
Written using fd from dup2
Written using fd from fcntl


Additional info:
Using dup and fcntl the file decsriptor will be as minimum as possible
With dup2 you can set whatever value you want but ofcourse try to keep it below 1023

*/
