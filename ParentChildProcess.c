#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid;
	printf("parent process started\n");
	printf("parent pid: %d\n",getpid());
	pid=fork();
	if(pid<0){
		printf("process creation failed");
	}else if(pid==0){
		printf("child process\n");
		printf("child pid:%d\n",getpid());
		printf("parent pid:%d\n",getpid());
		execl("/bin/ls","ls","-l",NULL);
		printf("Exec failed\n");
	}
	else{
		wait(NULL);
		printf("\nChild process completed\n");
		printf("Parent process exiting\n");
	}
	return 0;
}
