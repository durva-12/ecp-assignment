#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() 
{
  int i,ret1,ret2,ret3,s;
  ret1=fork();
  if(ret1 == 0) {
	   for(i=1; i<=3; i++) {
			printf("child1: %d\n", i);
			}
			_exit(0);
			
		}	
	ret2=fork();
	if(ret2 == 0) {
		
		for(i=1; i<=3; i++) {
			printf("child2: %d\n", i);
			}
			_exit(0);
			
		}	
	ret3=fork();
	if(ret3 == 0)
	    {
		for(i=1;i<=3;i++){
		printf("child3:%d\n",i);
		}
		_exit(0);
		
	}
	else {
		
		for(i=1; i<=3; i++) {
			printf("parent: %d\n", i);
			sleep(1);
			if(i == 3) {
				wait(&s);
				printf("child exit: %d\n", WEXITSTATUS(s));
			}
			}
			}
	return 0;
	}
