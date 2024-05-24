#include <iostream>
#include <vector>
using namespace std;

void linear_search(vector<int> arr, int size, int key)
{
  int comparisions = 0, i=0;
  for (i = 0; i < size; i++)
  {
    comparisions++;
    if (arr[i] == key)
    {
      cout << "Present " << comparisions << endl;
      break;
    }
  }

  if (i == size)
  {
    cout << "Not present" << endl;
  }
}

int main()
{
  int testcases, size, key, value;
  vector<int> arr;
  cin >> testcases;

  for (int i = 0; i < testcases; i++)
  {
    cin >> size;
    for (int j = 0; j < size; j++)
    {
      cin >> value;
      arr.push_back(value);
    }

    cin >> key;
    linear_search(arr, size, key);
  }
}