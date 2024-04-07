#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int low, int mid, int high)
{
    int n = arr.size();
    int i=low;
    int j=mid+1;
    int k = low;
    vector<int>temp(n);
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }

        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j<=high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int>&arr, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
        mergeSort(arr, 0, n-1);
        printArray(arr);
    }
}