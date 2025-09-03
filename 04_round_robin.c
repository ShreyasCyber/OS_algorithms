#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], rem_bt[n];
    int i, t = 0; //urrent time

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];  
        wt[i] = 0;         
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int done;
    printf("\nGantt Chart Order: ");

    do {
        done = 1; // assume all done
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // still some process is left

                printf(" P%d ", i+1);

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i]; // WT
                    rem_bt[i] = 0;
                }
            }
        }
    } while (!done);

    // Calculate TAT
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
