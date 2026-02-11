#include <stdio.h>
#define MAX_PROCESS 10
void findWaitingTime(int process[],int n,int bt[],int wt[]){
	int remaining_bt[MAX_PROCESS];
	for(int i=0;i<n;i++){
		remaining_bt[i]=bt[i];
	}
	int current_time=0;
	while(1){
		int min_bt=9999;
		int shortest=-1;
		int done=1;
	for(int i=0;i<n;i++){
		if(remaining_bt[i]>0 && remaining_bt[i]<min_bt){
			min_bt=remaining_bt[i];
			shortest=i;
			done=0;
		}
	}
	if(done){
		break;
	}
	wt[shortest]=current_time;
	current_time++;
	remaining_bt[shortest]--;
	}
}
void findTurnAroundTime(int process[], int n,int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
}
void calculateAvgTime(int process[],int n,int bt[]){
	int wt[MAX_PROCESS],tat[MAX_PROCESS];
	int total_wt=0,total_tat=0;
	findWaitingTime(process,n,bt,wt);
	findTurnAroundTime(process,n,bt,wt,tat);
	for(int i=0;i<n;i++){
		total_wt+=wt[i];
		total_tat+=tat[i];
	} 
	printf("process\tBurst time\tWaiting time\tTurnaround time\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting time: %.2f",(float)total_wt/n);
	printf("turn around time: %.2f",(float)total_tat/n);
}
int main(){
	int process[]={1,2,3,4};
	int burst_time[]={6,8,7,3};
	int n=sizeof(process)/sizeof(process[0]);
	calculateAvgTime(process,n,burst_time);
	return 0;
}

