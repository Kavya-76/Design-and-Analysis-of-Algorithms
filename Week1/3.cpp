#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int start, int end, int key, int &comparisions)
{
    for (int i = start; i <= end; i++)
    {
        comparisions++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void expoSearch(vector<int> arr, int n, int key)
{
    int i = 1, comparisions=0;
    if (arr[0] == key)
    {
        return;
    }

    while (i < n && arr[i] <= key)
    {
        comparisions++;
        i *= 2;
    }
    int ans = linearSearch(arr, i / 2, max(i, n - 1), key, comparisions);
    if(ans>=0)
        cout<<"Present "<<comparisions<<endl;
    else
        cout<<"Not present "<<endl;
}

int main()
{
    int testcases, temp, ans, key;
    vector<int> arr;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        cin >> key;
        expoSearch(arr, n, key);
    }
}