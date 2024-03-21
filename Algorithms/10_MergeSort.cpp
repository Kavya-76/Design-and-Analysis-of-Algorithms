#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&nums, int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k=low;
    int a[100];
    while(i<=mid && j<=high)
    {
        if(nums[i]<nums[j])
        {
            a[k] = nums[i];
            k++;
            i++;
        }

        else
        {
            a[k] = nums[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        a[k] = nums[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        a[k] = nums[j];
        k++;
        j++;
    }

    for(int i=low; i<=high; i++)
    {
        nums[i] = a[i];
    }
}

void mergeSort(vector<int>&nums, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
}

int main()
{
    vector<int>nums;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the values: ";
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    mergeSort(nums, 0, nums.size()-1);
    printArray(nums);
    return 0;
}