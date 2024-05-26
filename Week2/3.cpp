#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>arr, int key)
{
    int count=0;
    int n = arr.size();
    int i=0, j=1;
    sort(begin(arr), end(arr));

    while(i<n && j<n)
    {
        if(arr[j]-arr[i]==key)
        {
            count++;
            i++;
            j++;
        }

        else if(arr[j]-arr[i]>key)
        {
          i++;
        }

        else
        {
          j++;
        }
    }
    return count;
}

int main()
{
  int testcases ,key;
  vector<int> arr;
  cout<<"Enter number of testcases: ";
  cin >> testcases;
  for (int i = 0; i < testcases; i++)
  {
    int n;
    cout<<"Enter number of elements: ";
    cin >> n;
    cout<<"Enter the elements: ";
    for (int j = 0; j < n; j++)
    {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    cout<<"Enter key: ";
    cin>>key;
    int ans = solve(arr,key);
    cout<<"Number of Pairs: "<<ans<<endl;
  }
}