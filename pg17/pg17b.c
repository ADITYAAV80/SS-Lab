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
		perror("read lock error :\n");
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
		perror("write lock error :\n");
	}
	else{
		printf("Writelock set\n");
	}

	int w = write(fd,&buf,sizeof(int));
	if(w==-1){ perror("Error writing : \n");}
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
		perror("Lock release error\n");
	}
	close(fd);
}
