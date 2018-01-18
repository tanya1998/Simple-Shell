#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argn, char *argv[])
{	
	

	
	if(argn<=1)
	{
		printf("Invalid Command:- More Parameters expected");

	}
	else
	if(argn==2)
	{
		if(strcmp(argv[1],"-d")==0 || strcmp(argv[1],"-i")==0 )
		printf("Invalid Command:- No Directory");
		else
		{	
			if(fopen(argv[1],"r")!=NULL)
			{
				if(remove(argv[1])==0)
				{
				}
				 
			}
			else
			{
				printf("No Such File or is a Directory(--r)");
			}
		}
	}
	else
	if(strcmp(argv[1],"-d")==0 )
	{
		if(remove(argv[2])==0)
		{
			
		}
		else if(!opendir(argv[2]))
		{
			printf("No Such File or Directory");
		}
		else
		{
			printf("Not an Empty Directory");
		}
				 
	}
	else if(strcmp(argv[1],"-i")==0)
	{
		
			
			if(fopen(argv[2],"r")!=NULL)
			{
				printf("remove regular file '%s'?",argv[2]);
				char choice[10];
				gets(choice);
				if(choice[0] == 'y' || choice[0] == 'Y')
					remove(argv[2]);
				
				 
			}
			else
			{
				printf("No Such File or is a Directory(--r)");
			}
		
	}
	
	
}
