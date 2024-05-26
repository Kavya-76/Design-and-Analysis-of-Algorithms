/*
Q3 :- Given an unsorted array of elements, design an algorithm and
implement it using a program to find whether majority element exists or not.
Also find median of the array. A majority element is an element that appears
more than n/2 times, where n is the size of array.
*/

#include <iostream>
#include <algorithm>
using namespace std;
void findMajorityElementAndMedian(int n, int arr[])
{
    sort(arr, arr + n); 
    int majority_count = n / 2;
    int majority_element = arr[majority_count];
    
    for (int i = 0; i <= n - majority_count; i++)
    {
        if (arr[i] == majority_element)
        {
            majority_count--;
            if (majority_count == 0)
                break;
        }
    }
    
    if (majority_count > 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    
    if (n % 2 == 1)
        cout << "Median: " << arr[n / 2] << endl;
    else
        cout << "Median: " << (arr[n / 2 - 1] + arr[n / 2]) / 2.0 << endl;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findMajorityElementAndMedian(n, arr);
    return 0;
}