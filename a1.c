#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main() {
   int arr1[2],ret,res,num1,num2,n1,n2,arr2[2];
   int r,s;
   printf("parent started.\n");
   ret=pipe(arr1);
   ret = pipe(arr2);
   if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}
   
   ret=fork();
   if(ret==0) {
      close(arr1[0]);
	  close(arr2[1]);
      printf("child:enter  numbers");
	  scanf("%d",&num1);
	  printf("enter nO:");
	  scanf("%d",&num2);
	  ret=write(arr1[1],&num1,sizeof(num1));
	  printf("child: data written in pipe: %d bytes\n", ret);
	  ret=write(arr1[2],&num1,sizeof(num2));
	 printf("child: data written in pipe: %d bytes\n", ret);
     read(arr2[0],&res,sizeof(res));
	 printf("result:%d\n",res);

	 close(arr2[0]);
	 close(arr1[1]);

   }
   else{
     close(arr1[1]);
	 close(arr2[0]);
     printf("parent is waiting for data....\n");
	 read(arr1[0],&n1,sizeof(n1));
	 read(arr1[0],&n2,sizeof(n2));
	 r=n1+n2;

	 write(arr2[1],&r,sizeof(r));
	 close(arr2[1]);
	 close(arr1[0]);
	 waitpid(-1,&s,0);
	 printf("parent completed!\n");
	} 
return 0;
	}
