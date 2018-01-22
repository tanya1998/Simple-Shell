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
		getcwd(path,sizeof(path));
		//strcpy(path,current);
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
		printf("\n");	
		}
		else if(strcmp(argv[0],"pwd")==0)
		{
			char cwd[2056];
			printf(getcwd(cwd,sizeof(cwd)));
			printf("\n");
		}
		else if(strcmp(argv[0],"echo")==0)
		{
			if(i >1)
			{if(strcmp(argv[1],"-n")==0 || strcmp(argv[1],"-E")==0 )
			{
			for(int k =2;k<i;k++)
			{char *ech = strtok(argv[k],"\\'");
			
			int p =0;
		
			char *echv[256];
			while(ech!='\0')
	
			{	
			echv[p] = ech;
			//printf("%s",echv[p]);
			ech = strtok (NULL,"\\'");
			p++;
			}
			for(int l =0;l<p;l++)
				{if(strcmp(echv[l],"")==0 && l!=0)
					printf("%s","\\");
				printf("%s",echv[l]);}
			printf(" ");
			}
			}
			else
			{for(int k=1;k<i;k++)
			{char *ech = strtok(argv[k],"\\'");
			
			int p =0;
		
			char *echv[256];
			while(ech!='\0')
	
			{	
			echv[p] = ech;
			//printf("%s",echv[p]);
			ech = strtok (NULL,"\\'");
			p++;
			}
			
			for(int l =0;l<p;l++)
				{if(strcmp(echv[l],"")==0 && l!=0)
					printf("%s","\\");
				printf("%s",echv[l]);}
			printf(" ");
			}}
			if(strcmp(argv[1],"-n")!=0)
			printf("\n");}
			else
			printf("\n");
			
		}
		else if(strcmp(argv[0],"history")==0)
		{
			for(int j=0;j<cnt;j++)
			{
				printf("%d %s\n",j+1,history[j]);
			}
			printf("\n");
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
	
}
	return 0;
}
