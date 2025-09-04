#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], pr[20];
    int rt[20], ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    int complete = 0, t = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("\nGantt Chart Order: ");

    while (complete < n) {
        int idx = -1;
        int minPr = 9999;

        // process with high priority
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                if (pr[i] < minPr) {
                    minPr = pr[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf(" P%d ", idx+1);
            rt[idx]--;

            if (rt[idx] == 0) {
                complete++;
                ct[idx] = t + 1;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
        t++;
    }

    printf("\n\nProcess\tAT\tBT\tPr\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}