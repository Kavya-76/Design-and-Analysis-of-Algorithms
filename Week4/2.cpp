#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&nums, int low, int high, int &comparisions, int &swaps)
{
    int pivot = nums[high];
    int i = low-1;
    int j = low;
    for(int j=low; j<high; j++)
    {
        comparisions++;
        if(nums[j]<=pivot)
        {
            i++;
            swap(nums[i], nums[j]);
            swaps++;
        }
    }
    swap(nums[i+1], nums[high]);
    swaps++;
    return i+1;
}

void quickSort(vector<int>&arr, int low, int high, int &comparisions, int &swaps)
{
    if(low<high)
    {
        int partitionIndex = partition(arr, low, high, comparisions, swaps);
        quickSort(arr, low, partitionIndex-1, comparisions, swaps);
        quickSort(arr, partitionIndex+1, high, comparisions, swaps);
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
    int testcases, comparisions=0, swaps=0;
    cout<<"Enter number of testcases: ";
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n, temp;
        cout<<"Enter number of elements: ";
        cin >> n;
        cout<<"Enter the elements: ";
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        quickSort(arr, 0, n-1, comparisions, swaps);

        cout<<"Array after sorting: ";
        printArray(arr);
        cout<<"Comparisions: "<<comparisions<<endl;
        cout<<"Swaps: "<<swaps<<endl;
    }
}