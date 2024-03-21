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

void Heapify(vector<int>&nums, int n, int i)
{
    int c1 = (2*i)+1;
    int c2 = (2*i)+2;
    int max = i;

    if(c1<n && nums[c1]>nums[max])
    {
        max = c1;
    }

    if(c2<n && nums[c2]>nums[max])
    {
        max = c2;
    }

    if(max!=i)
    {
        swap(nums[i], nums[max]);
        Heapify(nums, n, max);
    }
}

void buildHeap(vector<int>&nums)
{
    int n=nums.size();
    for(int i=n/2-1; i>=0; i--)
    {
        Heapify(nums, n, i);
    }

    for(int i=n-1; i>0; i--)
    {
        swap(nums[0], nums[i]);
        Heapify(nums, i, 0);
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
    buildHeap(nums);
    printArray(nums);
    return 0;
}