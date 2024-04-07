/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
and implement it using a program to find which alphabet has maximum number of
occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countingSort(vector<char>&arr)
{
    vector<int>count(26,0);
    for(int i=0; i<arr.size(); i++)
    {
        count[arr[i]-'a']++;
    }

    int maxCount = 0;
    char maxChar = 'a';
    for(int i=0; i<count.size(); i++)
    {
        if(count[i]>maxCount)
        {
            maxCount = count[i];
            maxChar = 'a'+i;
        }
    }

    cout<<maxChar;
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
        countingSort(arr);
    }
}