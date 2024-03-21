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

int partition(vector<int>&nums, int low, int high)
{
    int pivot = nums[high];
    int i = low-1;
    int j = low;
    for(int j=low; j<high; j++)
    {
        if(nums[j]<=pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[high]);
    return i+1;
}

void quickSort(vector<int>&nums, int low, int high)
{
    int partitionIndex;
    if(low<high)
    {
        partitionIndex = partition(nums, low, high);
        quickSort(nums, low, partitionIndex-1);
        quickSort(nums, partitionIndex+1, high);
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
    quickSort(nums, 0, nums.size()-1);
    printArray(nums);
    return 0;
}