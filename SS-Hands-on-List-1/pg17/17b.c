/*

NAME: 17b.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file
DATE: 17 AUG 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main (int argc, char *argv[]){

	int fd = open("file.txt", O_RDWR);
	if(fd==-1){
		perror("error opening file: \n");
	}
	else{
		printf("File opened successfully with fd:%d\n",fd);
	}

	struct flock l;
	l.l_type = F_RDLCK;
	l.l_start = 0;
	l.l_whence = SEEK_SET;
	l.l_len = 0;
	int buf;

	int rdlck = fcntl(fd,F_SETLKW,&l);
	if(rdlck == -1){
		perror("read lock error :");
	}
	else{
		printf("Readlock set\n");
	}

	int r = read(fd,&buf,1);
	if (r==-1){ perror("Error reading : \n");}
	int ls = lseek(fd,-r,SEEK_CUR);
	printf("Current ticket no : %d\n",buf);
	buf+=1;


	l.l_type=F_WRLCK;
	int wrlck = fcntl(fd,F_SETLKW,&l);
	if(wrlck == -1){
		perror("write lock error :");
	}
	else{
		printf("Writelock set\n");
	}

	int w = write(fd,&buf,sizeof(int));
	if(w==-1){ perror("Error writing : ");}
	ls = lseek(fd,-w,SEEK_CUR);
	r = read(fd,&buf,sizeof(int));
	printf("New value of ticket no : %d\n",buf);
	printf("Enter to release lock\n");
	getchar();


	l.l_type= F_UNLCK;
	int unlck = fcntl(fd,F_SETLKW,&l);
	if (unlck !=-1){
		printf("Lock released\n");
	}
	else{
		perror("Lock release error :");
	}
	close(fd);
}

/* OUTPUT

Terminal 1
1) Compile and Execute : 17b.c
2) It acquires read lock
3) It reads the value 10 after it is initialized by 17a.c
4) It acquires a write lock
5) Updates the ticket value to 11

Terminal 2
1) Execute 17b.out
2) It opens the file and waits for write lock to be released by Resource 1


Terminal 1
1) Release the write lock by pressing Enter

Terminal 2
1) It acquires the read lock, reads value 11 , acquires write lock,
updates ticket no to 12
2) It waits for enter to release lock

If a new terminal tries to access the file then it is made to wait until 
terminal 2 releases the resources



TERMINAL 1:
aditya@laptop:~/SS-Lab/pg17$ ./17b.out
File opened successfully with fd:3
Readlock set
Current ticket no : 10
Writelock set
New value of ticket no : 11
Enter to release lock

Lock released

TERMINAL 2:
aditya@laptop:~/SS-Lab/pg17$ ./17b.out
File opened successfully with fd:3
Readlock set
Current ticket no : 11
Writelock set
New value of ticket no : 12
Enter to release lock

Lock released

*/
