#include <stdio.h>

struct Process {
    int id, arrivalTime, burstTime, waitingTime, turnaroundTime, completionTime, remainingTime;
};

struct Process processes[10];

int queue[100];
int start = -1;
int end = -1;

void insert(int n) {
    if (start == -1) {
        start = 0;
    }
    end = end + 1;
    queue[end] = n;
}

int delete() {
    int n;
    n = queue[start];
    start = start + 1;
    return n;
}

int main() {
    int n, timeQuantum, processIndex, time = 0;
    int temp[10], exists[10] = {0};

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].arrivalTime = 0;
        processes[i].id = i;
        processes[i].remainingTime = processes[i].burstTime;
        temp[i] = processes[i].burstTime;
    }

    insert(0);
    exists[0] = 1;

    while (start <= end) {
        processIndex = delete();
        if (processes[processIndex].remainingTime >= timeQuantum) {
            processes[processIndex].remainingTime = processes[processIndex].remainingTime - timeQuantum;
            time = time + timeQuantum;
        } else {
            time = time + processes[processIndex].remainingTime;
            processes[processIndex].remainingTime = 0;
        }

        for (int i = 0; i < n; i++) {
            if (exists[i] == 0 && processes[i].arrivalTime <= time) {
                insert(i);
                exists[i] = 1;
            }
        }

        if (processes[processIndex].remainingTime == 0) {
            processes[processIndex].turnaroundTime = time - processes[processIndex].arrivalTime;
            processes[processIndex].waitingTime = processes[processIndex].turnaroundTime - temp[processIndex];
        } else {
            insert(processIndex);
        }
    }

    for (int j = 0; j < 10; j++) {
        processes[j].completionTime = processes[j].arrivalTime + processes[j].turnaroundTime;
    }

    printf("PID AT  BT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t %d\n", processes[i].id + 1, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
    return 0;
}
