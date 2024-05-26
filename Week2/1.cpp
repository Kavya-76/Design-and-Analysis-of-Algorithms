#include <iostream>
#include <vector>
using namespace std;
void findDuplicates(vector<int> arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int freq = 0;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            if (mid>0 && arr[mid - 1] == key)
            {
                mid--;
                continue;
            }
            break;
        }

        else if (key > arr[mid])
            start = mid + 1;

        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }

    while (mid<arr.size() && arr[mid] == key)
    {
        freq++;
        mid++;
    }

    cout<<key<<" - "<<freq<<endl;
}

int main()
{
    int testcases;
    cout<<"Enter number of testcases: ";
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n, key, temp;
        cout<<"Enter number of elements: ";
        cin >> n;
        cout<<"Enter the elements: ";
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        cout<<"Enter key: ";
        cin >> key;
        findDuplicates(arr, n, key);
    }
}