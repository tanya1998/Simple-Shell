#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
 int main(int argn, char* file[])
 {
	if(argn<=1)
	{time_t showtime;
	showtime = time(NULL);
	printf(ctime(&showtime));
	}

	else
	{
		if(strcmp(file[1],"-r")==0)
			{
				if(argn==2)
				printf("Invalid command:- Filename required\n");
				else
				{
				char filetime[100];
				struct stat t;
				if (!stat(file[2],&t)) 
				{

  					strftime(filetime, 100, "%d/%m/%Y %H:%M:%S", localtime(&t.st_ctime));
  					printf("\nLast modified date and time = %s\n", filetime);
 				 } 
				else 
				{
  					printf("Cannot display the time. No Such File.\n");
  				}
				}
			}
		if(strcmp(file[1],"-I")==0)
		{
			time_t now = time(NULL);
   			struct tm *t = localtime(&now);
   			printf( "%d-%d-%d\n", t->tm_year+1900 ,t->tm_mon+1,t->tm_mday);
		}
		else
		{
			printf("No such option in date :- only -r and-I\n");
		}
	
	}

 	return 0;
	}
