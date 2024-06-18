#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct processes
{
    int pid;
    int arrivalTime;
    int burstTime;
    int startingTime = 0;
    int endingTime = 0;
    int waitingTime = 0;
};

bool com(const processes& a, const processes& b)
{
    return a.arrivalTime < b.arrivalTime;
}

void FCFS(struct processes process[], int n)
{
    int sum = 0;
    process[0].startingTime = process[0].arrivalTime;
    process[0].endingTime = process[0].startingTime+process[0].burstTime;
    process[0].waitingTime = 0;

    for(int i = 1; i < n; i++)
    {
        if(process[i].arrivalTime <= process[i - 1].endingTime)
        {
            process[i].startingTime = process[i - 1].endingTime;
        }
        else
        {
            process[i].startingTime = process[i].arrivalTime;
        }

        process[i].endingTime = process[i].startingTime + process[i].burstTime;
        process[i].waitingTime=process[i].startingTime - process[i].arrivalTime;
        sum += process[i].waitingTime;

        cout << process[i].pid << " ";
    }

    cout << endl << "Avg " << sum/n <<endl;

}

int main()
{

    int n;
    cin >> n;
    processes process[n];

    for(int i = 0; i < n; i++)
    {
        cin >> process[i].pid;
        cin >> process[i].arrivalTime;
        cin >> process[i].burstTime;
    }

    sort(process, process+n,com);

    FCFS(process, n);

    return 0;
}
