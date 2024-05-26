/*
Q2 :- Given a long list of tasks. Each task takes specific time to accomplish it
and each task has a deadline associated with it. You have to design an
algorithm and implement it using a program to find maximum number of
tasks that can be completed without crossing their deadlines and also find
list of selected tasks.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void selectTasks(int n, vector<int> &time, vector<int> &deadline)
{
    vector<pair<int, int>> tasks;
    
    for (int i = 0; i < n; i++)
    {
        tasks.push_back(make_pair(i, deadline[i]));
    }
    
    sort(tasks.begin(), tasks.end(), [](const pair<int, int> &t1, const pair<int, int> &t2)
         { return t1.second < t2.second; });
    vector<int> selected;
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (tasks[i].second >= count + 1)
        {
            count++;
            selected.push_back(tasks[i].first);
        }
    }
    
    cout << "Number of tasks completed: " << count << endl;
    cout << "Selected tasks: ";
    for (int i = 0; i < count; i++)
    {
        cout << selected[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the total number of tasks: ";
    cin >> n;
    vector<int> time(n);
    vector<int> deadline(n);
    cout << "Enter the time taken for each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    cout << "Enter the deadlines for each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> deadline[i];
    }
    selectTasks(n, time, deadline);
    return 0;
}
