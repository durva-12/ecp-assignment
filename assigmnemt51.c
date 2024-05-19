#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
 int sig,pid,ret;
 printf("enter values for pid and signal number");
 scanf("%d%d",&pid,&sig);
  ret=kill(sig,pid);
 if(ret==0)
  
   printf("process killed succesfully");
  
 else
  
   printf("process not killed succesfully");
  
  
 } 
