#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)                     // o(1)
    {
        return n;
    }
    return fib(n-1)+fib(n-2);             // T(n-1)+T(n-2)
}

int main()
{
    int n;
    cout<<"Enter term: ";
    cin>>n;
    cout<<"Term at index "<<n<<" is "<<fib(n)<<endl;
    return 0;
}

// T(n) = T(n-1)+T(n-2)+1          on solving            O(2^n)