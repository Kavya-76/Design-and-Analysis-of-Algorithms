#include <iostream>
#include <vector>
using namespace std;

void linearSearch(vector<int>nums, int key)
{
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==key)
        {
            cout<<"Key found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Key not found"<<endl;
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
    linearSearch(nums, key);
    return 0;
}