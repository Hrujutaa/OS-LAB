#include <stdio.h>
int main(){
int n,i;
int bt[10],wt[10],tat[10];
float avg_wt=0,avg_tat=0;
printf("Enter the number of processes: ");
scanf("%d",&n);

printf("enter burst time: ");
for(i=0;i<n;i++){
printf("process %d: ",i+1);
scanf("%d",&bt[i]);
}

wt[0]=0;
for(i=1;i<n;i++){
wt[i]=wt[i-1]+bt[i-1];
}

for(i=0;i<n;i++){
tat[i]=wt[i]+bt[i];
avg_wt+=wt[i];
avg_tat+=tat[i];
}

avg_wt/=n;
avg_tat/=n;
printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
for(i=0;i<n;i++){
printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
printf("\navg waiting time=%.2f\n",avg_wt);
printf("avg turnaround time=%.2f\n",avg_tat);
return 0;
}
