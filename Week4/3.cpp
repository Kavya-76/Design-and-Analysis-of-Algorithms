#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

int kthSmallest(vector<int>& nums, int low, int high, int k) {
    if (low <= high) 
    {
        int pivotIndex = partition(nums, low, high);

        if (pivotIndex == k - 1)
            return nums[pivotIndex];
        else if (pivotIndex > k - 1)
            return kthSmallest(nums, low, pivotIndex - 1, k);
        else
            return kthSmallest(nums, pivotIndex + 1, high, k);
    }
    return -1;
}

int kthLargest(vector<int>& nums, int low, int high, int k) {
    int n = nums.size();
    if (low <= high) {
        int pivotIndex = partition(nums, low, high);

        if (pivotIndex == n - k)
            return nums[pivotIndex];
        else if (pivotIndex > n - k)
            return kthLargest(nums, low, pivotIndex - 1, k);
        else
            return kthLargest(nums, pivotIndex + 1, high, k);
    }
    return -1;
}

int main() {

    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        vector<int> nums;
        int n, temp, k;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            nums.push_back(temp);
        }
        
        cin>>k;
        int result = kthSmallest(nums, 0, nums.size() - 1, k);
        int result2 = kthLargest(nums, 0, nums.size()-1, 2);
        if (result != -1 && result2!=-1)
        {
            cout << "K'th smallest element is " << result << endl;
            cout << "K'th largest element is " << result2 << endl;

        }
        else
        {
            cout << "K out of range." << endl;
        }
    }
}
