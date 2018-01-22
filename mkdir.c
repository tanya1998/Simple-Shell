#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int main(int argn, char *argc[])
{	
	printf("%d",argn);
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
	if(argn ==3 && strcmp("-v",argc[1])==0)
	{
		if(mkdir(argc[2],S_IRWXU | S_IRGRP| S_IXGRP | S_IROTH | S_IXOTH )!=0)
			{printf("mkdir: cannot create directory ‘%s’: File exists",argc[2]);
			exit(0);
			}
		else
		{
			printf("mkdir: created directory '%s'",argc[2]);
		}
	}
	if(argn ==3 && strcmp("-p",argc[1])==0)
	{
		char *arg = strtok(argc[2],"/");
		int p =0;
		char cwd[2056];
		char *argv[256];
		while(arg!='\0')
	
		{	
		argv[p] = arg;
		printf("%s",argv[p]);
		arg = strtok (NULL,"/");
		p++;
		}
		int k = p;
		for(p=0;p<k;p++)
		{
			if(mkdir(argv[p],S_IRWXU | S_IRGRP| S_IXGRP | S_IROTH | S_IXOTH)==0)
			{
			}
			else
			{
		           
			}
			printf("%d",chdir(argv[p]));
			printf("%s\n",getcwd(cwd,sizeof(cwd)));
			
		}
		
	}
	printf("\n");
	return 0;
}
