/* forkbomb.c
   Michael Craze
   http://projectcraze.ath.cx
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void usage(char *s);

int main(int argc, char **argv){
	int i, fv, iter;
	if(argc != 2){
		usage(argv[0]);
	}
	iter=atoi(argv[1]);
	for(i=0;i<iter;i++){
		if((fv=fork())==-1){
			perror(argv[0]);
		}
		else if(fv==0){
			sleep(1000);
		}
		else{
			printf("Process: %8d -- i/iter = %d/%d\n",getpid(),i,iter);
			fflush(stdout);
		}
	}
	return 0;
}

void usage(char *s){
	fprintf(stderr,"Usage: %s <iterations>\n",s);
	fprintf(stderr," *Note: fork calls scale logrithmically\n");
	exit(1);
}
