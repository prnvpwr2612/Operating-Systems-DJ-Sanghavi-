#include <stdio.h>

int main() {
    int numberOfProcesses, sum = 0, count = 0, remainingProcesses, quantum, wt = 0, tat = 0;
    int arrivalTime[10], burstTime[10], tempBurstTime[10];
    int i;

    // Get the number of processes
    printf("Enter the total number of processes in the system: ");
    scanf("%d", &numberOfProcesses);

    remainingProcesses = numberOfProcesses;

    // Input arrival time and burst time for each process
    for (i = 0; i < numberOfProcesses; i++) {
        printf("\nEnter the arrival time and burst time for Process[%d]\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
        tempBurstTime[i] = burstTime[i];
    }

    // Input the time quantum
    printf("\nEnter the time quantum for the process: ");
    scanf("%d", &quantum);

    // Display the header for the process table
    printf("\nProcess No \tBurst Time \tTurnaround Time \tWaiting Time\n");

    // Implement the Round Robin scheduling algorithm
    for (sum = 0,i = 0; remainingProcesses != 0;) {
        if (tempBurstTime[i] <= quantum && tempBurstTime[i] > 0) {
            sum += tempBurstTime[i];
            tempBurstTime[i] = 0;
            count = 1;
        } else if (tempBurstTime[i] > 0) {
            tempBurstTime[i] -= quantum;
            sum += quantum;
        }

        if (tempBurstTime[i] == 0 && count == 1) {
            remainingProcesses--;
            printf("  %d\t\t  %d\t\t\t%d\t\t\t%d\n", i + 1, burstTime[i], sum - arrivalTime[i], sum - arrivalTime[i] - burstTime[i]);
            wt += sum - arrivalTime[i] - burstTime[i];
            tat += sum - arrivalTime[i];
            count = 0;
        }

        i = (i == numberOfProcesses - 1) ? 0 : i + 1;
    }

    // Calculate and display average turnaround time and waiting time
    float avgWaitingTime = (float)wt / numberOfProcesses;
    float avgTurnaroundTime = (float)tat / numberOfProcesses;

    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}

