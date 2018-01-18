#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char*argv[])
{
 struct dirent** fileList;
 if(argc ==1)
 {
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

 	{	char *str = fileList[i]->d_name;
		if(strcmp(fileList[i]->d_name,".")!=0 && strcmp(fileList[i]->d_name,"..")!=0 )
		if(str[0] != '.')
		printf("%s\n",fileList[i]->d_name);
	}
}
else if (argc ==2)
	{
		if(strcmp(argv[1],"-a")==0)
		{
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
		char *str = fileList[i]->d_name;
		printf("%s\n",fileList[i]->d_name);
		}	
		}
		else if(strcmp(argv[1],"-A")==0)
		{
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
		char *str = fileList[i]->d_name;
		if(strcmp(fileList[i]->d_name,".")!=0 && strcmp(fileList[i]->d_name,"..")!=0 )
		printf("%s\n",fileList[i]->d_name);
		}	
		}
		else
		{
			
			if(chdir(argv[1])==0)
			{
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
		char *str = fileList[i]->d_name;
		if(strcmp(fileList[i]->d_name,".")!=0 && strcmp(fileList[i]->d_name,"..")!=0 )
		if(str[0] != '.')
		printf("%s\n",fileList[i]->d_name);
		}	}
		else
		    printf("Directory Not found");
				
		}
	}
else if (argc == 3)
	{
		if(strcmp(argv[1],"-a")==0)
		{
			if(chdir(argv[2])==0)
			{
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
		char *str = fileList[i]->d_name;
		printf("%s\n",fileList[i]->d_name);
		}	}
		else
		    printf("Directory Not found");
		}
		if(strcmp(argv[1],"-A")==0)
		{
			if(chdir(argv[2])==0)
			{
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
		if(strcmp(fileList[i]->d_name,".")!=0 && strcmp(fileList[i]->d_name,"..")!=0 )
		printf("%s\n",fileList[i]->d_name);
		}	}
		else
		    printf("Directory Not found");
		}
		
	}
 return 0;
 

}
