#include <stdio.h>
// Function to merge two sorted subarrays into a single sorted subarray
int merge(int arr[], int temp[], int left, int mid, int right)
{
int i, j, k;
int inv_count = 0;
i = left; // index for left subarray
j = mid; // index for right subarray
k = left; // index for temp array
// Merge elements from left and right subarrays into temp array
while ((i <= mid - 1) && (j <= right))
{
if (arr[i] <= arr[j])
{
temp[k++] = arr[i++];
}
else
{
temp[k++] = arr[j++];
inv_count += (mid - i);
}
}
// Copy the remaining elements of left subarray into temp array
while (i <= mid - 1)
temp[k++] = arr[i++];
// Copy the remaining elements of right subarray into temp array
while (j <= right)
temp[k++] = arr[j++];
// Copy the merged elements from temp array back to original array
for (i = left; i <= right; i++)
arr[i] = temp[i];
return inv_count;
}
// Function to divide the array into two subarrays and merge them
int mergeSort(int arr[], int temp[], int left, int right)
{
int mid, inv_count = 0;
if (right > left)
{
mid = (right + left) / 2;
// Recursively sort left and right subarrays
inv_count += mergeSort(arr, temp, left, mid);
inv_count += mergeSort(arr, temp, mid + 1, right);
// Merge the sorted subarrays
inv_count += merge(arr, temp, left, mid + 1, right);
}
return inv_count;
}
int main()
{
int t, n, i, j, count, inversions;
scanf("%d", &t); // Number of test cases
for (i = 0; i < t; i++)
{
scanf("%d", &n); // Size of array
int arr[n], temp[n];
for (j = 0; j < n; j++)
scanf("%d", &arr[j]); // Input array elements
inversions = mergeSort(arr, temp, 0, n - 1); // Sort the array and count inversions
count = (n * (n - 1)) / 2 - inversions; // Calculate number of comparisons
// Output sorted array, number of comparisons, and number of inversions
printf("Sorted array: ");
for (j = 0; j < n; j++)
printf("%d ", arr[j]);
printf("\nNumber of comparisons: %d\n", count);
printf("Number of inversions: %d\n", inversions);
}
return 0;
}
