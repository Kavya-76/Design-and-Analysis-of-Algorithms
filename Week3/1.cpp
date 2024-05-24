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

void insertionSort(vector<int> &arr, int n, int &comparisions, int &shifts)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;

            shifts++;
            comparisions++;
        }
        arr[j + 1] = key;
        shifts++;
    }
    cout << "Comparisions: " << comparisions << endl;
    cout << "Shifts: " << shifts << endl;
}

int main()
{
    int testcases, comparisions=0, shifts=0;
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
        insertionSort(arr, n, comparisions, shifts);

        cout<<"Array after sorting: ";
        printArray(arr, n);
        cout<<"Comparisions: "<<comparisions<<endl;
        cout<<"Shifts: "<<shifts<<endl;
    }
}