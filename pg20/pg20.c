#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	if (argc <2){
		printf("Please pass the priority value \n");
		exit(0);
	}
	int add_p = atoi(argv[1]);

	int curr_p = nice(0);
	printf("Current priority : %d\n",curr_p);


	int new_p = nice(add_p);
	printf("New priority : %d\n",new_p);

}
