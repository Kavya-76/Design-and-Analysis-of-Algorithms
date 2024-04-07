#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&arr, int low, int high)
{   
    int pivot = arr[high];
    int i=low-1;
    int j=low;
    for(int j=low; j<high; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high)
{
    if(low<high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

void printArray(vector<int>arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n, temp;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        quickSort(arr, 0, n-1);
        printArray(arr);
    }
}