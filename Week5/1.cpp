#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countingSort(vector<char>&arr)
{
    vector<int>count(26,0);
    for(int i=0; i<arr.size(); i++)
    {
        count[arr[i]-'a']++;
    }

    int maxCount = 0;
    char maxChar = 'a';
    for(int i=0; i<count.size(); i++)
    {
        if(count[i]>maxCount)
        {
            maxCount = count[i];
            maxChar = 'a'+i;
        }
    }

    cout<<maxChar<<endl;
}

int main()
{
    int testcases;
    cout<<"Enter number of testcases: ";
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        vector<char> arr;
        cout<<"Enter number of elements: ";
        cin >> n;
        cout<<"Enter the elements: ";
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            arr.push_back(temp);
        }
        countingSort(arr);
    }
}