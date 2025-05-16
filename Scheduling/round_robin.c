#include <stdio.h>

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int pid[n], at[n], bt[n], remaining_bt[n], ct[n], tat[n], wt[n];
    int current_time = 0, completed = 0;

    // Input process details
    printf("Enter Process ID, Arrival Time, and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        remaining_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Round Robin Scheduling Logic
    while (completed != n) {
        int all_idle = 1; // Flag to check if CPU is idle

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && at[i] <= current_time) {
                all_idle = 0; // CPU is not idle

                // Execute the process for the time quantum or remaining time, whichever is smaller
                int execute_time = (remaining_bt[i] > time_quantum) ? time_quantum : remaining_bt[i];
                remaining_bt[i] -= execute_time;
                current_time += execute_time;

                // If the process is completed
                if (remaining_bt[i] == 0) {
                    completed++;
                    ct[i] = current_time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        // If no process was executed in this cycle, increment time
        if (all_idle) {
            current_time++;
        }
    }

    // Calculate averages and print results
    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    printf("Average Waiting Time: %.2f\n", avg_wt / n);

    return 0;
}
