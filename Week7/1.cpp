/*
Q1 :- After end term examination, Akshay wants to party with his friends. All 
his friends are living as paying guest and it has been decided to first gather at 
Akshay’s house and then move towards party location. The problem is that 
no one knows the exact address of his house in the city. Akshay as a 
computer science wizard knows how to apply his theory subjects in his real 
life and came up with an amazing idea to help his friends. He draws a graph 
by looking in to location of his house and his friends’ location (as a node in 
the graph) on a map. He wishes to find out shortest distance and path 
covering that distance from each of his friend’s location to his house and 
then whatsapp them this path so that they can reach his house in minimum 
time. Akshay has developed the program that implements Dijkstra’s 
algorithm but not sure about correctness of results. Can you also implement 
the same algorithm and verify the correctness of Akshay’s results? (Hint: 
Print shortest path and distance from friends’ location to Akshay’s house)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>dijkstra(vector<vector<int>>&adj, int src, int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n, 1e9);
    dist[src]=0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(int i=0; i<n; i++)
        {
            if(adj[node][i]!=0)
            {
                int edgeWt = adj[node][i];
                int adjNode = i;
                if(edgeWt+dis<dist[adjNode])
                {   
                    dist[adjNode] = edgeWt+dis;
                    pq.push({dist[adjNode], adjNode});
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
    cout<<"Enter Akshay's house vertex: ";
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
    paths = dijkstra(adj, source, n);
    
    for(int i=0; i<n; i++)
    {
        if(i!=source)
        {
            cout<<"Shortest distance of vertex "<<i<<" from Akshay's house: "<<paths[i]<<endl;
        }
    }
}