/*
NAME: 3.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM: 3. Write a program to set (any one) system resource limit. 
Use setrlimit system call.
DATE: 5 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/resource.h>

int main(){

	struct rlimit r;

	if (getrlimit(RLIMIT_CPU, &r) == 0) {
		printf("Resource limit of CPU Before\n");
        	printf("Soft limit = %ld, Hard limit = %ld\n",r.rlim_cur,r.rlim_max);
    	} else {
        	perror("getrlimit");
    	}

	r.rlim_cur = 10;
	r.rlim_max = 200;
	int ret = setrlimit(RLIMIT_CPU,&r);
	if (ret ==0){
		printf("Resource limit of CPU set sucsessfully\n");
	}
	else{
		perror("setrlimit error");
	}

	if (getrlimit(RLIMIT_CPU, &r) == 0) {
		printf("Resource limit of CPU After\n");
        	printf("Soft limit = %ld, Hard limit = %ld\n",r.rlim_cur,r.rlim_max);
    	} else {
        	perror("getrlimit");
    	}


}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg3$ ./a.out
Resource limit of CPU Before
Soft limit = -1, Hard limit = -1
Resource limit of CPU set sucsessfully
Resource limit of CPU After
Soft limit = 10, Hard limit = 200

*/
