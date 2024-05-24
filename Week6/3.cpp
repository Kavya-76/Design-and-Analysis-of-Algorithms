/*
Q3 :- Given a directed graph, design an algorithm and implement it using a
program to find whether cycle exists in the graph or not.
*/

#include <iostream>
#include <vector>
using namespace std;

bool checkCycle(int node, vector<vector<int>>&adj, vector<int> &visited)
{
    visited[node] = 2;
    for (int i : adj[node])
    {
        if(adj[node][i]==0)
            continue;
        if (visited[i]==0)
        {
            if (checkCycle(i, adj, visited) == true)
            {
                cout<<node<<" "<<i;
                return true;
            }
        }

        else if (visited[i] == 2)
        {
            cout<<node<<" "<<i;
            return true;
        }
    }
    visited[node] = 1;
    return false;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (checkCycle(i, adj, visited) == true)
            {
                cout<<"There is a cycle in graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"There is no cycle in graph"<<endl;
}