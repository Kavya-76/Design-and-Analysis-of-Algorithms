    #include <iostream>
    #include <vector>
    using namespace std;

    void binarySearchIterative(vector<int>nums, int key)
    {
        int s=0; 
        int e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<=e)
        {
            if(nums[mid]==key)
            {
                cout<<"Value found at index: "<<mid<<endl;
                return;
            }

            else if(nums[mid]>key)
            {
                e = mid-1;
            }

            else
            {
                s = mid+1;
            }

            mid = s+(e-s)/2;
        }
        cout<<"Key not found"<<endl;
    }

    void binarySearchRecursive(vector<int>nums, int key, int s, int e)
    {
        if(s>e)
        {
            cout<<"Key not found"<<endl;
            return;
        }

        int mid = s+(e-s)/2;
        if(nums[mid]==key)
        {
            cout<<"Key found at index "<<mid<<endl;
            return;
        }

        else if(nums[mid]>key)
        {
            binarySearchRecursive(nums, key, s, mid-1);
        }

        else
        {
            binarySearchRecursive(nums, key, mid+1, e);
        }
    }
    int main()
    {
        vector<int>nums;
        int n;
        cout<<"Enter the size of array: ";
        cin>>n;
        cout<<"Enter the values: ";
        for(int i=0; i<n; i++)
        {
            int val;
            cin>>val;
            nums.push_back(val);
        }

        int key;
        cout<<"Enter the element to be searched: ";
        cin>>key;
        // binarySearchIterative(nums, key);
        binarySearchRecursive(nums, key, 0, nums.size()-1);
        return 0;
    }