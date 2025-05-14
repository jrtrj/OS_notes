#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], priority[n], ct[n], tat[n], wt[n];
    int remaining_bt[n]; // Tracks remaining burst time for preemption
    int current_time = 0, completed = 0;

    // Input process details
    printf("Enter Process ID, Arrival Time, Burst Time, and Priority:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &priority[i]);
        remaining_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Preemptive Priority Scheduling Logic
    while (completed != n) {
        int highest_priority_job = -1;
        int highest_priority = 9999; // Lower number = higher priority

        // Find the job with the highest priority (smallest number) at current_time
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && remaining_bt[i] > 0 && priority[i] < highest_priority) {
                highest_priority = priority[i];
                highest_priority_job = i;
            }
        }

        if (highest_priority_job == -1) {
            current_time++; // CPU idle if no process is available
        } else {
            remaining_bt[highest_priority_job]--; // Execute for 1 unit
            current_time++;

            // If the job is completed
            if (remaining_bt[highest_priority_job] == 0) {
                completed++;
                ct[highest_priority_job] = current_time;
                tat[highest_priority_job] = ct[highest_priority_job] - at[highest_priority_job];
                wt[highest_priority_job] = tat[highest_priority_job] - bt[highest_priority_job];
            }
        }
    }

    // Calculate averages and print results
    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", 
               pid[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    printf("Average Waiting Time: %.2f\n", avg_wt / n);

    return 0;
}
