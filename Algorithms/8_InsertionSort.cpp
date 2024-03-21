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

void insertionSort(vector<int>&nums)
{
    int n = nums.size();
    for(int i=1; i<n; i++)
    {
        int key = nums[i];
        int j=i-1;
        while(j>=0 && nums[j]>key)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
        printArray(nums);
    }
    cout<<endl;
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
    insertionSort(nums);
    printArray(nums);
    return 0;
}