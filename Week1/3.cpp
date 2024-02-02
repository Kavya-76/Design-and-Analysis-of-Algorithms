#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>arr, int start, int end, int key)
{
  for(int i=start; i<=end; i++)
    {
      if(arr[i]==key)
      {
        return i;
      }
    }
  return -1;
}

int expoSearch(vector<int>arr, int n, int key)
{
  int i=1;
  if(arr[0]==key)
  {
    return 0;
  }

  while(i<n && arr[i]<=key)
    {
      i*=2;
    }

  return linearSearch(arr, i/2, max(i, n-1), key);
}
int main() {
  int testcases, temp, ans, key;
  vector<int>arr;
  cin>>testcases;
  for(int i=0; i<testcases; i++)
    {
      int n;
      cin>>n;
      for(int i=0; i<n; i++)
        {
          cin>>temp;
          arr.push_back(temp);
        }
        cin>>key;
        ans = expoSearch(arr, n, key);
        cout<<ans<<endl;
    }
}