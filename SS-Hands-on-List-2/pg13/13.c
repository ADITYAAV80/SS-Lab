/*
NAME:13.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<signal.h>

int main(){

	pid_t pid;
	printf("Enter PID to be killed\n");
	scanf("%d",&pid);
	if(kill(pid,SIGSTOP)==0){
		printf("SIGSTOP Signal sent\n");
	} else{
		perror("kill");
	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg13$ ./13init.out &
[1] 18185
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg13$ ./13.out
Enter PID to be killed
18185
SIGSTOP Signal sent

[1]+  Stopped                 ./13init.out
aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg13$ cat /proc/18185/status | grep State
State:	T (stopped)

*/
