#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void pidd(char *ar[]);
void uidd(char *ar[]);
void gidd(char *ar[]);

void pidd(char *ar[]){
	printf("%s: Your current PID is: %ld\n",ar[0], (long)getpid());
};
void uidd(char *ar[]){
	printf("%s: Your current UID is: %ld\n", ar[0], (long)getuid());
};
void gidd(char *ar[]){
	printf("%s: Your current GID is: %ld\n", ar[0], (long)getgid());
};
