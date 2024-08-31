#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct flight{
	int flight_no;
	int ticket_no;
};
int main(){

    int fd = open("records.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(fd==-1) {
        perror("Error opening file");
        return 1;
    }
	struct flight fl;
	for(int i=0; i<4; i++) {
        	fl.flight_no = i+1;
 		fl.ticket_no = 0;
        	write(fd, &fl, sizeof(struct flight));
    	}
}
