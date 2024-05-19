#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() 
{
 char ch='A';
 int arr[56],ret;
 ret=pipe(arr);
 void sigint_handler(int sig) {
	printf("SIGINT caught: %d\n", sig);
}
 int count=0;
 while(1) {
     write(arr[1],&ch,1);
	 count++;
	 printf("bytes written:%d\n",count);
	 }
    int i=1;
	//step2: register signal handler
	signal(SIGINT, sigint_handler);
	while(1) {
		printf("running: %d\n", i++);
		sleep(1);
	}
	return 0;
}
