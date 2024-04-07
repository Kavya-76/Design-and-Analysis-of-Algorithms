#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void threeSum(vector<int> arr)
{
  int n = arr.size();
  for (int i = n-1; i >=2; i--)
  {
    int l = 0;
    int r = i-1;
    while (l < r)
    {
      if (arr[l] + arr[r] == arr[i])
      {
        cout << l+1 << " " << r+1 << " " << i+1 << endl;
        return;
      }

      else if (arr[l] + arr[r] > arr[i])
      {
        r--;
      }

      else
      {
        l++;
      }
    }
  }
  cout<<"No sequence found"<<endl;
}

int main()
{
  int testcases;
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
    threeSum(arr);
  }
}