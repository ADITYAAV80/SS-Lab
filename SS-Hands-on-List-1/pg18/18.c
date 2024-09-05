/*
NAME: 18.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition
DATE: 30 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

struct flight {
	int flight_no;
	int ticket_no;
};

int readLock(int l){
	int fd = open("records.txt",O_RDONLY);
	if (fd == -1){
		perror("Error opening file");
		exit(0);
	}

	struct flight fl;

	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (l-1) * sizeof(struct flight);
	lock.l_len = sizeof(struct flight);

	int fc = fcntl(fd,F_SETLKW,&lock);
	if (fc == -1){
		perror("Locking error");
	}
	printf("\n\n\nRecords locked for reading [In critical section]\n");

	lseek(fd,(l-1)*sizeof(struct flight),SEEK_SET);
	read(fd,&fl,sizeof(struct flight));

	printf("Flight no : %d\n",fl.flight_no);
	printf("Ticket no : %d\n",fl.ticket_no);

	printf("--------Press enter to exit--------\n");
	getchar();
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLKW,&lock);
	printf("Records Unlocked\n\n\n");
	close(fd);
	return 0;

}

int writeLock(int l){

	int fd = open("records.txt",O_RDWR);
	if (fd == -1){
		perror("Error opening file");
		exit(0);
	}

	struct flight fl;

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (l-1) * sizeof(struct flight);
	lock.l_len = sizeof(struct flight);

	int fc = fcntl(fd,F_SETLKW,&lock);
	if (fc == -1){
		perror("Locking error");
	}
	printf("\n\n\nRecords locked for writing [In critical section]\n");

	lseek(fd,(l-1)*sizeof(struct flight),SEEK_SET);
	read(fd,&fl,sizeof(struct flight));


	printf(" You are looking for tickets in Flight no : %d\n",fl.flight_no);

	lseek(fd,(l-1)*sizeof(struct flight),SEEK_SET);
	fl.ticket_no+=1;
	printf("Ticket booked successfully your ticket no is %d\n",fl.ticket_no);

	lseek(fd,(l-1)*sizeof(struct flight),SEEK_SET);
	write(fd,&fl,sizeof(struct flight));

	printf("--------Press enter to exit--------\n");
	getchar();
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLKW,&lock);
	printf("Records Unlocked\n\n\n");
	close(fd);
	return 0;

}

int main() {

	int fd = open("records.txt",  O_RDWR);
	if (fd == -1){
		perror("file opening error");
		exit(0);
	}

	struct flight fl;
	lseek(fd,0,SEEK_SET);

	printf("--------------------------------------------------\n");
	for(int i=0; i<4; ++i) {
		read(fd,&fl,sizeof(struct flight));
		printf("Flight No: %d\n",fl.flight_no);
		printf("Tickets Booked: %d\n",fl.ticket_no);
		printf("------------------\n");
	}
	printf("--------------------------------------------------\n");

	int l;
	int choice;

	printf("Select the flight number you want to know information regarding : ");
	scanf("%d",&l);
	if (l<1 || l>4){
		printf("\nNo such records found\n");
		exit(0);
	}

	while(1){

		printf("--------------------------------------------------\n");
		printf("Select the type of request\n1)See booking information \n2)New booking\n3)Exit\n");
		scanf("%d",&choice);
		if(choice == 1) {
       			readLock(l);
    		}
    		else if(choice == 2) {
        		writeLock(l);
    		}
    		else if(choice == 3) {
			break;
    		}
    		else {
        		printf("Please select the correct request\n");
    		}

	}
	close(fd);
	return 0;
}


/*

----------------------------------------------------Running init file to initialize the records---------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18_init.out

------------------------------------------------------Booking ticket for flight no 4 : Terminal 1---------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 0
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 4
Ticket booked successfully your ticket no is 1
--------Press enter to exit--------

------------------------------------------------------------Opened another terminal and tried to both read and write 4:-----------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 1
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
1

----------------------------------------------------------------Made to wait as terminal 1-Reading and terminal 2-Writing----------------------------------------


aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 1
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2

--------------------------------------------------------------Made to wait as terminal 1 - writing terminal 2- writing----------------------------------------------

---------------------------------------------------------------Now went to terminal 1 and unlocked:----------------------------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 0
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 4
Ticket booked successfully your ticket no is 1
--------Press enter to exit--------

Records Unlocked


--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------In terminal 2 booking is allowed now -------------------------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 1
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 4
Ticket booked successfully your ticket no is 2
--------Press enter to exit--------

-------------------------------------------------------------------Testing advisory locking by locking other records--------------------------------------------------
-------------------------------------------------------------------In terminal 1-------------------------------------------------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 1
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 4
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 4
Ticket booked successfully your ticket no is 2
--------Press enter to exit--------

Records Unlocked


--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 4
Ticket booked successfully your ticket no is 3
--------Press enter to exit--------


---------------------------------------------------------------In terminal 2 writing on record 1 which is allowed-----------------------------------------------------------------------

aditya@laptop:~/SS-Lab/pg18$ ./18.out
--------------------------------------------------
Flight No: 1
Tickets Booked: 0
------------------
Flight No: 2
Tickets Booked: 0
------------------
Flight No: 3
Tickets Booked: 0
------------------
Flight No: 4
Tickets Booked: 3
------------------
--------------------------------------------------
Select the flight number you want to know information regarding : 1
--------------------------------------------------
Select the type of request
1)See booking information 
2)New booking
3)Exit
2



Records locked for writing [In critical section]
 You are looking for tickets in Flight no : 1
Ticket booked successfully your ticket no is 1
--------Press enter to exit--------

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

*/ 
