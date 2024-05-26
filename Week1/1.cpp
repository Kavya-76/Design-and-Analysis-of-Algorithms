/*
Q1 :- Given an array of nonnegative integers, design a linear algorithm and 
implement it using a program to find whether given key element is present in 
the array or not. Also, find total number of comparisons for each input case. 
(Time Complexity = O(n), where n is the size of input).
*/

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
  cout<<"Enter number of testcases: ";
  cin >> testcases;

  for (int i = 0; i < testcases; i++)
  {
    cout<<"Enter number of elements: ";
    cin >> size;

    cout<<"Enter the elements: ";
    for (int j = 0; j < size; j++)
    {
      cin >> value;
      arr.push_back(value);
    }
    cout<<"Enter key: ";
    cin >> key;
    linear_search(arr, size, key);
  }
}