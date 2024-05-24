#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int>commonElements(vector<int>arr1, vector<int>arr2, int m, int n)
{
    vector<int>common;
    int i=0, j=0;

    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
            i++;

        else if(arr1[i]>arr2[j])
            j++;

        else
        {
            common.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return common;
}

int main()
{
    int testcases;
    cin>>testcases;
    vector<int>arr1, arr2;
    for(int i=0; i<testcases; i++)
    {
        int m, n, temp;
        cin>>m;
        for(int j=0; j<m; j++)
        {
            cin>>temp;
            arr1.push_back(temp);
        }

        cin>>n;
        for(int j=0; j<n; j++)
        {
            cin>>temp;
            arr2.push_back(temp);
        }

        vector<int>ans;
        ans = commonElements(arr1, arr2, m, n);
        printArray(ans);
    }
    return 0;
}