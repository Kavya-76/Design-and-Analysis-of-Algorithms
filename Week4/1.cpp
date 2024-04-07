#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&nums, int low, int mid, int high)
{
    int n = nums.size();
    int i=low;
    int j=mid+1;
    int k = low;
    vector<int>temp(n);
    while(i<=mid && j<=high)
    {
        if(nums[i]<nums[j])
        {
            temp[k]=nums[i];
            k++;
            i++;
        }

        else
        {
            temp[k]=nums[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k] = nums[i];
        k++;
        i++;
    }

    while(j<=high)
    {
        temp[k] = nums[j];
        k++;
        j++;
    }

    for(int i=low; i<=high; i++)
    {
        nums[i] = temp[i];
    }
}

void mergeSort(vector<int>&nums, int low, int high)
{
    while(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
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
        cin >> key;
        findDuplicates(arr, n, key);
    }
}