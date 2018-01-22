#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argn, char* file[])
{
 FILE *fp;
 char line[100000];
 char *status;
 if(argn<=1)
	{
		printf("Invalid Cat Command: cat 'filename' \n");
		exit(0);
	}
 int i =1;
if(strcmp(file[1],"-n")!=0 && strcmp(file[1],"-b")!=0 )
 for(;i<argn;i++)
	{
		fp = fopen(file[i],"r");
		if(fp == NULL)
		{
			printf("File Not Found");
			exit(0);
		}
		int count =1;
		do
		{
			status = fgets(line,sizeof(line),fp);
			printf("%s",line);
			count++;
		}
		while(status);
		
	} 
else
	{
	if(argn ==2)
	printf("More parameters required:- Filename Missing");
	else if(strcmp(file[1],"-n")==0)
	{ for(i=2;i<argn;i++)
	{
		fp = fopen(file[i],"r");
		if(fp == NULL)
		{
			printf("File Not Found");
			exit(0);
		}
		int count =1;
		do
		{
			status = fgets(line,sizeof(line),fp);
			
			printf("%d%s",count,line);
			count++;
			
			
		}
		while(status);
	}
	}
	else
	{
		for(i=2;i<argn;i++)
	{
		fp = fopen(file[i],"r");
		if(fp == NULL)
		{
			printf("File Not Found");
			exit(0);
		}
		int count =1;
		do
		{
			status = fgets(line,sizeof(line),fp);
			if(strcmp(line,"\n")!=0)
			{printf("%d%s",count,line);
			count++;
			}
			else
			{printf("%s",line);
			}
		}
		while(status);
	}
	}
}
printf("\n");
return 0;
}
