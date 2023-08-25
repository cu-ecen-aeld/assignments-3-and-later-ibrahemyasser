#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <syslog.h>
void openlog(const char *ident, int option, int facility);
void syslog(int priority, const char *format, ...);


int main(int argc,char *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr,"Error:Not enough arguments\n");
		exit(EXIT_FAILURE);

	}

	const char *writefile = argv[1];
	const char *writestr = argv[2];


	FILE *file = fopen(writefile,"w");
	
	if(file== NULL)
	{
		perror("Erro opening the file");
		syslog(LOG_ERR, "Error opening file %s", writefile);
        	exit(EXIT_FAILURE);
	}
	
	fprintf(file, "%s\n", writestr);
    	fclose(file);	


	openlog("writer", LOG_CONS | LOG_PID, LOG_USER);
        syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", writestr, writefile);
        closelog();

        printf("Content written to %s successfully.\n", writefile);

        return EXIT_SUCCESS;

}
