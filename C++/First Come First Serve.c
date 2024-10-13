#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int start_time;
};

void findWaitingTime(struct Process process[], int n) {
    process[0].waiting_time = 0;
    process[0].start_time = 0;
    process[0].completion_time = process[0].burst_time;

    for (int i = 1; i < n; i++) {
        process[i].start_time = process[i - 1].completion_time;
        process[i].waiting_time = process[i].start_time - process[i].arrival_time;
        if (process[i].waiting_time < 0) {
            process[i].waiting_time = 0;
        }
        process[i].completion_time = process[i].start_time + process[i].burst_time;
    }
}

void findTurnAroundTime(struct Process process[], int n) {
    for (int i = 0; i < n; i++) {
        process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
    }
}

void findAverageTime(struct Process process[], int n) {
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += process[i].waiting_time;
        total_tat += process[i].turnaround_time;
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turnaround time = %.2f\n", avg_tat);
}

void display(struct Process process[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].pid, process[i].burst_time, process[i].arrival_time, process[i].waiting_time, process[i].turnaround_time, process[i].completion_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process process[n];
    for (int i = 0; i < n; i++) {
        process[i].pid = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &process[i].burst_time);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &process[i].arrival_time);
    }

    findWaitingTime(process, n);
    findTurnAroundTime(process, n);
    display(process, n);
    findAverageTime(process, n);

    return 0;
}