#include <stdio.h>

int main() {
    int n, at[10], wt[10], bt[10], tat[10], ct[10];
    int sum = 0; 
    float total_tat = 0, total_wt = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter the Arrival time and Burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Compute the completion time
    sum = 0; 
    for (int i = 0; i < n; i++) {
        if (sum < at[i]) {  
            sum = at[i]; 
        }
        sum = sum + bt[i];
        ct[i] = sum;
    }

    // Compute the turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        total_tat += tat[i];
    }

    // Compute the waiting time
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %f\n", total_tat / n);
    printf("Average Waiting Time: %f\n", total_wt / n);

    return 0;
}

