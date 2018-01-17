#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int main(int argn, char *argc[])
{
	if(argn<=1)
	{
		printf("Invalid Command:- More Parameters expected");
		exit(0);

	}
	if(strcmp("-m",argc[1])==0 &&( argn == 2 || argn == 3))
	{
		printf("Too few Arguments");
		exit(0);
	}
	if(argn==2)
	{
		
		if(mkdir(argc[1],S_IRWXU | S_IRGRP| S_IXGRP | S_IROTH | S_IXOTH )!=0)
			{printf("Directory already exists");
			exit(0);
			}
			
	}
	if(argn ==4 && strcmp("-m",argc[1])==0)
	{
		if(mkdir(argc[4],atoi(argc[3]))!=0)
			{printf("Directory already exists");
			exit(0);
			}
	}
	return 0;
}
