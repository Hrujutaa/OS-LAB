#include <stdio.h>
int main(){
	int n,m,i,j,k;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&m);
	int alloc[n][m],max[n][m],need[n][m];
	int avail[m],finish[n],safeSeq[n];
	printf("\nEnter allocation matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\nEnter maximum matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n Enter available resources:\n");
	for(i=0;i<m;i++){
		scanf("%d",&avail[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<n;i++){
		finish[i]=0;
	}
	int count=0;
	while(count<n){
		int found=0;
		for(i=0;i<n;i++){
			if(finish[i]==0){
				int flag=1;
				for(j=0;j<m;j++){
					if(need[i][j]>avail[j]){
						flag=0;
						break;
					}
				}
				if(flag){
					for(k=0;k<m;k++){
						avail[k]+=alloc[i][k];
						safeSeq[count++]=i;
						finish[i]=1;
						found=1;
					}
				}
			}
			if(found==0){
				printf("\nSystem is Not in safe state(Deadlock possible).\n");
				return 0;
			}
		}
		printf("\nSystem is in SAFE state\nSafe Sequence: ");
		for(i=0;i<n;i++){
			printf("P%d",safeSeq[i]);
		}
		printf("\n");
		return 0;
	}
}
