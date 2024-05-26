/*
Q2 :- Given an array of integers of size n, design an algorithm and write a
program to check whether this array contains duplicate within a small
window of size k < n.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int k;
        cout << "Enter the window size k: ";
        cin >> k;

        unordered_set<int> window;
        bool duplicateFound = false;

        for (int i = 0; i < n - k + 1; i++)
        {
            int element = arr[i];

            if (window.find(element) != window.end())
            {
                duplicateFound = true;
                break;
            }

            window.insert(element);

            if (window.size() > k)
            {
                window.erase(arr[i - k + 1]);
            }
        }

        if (duplicateFound)
        {
            cout << "Duplicate present in window k" << endl;
        }
        else
        {
            cout << "Duplicate not present in window k" << endl;
        }
    }

    return 0;
}
