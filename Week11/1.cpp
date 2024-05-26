/*
Q1 :- .Given a sequence of matrices, write an algorithm to find most efficient
way to multiply these matrices together. To find the optimal solution, you
need to find the order in which these matrices should be multiplied.
*/

#include <iostream>
#include <climits>
using namespace std;
int matrixChainMultiplication(int dimensions[], int n)
{
    int dp[n][n];
    
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[1][n - 1]; 
}
int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int dimensions[n + 1];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> dimensions[i];
    }
    int minOperations = matrixChainMultiplication(dimensions, n + 1);
    cout << "Minimum number of operations: " << minOperations << endl;
    return 0;
}
