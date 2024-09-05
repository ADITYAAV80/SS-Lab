/*
NAME: 2.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
2. Write a program to print the system resource limits. Use getrlimit system call. 
DATE: SEP 5 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/resource.h>

int displayresources(int resource, char *name){

	struct rlimit r;
	int ret = getrlimit(resource,&r);
	static int count =1;
	if (ret==0){
		printf("%d)%s\n",count,name);
		printf("Soft limit: %ld\n",r.rlim_cur);
		printf("Hard limit: %ld\n",r.rlim_max);
		count++;
	}
	else{
		perror("getrlimit error");
	}
}


int main(){

	displayresources(RLIMIT_CPU,"CPU TIME");
	displayresources(RLIMIT_FSIZE,"FILE SIZE");
	displayresources(RLIMIT_STACK,"STACK SIZE IN BYTES");
	displayresources(RLIMIT_DATA,"DATA SEGMENT SIZE");
	displayresources(RLIMIT_NOFILE,"NUMBER OF FILES");
	displayresources(RLIMIT_AS,"VIRTUAL ADDRESS SPACE SIZE");
	displayresources(RLIMIT_NPROC,"NUMBER OF PROCESSES");
	displayresources(RLIMIT_MEMLOCK,"MAXIMUM BYTES LOCKED INTO MEMORY");
	displayresources(RLIMIT_LOCKS,"NUMBER NUMBER OF FILE LOCKS");
	displayresources(RLIMIT_SIGPENDING,"NUMBER OF SIGNALS WAITING FOR A PROCESS");
	displayresources(RLIMIT_MSGQUEUE,"MAX SIZE FOR MESSAGE QUEUE IN BYTES");
	displayresources(RLIMIT_NICE,"MAX VALUE OF NICE");
	displayresources(RLIMIT_RTPRIO,"MAX PRIORITY FOR REALTIME SCHEDULING POLICY(FIFO,RR)");
	displayresources(RLIMIT_RTTIME,"MAX TIME IN RT MODE");

}

/* OUTPUT

1)CPU TIME
Soft limit: -1
Hard limit: -1
2)FILE SIZE
Soft limit: -1
Hard limit: -1
3)STACK SIZE IN BYTES
Soft limit: 8388608
Hard limit: -1
4)DATA SEGMENT SIZE
Soft limit: -1
Hard limit: -1
5)NUMBER OF FILES
Soft limit: 1024
Hard limit: 1048576
6)VIRTUAL ADDRESS SPACE SIZE
Soft limit: -1
Hard limit: -1
7)NUMBER OF PROCESSES
Soft limit: 60951
Hard limit: 60951
8)MAXIMUM BYTES LOCKED INTO MEMORY
Soft limit: 2006851584
Hard limit: 2006851584
9)NUMBER NUMBER OF FILE LOCKS
Soft limit: -1
Hard limit: -1
10)NUMBER OF SIGNALS WAITING FOR A PROCESS
Soft limit: 60951
Hard limit: 60951
11)MAX SIZE FOR MESSAGE QUEUE IN BYTES
Soft limit: 819200
Hard limit: 819200
12)MAX VALUE OF NICE
Soft limit: 0
Hard limit: 0
13)MAX PRIORITY FOR REALTIME SCHEDULING POLICY(FIFO,RR)
Soft limit: 0
Hard limit: 0
14)MAX TIME IN RT MODE
Soft limit: -1
Hard limit: -1


aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg2$ ulimit -a
real-time non-blocking time  (microseconds, -R) unlimited
core file size              (blocks, -c) 0
data seg size               (kbytes, -d) unlimited
scheduling priority                 (-e) 0
file size                   (blocks, -f) unlimited
pending signals                     (-i) 60951
max locked memory           (kbytes, -l) 1959816
max memory size             (kbytes, -m) unlimited
open files                          (-n) 1024
pipe size                (512 bytes, -p) 8
POSIX message queues         (bytes, -q) 819200
real-time priority                  (-r) 0
stack size                  (kbytes, -s) 8192
cpu time                   (seconds, -t) unlimited
max user processes                  (-u) 60951
virtual memory              (kbytes, -v) unlimited
file locks                          (-x) unlimited

*/

