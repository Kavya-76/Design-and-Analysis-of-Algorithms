#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int low, int mid, int high, int &comparisions, int &inversions)
{
    int n = arr.size();
    int i=low;
    int j=mid+1;
    int k = low;
    vector<int>temp(n);
    while(i<=mid && j<=high)
    {
        comparisions++;
        if(arr[i]<=arr[j])
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
            inversions+=mid-i;
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

void mergeSort(vector<int>&arr, int low, int high, int &comparisions, int &inversions)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr, low, mid, comparisions, inversions);
        mergeSort(arr, mid+1, high, comparisions, inversions);
        merge(arr, low, mid, high, comparisions, inversions);
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
    int testcases, comparisions=0, inversions=0;
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
        mergeSort(arr, 0, n-1, comparisions, inversions);
        cout<<"Array after sorting: ";
        printArray(arr);
        cout<<"Comparisions: "<<comparisions<<endl;
        cout<<"Inversions: "<<inversions<<endl;
    }
}