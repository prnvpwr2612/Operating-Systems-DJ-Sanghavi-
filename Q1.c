#include <stdio.h>

struct Process {
    int arrival;
    int burst_time;
};

void computeFCFS(struct Process processes[], int num_process) {
    int waitingTime = 0, turnaroundTime = 0;

    printf("\nProcess\tArrival\tBurst\tCT\tTAT\tWT\n");

    int currentTime = 0;
    for (int i = 0; i < num_process; i++) {
        printf("%d\t%d\t%d\t", i + 1, processes[i].arrival, processes[i].burst_time);

        if (processes[i].arrival > currentTime) {
            currentTime = processes[i].arrival;
        }

        int completionTime = currentTime + processes[i].burst_time;
        printf("%d\t%d\t%d\n", completionTime, completionTime - processes[i].arrival, completionTime - processes[i].arrival - processes[i].burst_time);

        waitingTime += completionTime - processes[i].arrival - processes[i].burst_time;
        turnaroundTime += completionTime - processes[i].arrival;

        currentTime = completionTime;
    }

    float avg_waiting = (float)waitingTime / num_process;
    float avg_turnaround = (float)turnaroundTime / num_process;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

int main() {
    int num_process;

    printf("Enter the number of processes: ");
    scanf("%d", &num_process);

    struct Process processes[2000];

    printf("Enter arrival time and CPU burst time for each process:\n");
    for (int i = 0; i < num_process; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival);
        printf("CPU Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    computeFCFS(processes, num_process);

    return 0;
}

