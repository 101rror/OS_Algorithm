#include<bits/stdc++.h>
using namespace std;

#define MAX_PROCESSES 10
#define TIME_QUANTUM 4

struct Process
{
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
};

void roundRobin(struct Process processes[], int n)
{
    int time = 0;
    int completed = 0;
    int quantum = TIME_QUANTUM;

    cout << "Gantt Chart:" << endl;
    cout << "-------------" << endl;
    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                if (processes[i].remaining_time <= quantum)
                {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    cout << "| P" << processes[i].pid << " ";
                    completed++;
                }
                else
                {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    cout << "| P" << processes[i].pid << " ";
                }
            }
        }
    }
    cout << "|" << endl << endl;
    cout << "Waiting Time:" << endl;
    cout << "-------------" << endl;
    float total_waiting_time = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << processes[i].pid << ": " << processes[i].waiting_time << endl;;
        total_waiting_time += processes[i].waiting_time;
    }

    cout << endl;
    cout << "Average Waiting Time: " << (float)total_waiting_time/n << endl;
}

int main()
{
    int n;
    struct Process processes[MAX_PROCESSES];

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter burst time for each process: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    roundRobin(processes, n);

    return 0;
}
