#include <iostream>
#include <vector>
using namespace std;

void binary(vector<int> arr, int size, int key)
{
    int comparisions = 0;
    int start = 0, end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        comparisions++;
        if (key == arr[mid])
        {
            cout << "Present " << comparisions << endl;
            return;
        }

        else if (key < arr[mid])
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    cout << "Not present" << endl;
}

int main()
{
    vector<int> arr;
    int testcases, size, key, temp;
    cout<<"Enter number of testcases: ";
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        cout<<"Enter number of elements: ";
        cin >> size;

        cout<<"Enter the elements: ";
        for (int j = 0; j < size; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        cout<<"Enter key: ";
        cin >> key;
        binary(arr, size, key);
    }
}