#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void twoSum(vector<int> arr, int key)
{
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = key - arr[i];
        if (m.find(diff) != m.end())
        {
            cout << arr[i] << " " << arr[m[diff]]<<endl;
            return;
        }
        m[arr[i]] = i;
    }
    cout << "No such elements exist" << endl;
}

int main()
{
    int testcases;
    cout<<"Enter number of testcases: ";
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n, key;
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
        cin >> key;
        twoSum(arr, key);
    }
}