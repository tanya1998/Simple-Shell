#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argn, char* file[])
{
	printf("%d",argn);
 FILE *fp;
 char line[100000];
 char *status;
 if(argn<=1)
	{
		printf("Invalid Cat Command: cat 'filename' \n");
		exit(0);
	}
 int i =1;
 for(;i<argn;i++)
	{
		fp = fopen(file[i],"r");
		if(fp == NULL)
		{
			printf("File Not Found");
			exit(0);
		}
		do
		{
			status = fgets(line,sizeof(line),fp);
			printf("%s",line);
		}
		while(status);
		
	} 
}
