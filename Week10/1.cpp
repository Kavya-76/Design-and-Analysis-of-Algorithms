/*
Q1 :- Given a list of activities with their starting time and finishing time. Your
goal is to select maximum number of activities that can be performed by a
single person such that selected activities must be non-conflicting. Any
activity is said to be non-conflicting if starting time of an activity is greater
than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity
{
    int start;
    int finish;
};

bool compareActivities(const Activity &a1, const Activity &a2)
{
    return a1.finish < a2.finish;
}

void selectNonConflictingActivities(int n, vector<int> &start, vector<int> &finish)
{
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++)
    {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }

    sort(activities.begin(), activities.end(), compareActivities);
    vector<int> selected;
    selected.push_back(0);
    int lastFinish = activities[0].finish;
    int selectedCount = 1;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= lastFinish)
        {
            selected.push_back(i);
            lastFinish = activities[i].finish;
            selectedCount++;
        }
    }

    cout << "Number of non-conflicting activities: " << selectedCount << endl;
    cout << "Selected activities: ";
    for (int i = 0; i < selectedCount; i++)
    {
        cout << selected[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<int> start(n);
    vector<int> finish(n);
    cout << "Enter the starting times of activities: ";
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    cout << "Enter the finishing times of activities: ";
    for (int i = 0; i < n; i++)
    {
        cin >> finish[i];
    }
    selectNonConflictingActivities(n, start, finish);
    return 0;
}
