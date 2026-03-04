#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], rt[n], wt[n], tat[n], ct[n];

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }

    while(completed < n) {
        int max_index = -1;
        int max_remaining = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] > max_remaining) {
                    max_remaining = rt[i];
                    max_index = i;
                }
            }
        }

        if(max_index == -1) {
            time++;  
        } else {
            rt[max_index]--; 
            time++;

            if(rt[max_index] == 0) {
                completed++;
                ct[max_index] = time;
                tat[max_index] = ct[max_index] - at[max_index];
                wt[max_index] = tat[max_index] - bt[max_index];
            }
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
