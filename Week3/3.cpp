#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

bool isDuplicate(vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        vector<int> arr;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        if (isDuplicate(arr))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}