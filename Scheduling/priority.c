#include <stdio.h>

struct process {
    int id, at, bt, ct, tat, wt, stat, priority;
} p[20];

int main() {
    int n, i, completed = 0, current = 0;
    float ttat = 0, twt = 0, atat, awt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time, and Priority (lower value = higher priority):\n");
        scanf("%d %d %d %d", &p[i].id, &p[i].at, &p[i].bt, &p[i].priority);
        p[i].stat = 0;  // Not completed
    }

    while (completed != n) {
        int index = -1, highest_priority = 32767;

        for (i = 0; i < n; i++) {
            if (p[i].at <= current && p[i].stat == 0) {
                if (p[i].priority < highest_priority || 
                   (p[i].priority == highest_priority && p[i].at < p[index].at)) {
                    highest_priority = p[i].priority;
                    index = i;
                }
            }
        }

        if (index == -1) {
            current++; // CPU is idle
        } else {
            current += p[index].bt;
            p[index].ct = current;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].stat = 1;
            completed++;

            ttat += p[index].tat;
            twt += p[index].wt;
        }
    }

    atat = ttat / n;
    awt = twt / n;

    // Output
    printf("\nID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", 
            p[i].id, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}
