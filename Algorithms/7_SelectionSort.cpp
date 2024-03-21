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
void selectionSort(vector<int>&nums)
{
    int n = nums.size();
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(nums[j]<nums[min])
            {
                min = j;
            }
        }
        if(nums[min]!=nums[i])
        {
            swap(nums[min], nums[i]);
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
    selectionSort(nums);
    printArray(nums);
    return 0;
}