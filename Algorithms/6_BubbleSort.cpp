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
void bubbleSort(vector<int>&nums)
{
    int n = nums.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
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
    bubbleSort(nums);
    printArray(nums);
    return 0;
}