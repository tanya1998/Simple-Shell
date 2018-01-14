#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
char cmd[256];
char *arg ;
char *argv[256];
while(1)
{	
	printf("gsh:>");
	gets(cmd);

	int i=0;
	int length =0;
	
	arg = strtok(cmd," ");
	if(strcmp(cmd,"exit")==0)
	{
		exit(0);
	}
	else
	{	
		while(arg!='\0')
	
		{	
		argv[i] = arg;
		arg = strtok (NULL," ");
		i++;
		}
		//printf("argv[1]: %s , argv[0]: %s",argv[1],argv[0]); 
		//builtin for cd 
		if(strcmp(argv[0],"cd")==0)
		{
		if(argv[1] == NULL)
		{
			printf("cd: Argument expected\n");
		}
		else
		{
			if(chdir(argv[1]) !=0)
			{
				printf("No such file or Directory\n");
			}
		}
		}
	
		else if(fork()==0)
		{
		if(execve("/home/tanya/date",argv,NULL)==-1)
		{
			
			printf("Error\n");
		}
		}
		else
		{
		wait(NULL);
		}
	}
	for(i=0;i<256;i++)
	{
		argv[i] = NULL;
	}
	printf("\n");	
	
}
	return 0;
}
