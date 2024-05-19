#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() 
{
  int i,ret;
  int s,j;
 
  while(1){
  ret=fork();
  if(ret == 0) {
	   for(i=1; i<=3; i++) {
			printf("child: %d\n", i);
		}
		_exit(0);
			
}	
	else 
		
			if(ret == -1){
		for(i=1;i<=3;i++)
		{		
     		break;

}

else{
 i++;
   
   printf("child count=%d\n",i);
 

}
}
		for(j=1; j<=3;j++) {
		wait(&s);
		
			}
	
	
	return 0;
	}
	}

