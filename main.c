/*	For Linux Libaries	*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/*	 Headers 	*/

#include "pidgiduid.h"

/*	preprocessor 	*/
#define RW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
static int c();
static int o();
int main(int argc, char *argv[]){
	char line[3];
	int fail = 0;
	if (fail = fgets(line, sizeof(line), stdin) == NULL){
		perror("Fgets error:");
		exit(EXIT_FAILURE);
	}
	if(strcmp(line, "c") == 0){
		printf("Joining in the function for create\n");
		c();
	}
	if(strcmp(line, "o") == 0){
		printf("Joining in the function for open\n");
		o();
	}
	if(strcmp(line, "uf") == 0){
		printf("0.gid, 1.pid, 2.uid?\n");
		signed get = 0;
		scanf("%d", &get);
		if(get < 0 && get > 2){
			printf("Too long\n");
			exit(EXIT_FAILURE);
		}
		void (*ptr[])(char *argv[]) = { gidd, pidd, uidd};
		(*ptr[get])(argv);
	}
}
static int c(){
	char name[256];	
	scanf("%s", name);	
	int file = 0;
	if (file = creat(name, RW) == -1){
		perror("Creat error:");
		exit(errno);
	}
};

static int o(){
		char name[256];
		printf("Enter file name\n");
		scanf("%s", name);
		FILE *fp = fopen(name, "r+");
		if (!fp){
			perror("Open Error:");
			exit(EXIT_FAILURE);
		}
		printf("Enter options\n");
		char options[2];
		scanf("%s", options);
		options[2] = '\0';
		 int sek = 0;
		if (strcmp(options, "-s") == 0){
			
			printf("How much?\n");
			scanf("%d", &sek);
			fseek(fp, sek, SEEK_CUR);
			
		};
		printf("Enter options2\n");
		char options2[2];
		scanf("%s", options2);
		options2[2] = '\0';
		if (strcmp(options2, "-w") == 0){
			printf("Enter somewhat to put in file\n");
			char text[BUFSIZ];
			scanf("%s", text);
			fputs(text, fp);
		}
		fclose (fp);
		exit(EXIT_SUCCESS);

};
