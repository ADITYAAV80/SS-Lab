/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
15. Write a program to display the environmental variable of the user (use environ).
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main(){
	int count =0;
	for(char **env=environ;*env!=NULL;env++){
		printf("%d::%s\n",count,*env);
		count+=1;
	}
}
