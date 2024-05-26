/*
Q2 :- Design an algorithm and implement it using a program to solve 
previous question's problem using Bellman- Ford's shortest path algorithm.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>bellman_ford(vector<vector<int>>&adj, int src, int n)
{
    vector<int>dist(n, 1e9);
    dist[src] = 0;

    for(int k=0; k<n-1; k++)
    {   
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][j]!=0)
                {
                    int wt = adj[i][j];
                    if(dist[i]+wt<dist[j])
                    {
                        dist[j] = dist[i]+wt;
                    }
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n, source;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout<<"Enter source node: ";
    cin>>source;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    vector<int>paths;
    paths = bellman_ford(adj, source, n);
    
    for(int i=0; i<n; i++)
    {
        if(i!=source)
        {
            cout<<"Shortest distance of vertex "<<i<<" from Akshay's house: "<<paths[i]<<endl;
        }
    }
}