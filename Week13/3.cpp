/*
Q3 :- Given an array of nonnegative integers, Design an algorithm and
implement it using a program to find two pairs (a,b) and (c,d) such that a*b =
c*d, where a, b, c and d are distinct elements of array.
*/

    #include <iostream>
    #include <unordered_set>
    #include <vector>
    using namespace std;
    int main()
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = arr[i];
                int b = arr[j];

                for (int k = 0; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        int c = arr[k];
                        int d = arr[l];

                        if (a * b == c * d && a != b && a != c && a != d && b != c && b != d)
                        {
                            cout << "Pair (a, b): (" << a << ", " << b << ")" << endl;
                            cout << "Pair (c, d): (" << c << ", " << d << ")" << endl;
                            return 0;
                        }
                    }
                }
            }
        }

        cout << "No such pairs exist" << endl;

        return 0;
    }
