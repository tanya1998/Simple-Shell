#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
char cmd[256];
char *arg ;
char *argv[256];
char history[2000][2000];
int histn =0;
char cd[2000][2000];
strcpy(cd[0],"/home/tanya");
int cnt =0;
while(1)
{	
	printf("gsh:>");
	gets(cmd);
	strcpy(history[cnt],cmd);
	cnt++;
	int i=0;
	int length =0;
	char sentence[1000];
   	
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
		char *path = (char *)malloc(sizeof(char)); 
		strcpy(path,"/home/tanya/");
		strcat(path,argv[0]);
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
				if(strcmp(argv[1],"~")==0)
				{
					chdir("/home/tanya");
					histn++;
					getcwd(cd[histn],sizeof(cd[histn]));
					
				}
				else if(strcmp(argv[1],"-")==0)
				{
					chdir(cd[histn-1]);
					histn++;
					getcwd(cd[histn],sizeof(cd[histn]));
					
				}
				else
				printf("No such file or Directory\n");
			}
			else
			{	
				histn++;
				getcwd(cd[histn],sizeof(cd[histn]));
				
			}
		}
			
		}
		else if(strcmp(argv[0],"pwd")==0)
		{
			char cwd[2056];
			printf(getcwd(cwd,sizeof(cwd)));
		}
		else if(strcmp(argv[0],"echo")==0)
		{
			for(int l =1;l<i;l++)
				printf("%s ",argv[l]);
		}
		else if(strcmp(argv[0],"history")==0)
		{
			for(int j=0;j<cnt;j++)
			{
				printf("%d %s\n",j+1,history[j]);
			}
		}
		else if(fork()==0)
		{
		
		if(execve(path,argv,NULL)==-1)
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
