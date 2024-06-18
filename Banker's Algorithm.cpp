#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    int allocation[n][m] =
    {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[n][m] =
    {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[m] = {3, 3, 2};
    int need[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    bool finish[n] = {false};

    for (int k = 0; k < n; k++)  //outer loop
    {
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == false)
            {
                bool temp = true;

                for(int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        temp = false;
                        break;
                    }
                }

                if (temp == true)
                {
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }

                    finish[i] = true;
                    cout << "Process " << i << " is finished!" << endl;
                }
            }
        }
    }

    bool isSafe = true;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == false)
        {
            isSafe = false;
            cout << "\nNot safe!";
            break;
        }
    }

    if (isSafe == true)
    {
        cout << "\nSafe state.\n";
    }

    return 0;
}
