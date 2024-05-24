#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<int> arr, int n)
{
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout<<endl;
}

void selectionSort(vector<int> &arr, int n, int &comparisions, int &swaps)
{
    int min_index;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            comparisions++;
        }
        swap(arr[min_index], arr[i]);
        swaps++;
    }
}

int main()
{
    int testcases, comparisions=0, swaps=0;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        selectionSort(arr, n, comparisions, swaps);

        cout<<"Array after sorting: ";
        printArray(arr, n);
        cout << "Comparisions: " << comparisions << endl;
        cout << "Swaps: " << swaps << endl;
    }
}