#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], pr[n], pid[n];
    int i, j;

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority for Process P%d: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort by priority
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[i])
            {
                // Swap priority
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate WT
    wt[0] = 0; 
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }

    // Calculate TAT
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], pr[i], bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
