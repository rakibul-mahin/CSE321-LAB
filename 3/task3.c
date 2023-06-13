#include <stdio.h>

struct Process {
    int arrival_time, burst_time, priority, waiting_time, turnaround_time, completion_time, remaining_time;
};

struct Process processes[10];

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d",&n);
    
    int temp_burst_time[10], t, count=0, shortest;
    
    for(int i=0; i<n; i++){
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for P%d: ", i+1);
        scanf("%d", &processes[i].priority);
        temp_burst_time[i] = processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    processes[9].priority = 999;
   
    for(t=0; count!=n; t++) {
        shortest = 9;
        for(int i=0; i<n; i++) {
            if(processes[shortest].priority > processes[i].priority && processes[i].arrival_time <= t && processes[i].remaining_time > 0){
                shortest = i;
            }
        }
       
        processes[shortest].remaining_time--;
        if(processes[shortest].remaining_time == 0) {
            count++;
            processes[shortest].waiting_time = t+1 - processes[shortest].arrival_time - temp_burst_time[shortest];
            processes[shortest].turnaround_time = t+1 - processes[shortest].arrival_time;
        }
    }
    
    for(int k=0; k<n; k++){
        processes[k].completion_time = processes[k].arrival_time + processes[k].turnaround_time;
    }

    printf("PID  AT    BT    CT    TAT   WT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    return 0;
}
