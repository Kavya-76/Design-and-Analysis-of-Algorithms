/*
Q1 :- Given a (directed/undirected) graph, design an algorithm and 
implement it using a program to find if a path exists between two given 
vertices or not. (Hint: use DFS)
*/

#include <iostream>
#include <vector>
using namespace std;

bool checkPath(vector<vector<int>>&adj, int src, int des, vector<int>&visited, int n)
{
    if(src==des)
    {
        return true;
    }

    visited[src] = 1;
    for(int i=0; i<n; i++)
    {
        if(adj[src][i]==1 && !visited[i])
        {
            if(checkPath(adj, i, des, visited, n))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, source, destination;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    vector<vector<int>>adj(n, vector<int>(n, 0));
    cout<<"Enter adjacency matrix: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>adj[i][j];
        }
    }

    cout<<"Enter source: ";
    cin>>source;
    cout<<"Enter destination: ";
    cin>>destination;

    vector<int>visited(n, 0);
    if(checkPath(adj, source, destination, visited, n))
    {
        cout<<"Yes path exists"<<endl;
    }

    else{
        cout<<"Path does not exists"<<endl;
    }
    return 0;
}