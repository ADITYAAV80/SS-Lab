/*
NAME:6.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM: 6. Write a simple program to create three threads.
DATE: 05 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* print_threadno(void* num){
	printf("This is thread %d\n",*((int*)num));
	free(num);
	sleep(40);
}

int main() {

	printf("PID:%d\n",getpid());

	pthread_t t1,t2,t3;
	int *num1 = malloc(sizeof(int));
	int *num2 = malloc(sizeof(int));
	int *num3 = malloc(sizeof(int));

	*num1 = 1;
	*num2 = 2;
	*num3 = 3;

	pthread_create(&t1,NULL,print_threadno,num1);
	pthread_create(&t2,NULL,print_threadno,num2);
	pthread_create(&t3,NULL,print_threadno,num3);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	return 0;
}



/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg6$./a.out
PID:18639
This is thread 1
This is thread 2
This is thread 3

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg6$ ps -L 18639
    PID     LWP TTY      STAT   TIME COMMAND
  18639   18639 pts/2    Sl+    0:00 ./a.out
  18639   18640 pts/2    Sl+    0:00 ./a.out
  18639   18641 pts/2    Sl+    0:00 ./a.out
  18639   18642 pts/2    Sl+    0:00 ./a.out

*/
