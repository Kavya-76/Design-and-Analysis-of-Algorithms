/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
and implement it using a program to find which alphabet has maximum number of
occurrences andprint it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void findDuplicate(vector<char> arr)
{
    map<char, int> m;
    for (char val : arr)
    {
        m[val]++;
    }

    int max = 0;
    char maxel;
    for (auto &it : m)
    {
        if (it.second > 1 && it.second > max)
        {
            maxel = it.first;
            max = it.second;
        }
    }
    if (max == 0)
    {
        cout << "No duplicate element found" << endl;
    }
    else
    {
        cout << maxel << "-" << max << endl;
    }
    return;
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        vector<char> arr;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            arr.push_back(temp);
        }
        findDuplicate(arr);
    }
}