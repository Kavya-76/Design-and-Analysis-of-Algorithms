#include <iostream>
#include <vector>
using namespace std;
int findDuplicates(vector<int> arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int freq = 0;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            if (arr[mid - 1] == key)
            {
                end = mid - 1;
            }
            else
            {
                break;
            }
        }

        else if (key > arr[mid])
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    while (arr[mid] == key)
    {
        freq++;
        mid++;
    }
    if (freq != 0)
    {
        return freq;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n, key, temp;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        cin >> key;
        cout << key << " - " << findDuplicates(arr, n, key) << endl;
    }
}