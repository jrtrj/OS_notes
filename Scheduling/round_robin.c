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

    int i = 0;
    while (completed != n) {
        int done_something = 0;
        if (remaining_bt[i] > 0 && at[i] <= current_time) {
            int exec_time = (remaining_bt[i] > time_quantum) ? time_quantum : remaining_bt[i];
            remaining_bt[i] -= exec_time;
            current_time += exec_time;
            done_something = 1;

            if (remaining_bt[i] == 0) {
                completed++;
                ct[i] = current_time;
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];
            }
        }

        i = (i + 1) % n; // Rotate circularly

        if (!done_something) {
            int all_idle = 1;
            for (int j = 0; j < n; j++) {
                if (remaining_bt[j] > 0 && at[j] <= current_time) {
                    all_idle = 0;
                    break;
                }
            }
            if (all_idle) current_time++;
        }
    }

    // Display output
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
