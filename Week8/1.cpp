/*
Q1 :- Assume that a project of road construction to connect some cities is 
given to your friend. Map of these cities and roads which will connect them 
(after construction) is provided to him in the form of a graph. Certain amount 
of rupees is associated with construction of each road. Your friend has to 
calculate the minimum budget required for this project. The budget should 
be designed in such a way that the cost of connecting the cities should be 
minimum and number of roads required to connect all the cities should be 
minimum (if 3 there are N cities then only N-1 roads need to be constructed). 
He asks you for help. Now, you have to help your friend by designing an 
algorithm which will find minimum cost required to connect these cities. (use 
Prim's algorithm)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(int n, vector<vector<int>>adj)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>visited(n, 0);

    int sum = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(!visited[node])
        {
            visited[node]=1;
            sum+=wt;
            for(int i=0; i<n; i++)
            {
                if(adj[node][i]!=0)
                {
                    int adjNode = i;
                    int edgeWt = adj[node][i];
                    if(!visited[adjNode])
                    {
                        pq.push({edgeWt, adjNode});
                    }
                }

            }
        }
    }
    return sum;
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

    int ans = minCost(n, adj);
    cout<<"Minimum cost to connect all the cities: "<<ans<<endl;
    return 0;
}
