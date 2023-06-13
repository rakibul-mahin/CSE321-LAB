#include <stdio.h>

struct Process {
    int waitingTime, arrivalTime, burstTime, turnaroundTime, completionTime, totalBurstTime;
};

struct Process processes[10];

int main() {
    int numProcesses, burstTime[10];
    int completedCount = 0, currentTime = 0, shortest;
    
    printf("Total Number of Processes: ");
    scanf("%d", &numProcesses);

    for(int i = 0; i < numProcesses; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        
        processes[i].totalBurstTime = processes[i].burstTime;
        burstTime[i] = processes[i].burstTime;
    }

    processes[9].burstTime = 999;

    for(currentTime = 0; completedCount != numProcesses; currentTime++) {
        shortest = 9;
        for(int i = 0; i < numProcesses; i++) {
            if(processes[i].burstTime < processes[shortest].burstTime && (processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0)) {
                shortest = i;
            }
        }

        processes[shortest].burstTime--;

        if(processes[shortest].burstTime == 0) {
            completedCount++;
            processes[shortest].waitingTime = currentTime + 1 - processes[shortest].arrivalTime - burstTime[shortest];
            processes[shortest].turnaroundTime = currentTime + 1 - processes[shortest].arrivalTime;
        }
    }

    for(int j = 0; j < 10; j++) {
        processes[j].completionTime = processes[j].arrivalTime + processes[j].turnaroundTime;
    }

    printf("Pid AT  BT  CT  TAT  WT\n");
    for(int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, processes[i].arrivalTime, processes[i].totalBurstTime, processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }

    return 0;
}
