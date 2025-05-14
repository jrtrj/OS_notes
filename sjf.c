#include <stdio.h>

int main() {
    int n, p[10], at[10], bt[10], wt[10], tat[10], ct[10], completed[10] = {0};
    float total_tat = 0, total_wt = 0;
    int current_time = 0, completed_processes = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Process No, Arrival Time, Burst Time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i], &at[i], &bt[i]);
    }

    while (completed_processes < n) {
        int shortest_job = -1;
        int shortest_bt = 9999;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= current_time && bt[i] < shortest_bt) {
                shortest_bt = bt[i];
                shortest_job = i;
            }
        }

        if (shortest_job == -1) {
            current_time++;  // Idle CPU if no job is available
        } else {
            // Execute the shortest job
            current_time += bt[shortest_job];
            ct[shortest_job] = current_time;
            tat[shortest_job] = ct[shortest_job] - at[shortest_job];
            wt[shortest_job] = tat[shortest_job] - bt[shortest_job];
            completed[shortest_job] = 1;
            completed_processes++;
        }
    }

    // Calculate totals
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
