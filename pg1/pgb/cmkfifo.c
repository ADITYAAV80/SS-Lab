/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <sys/stat.h>
#include <stdio.h>
int main(){

	const char *path="/tmp/myfifo";
	mode_t mode = 0666;
	int ret = mkfifo(path, mode);
	if(ret==-1){
		perror("mknod");
	}
	else{
		printf("FIFO created at path:%s\n",path);
	}
}
