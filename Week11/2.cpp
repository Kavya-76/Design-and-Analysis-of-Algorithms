/*
Q2 :- Given a set of available types of coins. Let suppose you have infinite
supply of each type of coin. For a given value N, you have to Design an
algorithm and implement it using a program to find number of ways in which
these coins can be added to make sum value equals to N.
*/

#include <iostream>
#include <vector>
using namespace std;
int coinChange(int coins[], int n, int N)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= N; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[N];
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int coins[n];
    cout << "Enter the values of coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    int ways = coinChange(coins, n, N);
    cout << "Number of ways to make sum " << N << ": " << ways << endl;
    return 0;
}