#include <iostream>
#include <vector>
using namespace std;
bool binarySearch(vector<int>nums, int s, int e, int key)
{
    if(s>e)
    {
        return false;
    }

    int mid = s+(e-s)/2;
    if(nums[mid]==key)
    {
        return true;
    }

    else if(nums[mid]>key)
    {
        return binarySearch(nums, s, mid-1, key);
    }

    else
    {
        return binarySearch(nums, mid+1, e, key);
    }
}

bool expoSearch(vector<int>nums, int key)
{
    int n = nums.size();
    if(nums[0]==key)
    {
        return true;
    }

    int i=1;
    while(i<n && nums[i]<=key)
    {
        i*=2;
    }
    return binarySearch(nums, i/2, ((n-1<i)?n-1:i), key);
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

    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    if(expoSearch(nums, key)) 
        cout<<"Key found";
    else 
        cout<<"Key not found";
    return 0;
}