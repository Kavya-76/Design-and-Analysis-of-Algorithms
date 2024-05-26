// Given a graph. Design an algorithm and implement it using a program to implement floyd-warshall algorithms(all pair shortest path algorithm)

#include <iostream>
#include <vector>
#define INF 99999

using namespace std;

void floydWarshall(vector<vector<int>>&adj, int n)
{
    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = adj[i][j];
            if(adj[i][j]==-1)
            {
                dist[i][j]=1e9;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 1e9)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>>adj(n, vector<int>(n));
    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    floydWarshall(adj, n);

    return 0;
}