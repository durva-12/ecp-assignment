#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() 
{
  int i,ret;
  int s;
 
  for(i=1;i<=3;i++)
  ret=fork();
  if(ret == 0) {
	   for(i=1; i<=3; i++) {
			printf("child1: %d\n", i);
			}
			_exit(0);
			
		}
else {
		// parent process
		for(i=1; i<=3;i++) {
			printf("parent: %d\n", i);
			sleep(1);
			if(i == 3) {		
	
	
			waitpid(-1,&s,0);
			printf("parent exit:%d\n",WEXITSTATUS(s));
			}
		
}
}

	return 0;
	}
