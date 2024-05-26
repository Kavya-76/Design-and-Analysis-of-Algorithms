/*
Q2 :- Implement the previous problem using Kruskal's algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int src, dest, weight;
};

bool compareEdges(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}

int find(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(vector<int> &parent, vector<int> &rank, int i, int j)
{
    int iRoot = find(parent, i);
    int jRoot = find(parent, j);
    if (rank[iRoot] < rank[jRoot])
        parent[iRoot] = jRoot;
    else if (rank[iRoot] > rank[jRoot])
        parent[jRoot] = iRoot;
    else
    {
        parent[jRoot] = iRoot;
        rank[iRoot]++;
    }
}

int findMinimumSpanningWeight(vector<Edge> &edges, int numVertices)
{
    sort(edges.begin(), edges.end(), compareEdges);
    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);
    for (int i = 0; i < numVertices; i++)
    {
        parent[i] = i;
    }
    int minimumSpanningWeight = 0;
    int edgeCount = 0;
    for (const Edge &edge : edges)
    {
        int srcRoot = find(parent, edge.src);
        int destRoot = find(parent, edge.dest);
        if (srcRoot != destRoot)
        {
            minimumSpanningWeight += edge.weight;
            unionSets(parent, rank, srcRoot, destRoot);
            edgeCount++;
            if (edgeCount == numVertices - 1)
            {
                break;
            }
        }
    }
    return minimumSpanningWeight;
}
int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<Edge> edges;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = i + 1; j < numVertices; j++)
        {
            if (graph[i][j] != 0)
            {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }
    int ans = findMinimumSpanningWeight(edges, numVertices);
    cout<<"Minimum cost to connect all the cities: "<<ans<<endl;
    return 0;
}
