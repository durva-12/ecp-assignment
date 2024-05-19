#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY		0x1234

typedef struct msg {
	
	int num1,num2,num3;
} msg_t;

int main() {
	int mqid, ret, s;
	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret= fork();
	if(ret == 0) {
		// child: initialize and send the message
		msg_t m1;
		m1.num2 = 22;
		m1.num1=20;
		ret = msgsnd(mqid, &m1, sizeof(m1.num1), 0);
		 ret = msgsnd(mqid, &m1, sizeof(m1.num2), 0);
		 printf("sender: message sent: %d%d\n", ret);
	}
	else {
		// parent: receive the message and print it
		msg_t m2;
		printf("receiver: waiting for the message...\n");
	m2.num3=m2.num1+m2.num2;
		ret = msgrcv(mqid, &m2, sizeof(m2.num3), 1, 0);
		printf("receiver: message received: %d \n", m2.num3);
	
		// wait for child and clean it up
		wait(&s);

		// destroy the message queue
	//	msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}








