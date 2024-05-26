/*
Q3 :- Given an array of elements. Assume arr[i] represents the size of file i. 
Write an algorithm and a program to merge all these files into single file with 
minimum computation. For given two files A and B with sizes m and n, 
computation cost of merging them is O(m+n). (Hint: use greedy approach).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mergeFiles(vector<int> &files)
{
    int totalCost = 0;
    while (files.size() > 1)
    {
        sort(files.begin(), files.end());
        int i = files[0];
        int j = files[1];
        totalCost += i + j;
        files.erase(files.begin(), files.begin() + 2);
        files.push_back(i + j);
    }
    return totalCost;
}

int main()
{
    int n;
    cout << "Enter the number of files: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the size of each file: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = mergeFiles(arr);
    cout << "Minimum computation cost: " << ans << endl;
}
