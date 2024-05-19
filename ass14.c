#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() 
{
int ret1,ret2,ret3,s,i;  
  ret1=fork();
  if(ret1 == 0) {
  ret2=fork();
	  if(ret2 == 0) {
ret3=fork();
if(ret3 == 0) {
for(i=1; i<=5; i++) {

			printf("child3: %d\n", i);
			sleep(1);
			if(i==3){
			waitpid(-1,&s,0);
			printf("child exit:%d\n",WEXITSTATUS(s));
			}
			}
		_exit(0);
}

		for(i=1; i<=5; i++) {
			printf("child2: %d\n", i);
			sleep(1);
			if(i==3){
			waitpid(-1,&s,0);
			printf("child exit:%d\n",WEXITSTATUS(s));

		}
		}
		_exit(0);
}

for(i=1;i<=5;i++)
{
printf("child1 :%d\n", i);
sleep(1);
if(i==3){
waitpid(-1,&s,0);
printf("child exit:%d\n",WEXITSTATUS(s));
}
}

_exit(0);
	
	}	
	
	
	return 0;
	}
