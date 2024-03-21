#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void countSort(vector<int> &nums)
{

    int n = nums.size();

    int max = nums[0];

    // To find the maximum element of the array
    for (int i = 1; i < n; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
    }

    // To find the frequency of each element in the array
    vector<int> count(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    nums = output;
}

int main()
{
    vector<int> nums;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    countSort(nums);
    printArray(nums);

    return 0;
}
