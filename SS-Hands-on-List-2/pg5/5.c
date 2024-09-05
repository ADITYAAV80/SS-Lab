/*
NAME:5.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
5. Write a program to print the system limitation of
 a. maximum length of the arguments to the exec family of functions.
 b. maximum number of simultaneous process per user id.
 c. number of clock ticks (jiffy) per second.
 d. maximum number of open files
 e. size of a page
 f. total number of pages in the physical memory
 g. number of currently available pages in the physical memory
DATE: 05 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){

	long maxarg = sysconf(_SC_ARG_MAX);
	printf("a) Maximum length of arguments to exec family of functions: %ld\n",maxarg);

	long maxproc = sysconf(_SC_CHILD_MAX);
	printf("b) Maximum simulaenous processes per ID: %ld\n",maxproc);

	long clktickpersec = sysconf(_SC_CLK_TCK);
	printf("c) Number of clock tick per second: %ld\n",clktickpersec);

	long maxopenfiles = sysconf(_SC_OPEN_MAX);
	printf("d) Maximum number of open files: %ld\n",maxopenfiles);

	long maxpagesize = sysconf(_SC_PAGESIZE);
	printf("e) Maximum size of a page: %ld\n",maxpagesize);

	long maxpages = sysconf(_SC_PHYS_PAGES);
	printf("f) Total number of pages in the physical memory: %ld\n",maxpages);

	long maxavailpages = sysconf(_SC_AVPHYS_PAGES);
	printf("g) Maximum simulaenous processes per ID: %ld\n",maxavailpages);

}

/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg5$ ./a.out
a) Maximum length of arguments to exec family of functions: 2097152
b) Maximum simulaenous processes per ID: 60951
c) Number of clock tick per second: 100
d) Maximum number of open files: 1024
e) Maximum size of a page: 4096
f) Total number of pages in the physical memory: 3919639
g) Maximum simulaenous processes per ID: 1965103


*/
