#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char S, char A, char D)    // S=source   A=auxiliary   D=Destination
{
    if(n==0)
    {
        return;
    }

    TowerOfHanoi(n-1, S, D, A);     // T(n-1)
    cout<<S<<"->"<<D<<endl;         // O(1)
    TowerOfHanoi(n-1, A, S, D);     // T(n-1)
}

int main()
{
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    TowerOfHanoi(n, 'S', 'A', 'D');
    return 0;
}

// T(n) = 2T(n-1)+1        on solving O(2^n)