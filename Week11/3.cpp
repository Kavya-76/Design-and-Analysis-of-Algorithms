/*
Q3 :- Given a set of elements, you have to partition the set into two subsets
such that the sum of elements in both subsets is same. Design an algorithm
and implement it using a program to solve this problem.
*/

#include <iostream>
#include <vector>
using namespace std;
bool partitionSet(int set[], int currentIndex, int subsetSum1, int subsetSum2, int subsetSize1,
                  int subsetSize2)
{
    int n = subsetSize1 + subsetSize2;
    if (subsetSum1 == subsetSum2 && n == currentIndex)
    {
        return true;
    }
    if (currentIndex == n)
    {
        return false;
    }
    return partitionSet(set, currentIndex + 1, subsetSum1 + set[currentIndex], subsetSum2,
                        subsetSize1 + 1, subsetSize2) ||
           partitionSet(set, currentIndex + 1, subsetSum1, subsetSum2 + set[currentIndex],
                        subsetSize1, subsetSize2 + 1) ||
           partitionSet(set, currentIndex + 1, subsetSum1, subsetSum2, subsetSize1,
                        subsetSize2);
}
bool canPartition(int set[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += set[i];
    }
    if (totalSum % 2 != 0)
    {
        return false;
    }
    return partitionSet(set, 0, 0, 0, 0, 0);
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int set[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    if (canPartition(set, n))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
