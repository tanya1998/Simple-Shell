#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char*argv[])
{
 struct dirent** fileList;
 char cwd[2056];
 int totalfiles =0;

 if(getcwd(cwd, sizeof(cwd)) == NULL)
	{
		printf("Error finding the directory \n");
		exit(0);
	}
 printf("Current Working Directory = %s\n",cwd);
 totalfiles = scandir(cwd, &fileList, NULL, alphasort);
 if(totalfiles ==0)
	{
		printf("No Files in the current working Directory :- %s \n",cwd);
		exit(0);
	}
 printf("Total:- %d\n",totalfiles);
 int i=0;
 for(i=0; i<totalfiles;i++)
 	{
		printf("%s\n",fileList[i]->d_name);
	}
 return 0;
 

}
