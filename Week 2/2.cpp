#include <iostream>
#include <vector>
using namespace std;

vector<int> threeSum(vector<int> arr)
{
  int i,j, k=arr.size()-1;
  vector<int> ans;
  while(k>0)
    {
      i=0;
      j=k-1;
      while(i<j)
        {
          if(arr[i]+arr[j]==arr[k])
          {
            ans.push_back(i+1);
            ans.push_back(j+1);
            ans.push_back(k+1);
            return ans;
          }

          else if(arr[i]+arr[j]<k)
          {
            i++;
          }

          else
          {
            j--;
          }
        }
        k--;
    }
  return {};
}

int main() {
  int testcases;
  vector<int>arr;
  vector<int>ans;
  cin>>testcases;
  for(int i=0; i<testcases; i++)
    {
      int n;
      cin>>n;
      for(int j=0; j<n; j++)
        {
          int temp;
          cin>>temp;
          arr.push_back(temp);
        }
      ans = threeSum(arr);
      if(ans.size()==0)
      {
        cout<<"No cases found";
      }

      else
      {
        for(int i=0; i<ans.size(); i++)
          {
            cout<<ans[i]<<" ";
          }
      }
    }
}