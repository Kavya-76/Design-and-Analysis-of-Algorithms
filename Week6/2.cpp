/*
Q2 :- Given a graph, design an algorithm and implement it using a program 
to find if a graph is bipartite or not. (Hint: use BFS) .
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int src, vector<int>&colors, vector<vector<int>>&adj)
{
    queue<int>q;
    colors[src] = 1;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int i: colors)
        {
            if(adj[src][i]==1)
            {
                if(colors[i]==0){
                    q.push(i);
                    colors[i] = -colors[node];
                }

                else if(colors[i]==colors[node])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
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

    vector<int>colors(n, 0);
    for(int i=0; i<n; i++)
    {
        if(colors[i]==0)
        {
            if(!isBipartite(i, colors, adj))
            {
                cout<<"Graph is not Bipartite"<<endl;
            }
            return 0; 
        }
    }
    cout<<"Graph is Bipartite"<<endl;
}