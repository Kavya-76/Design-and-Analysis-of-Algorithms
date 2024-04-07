#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>arr, int key)
{
    int count=0;
    sort(begin(arr), end(arr));
    int i=0; 
    int j=arr.size()-1;
    while(i<j)
    {
        if(arr[j]-arr[i]==key)
        {
            count++;
        }
    }
}

int main()
{
  int testcases ,key;
  vector<int> arr;
  cin >> testcases;
  for (int i = 0; i < testcases; i++)
  {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    cin>>key;
    solve(arr,key);
  }
}