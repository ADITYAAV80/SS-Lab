/*
NAME:30c.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
DATE: 18 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
	int key, shmid;
    	char *data;

	key = ftok(".", 1);
    	shmid = shmget(key, 1024, 0);

	printf("shared memory id : %d\n",shmid);
    	data = (char*)shmat(shmid, (void *)0, 0);

	printf("Data stored is %s\n",data);
    	if ( shmdt(data)==-1 ){ perror("shmdt");}

	printf("Shared memory detach successful\n");
	system("ipcs -m");

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg30$ ./30c.out
shared memory id : 32816
Data stored is hello
Shared memory detach successful

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 5          aditya     600        524288     2          dest         
0x00000000 32778      aditya     600        524288     2          dest         
0x00000000 11         aditya     600        524288     2          dest         
0x00000000 32780      aditya     600        4194304    2          dest         
0x00000000 32781      aditya     600        67108864   2          dest         
0x00000000 32784      aditya     600        524288     2          dest         
0x00000000 32785      aditya     600        4194304    2          dest         
0x00000000 32786      aditya     600        33554432   2          dest         
0x00000000 32807      aditya     600        524288     2          dest         
0xffffffff 32815      aditya     744        1024       0                       
0x0106b12f 32816      aditya     744        1024       0                       
0x00000000 60         aditya     600        524288     2          dest         



*/
