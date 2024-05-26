/*
Q3 :- Assume that same road construction project is given to another person.
The amount he will earn from this project is directly proportional to the
budget of the project. This person is greedy, so he decided to maximize the
budget by constructing those roads who have highest construction cost.
Design an algorithm and implement it using a program to find the maximum
budget required for the project.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int source;
    int destination;
    int weight;
};

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight > b.weight;
}

int find(int vertex, vector<int> &parent)
{
    if (parent[vertex] != vertex)
        parent[vertex] = find(parent[vertex], parent);
    return parent[vertex];
}
void unionSets(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}
int findMaximumBudget(int numVertices, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compareEdges);
    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);
    for (int i = 0; i < numVertices; i++)
        parent[i] = i;
    int maximumSpanningWeight = 0;
    int edgeCount = 0;
    for (const auto &edge : edges)
    {
        int rootSource = find(edge.source, parent);
        int rootDestination = find(edge.destination, parent);
        if (rootSource != rootDestination)
        {
            maximumSpanningWeight += edge.weight;
            unionSets(rootSource, rootDestination, parent, rank);
            edgeCount++;
            if (edgeCount == numVertices - 1)
                break;
        }
    }
    if (edgeCount != numVertices - 1)
    {
        cout << "Error: It is not possible to form a maximum spanning tree.\n";
        return -1;
    }
    return maximumSpanningWeight;
}
int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    vector<Edge> edges;
    cout << "Enter the graph (adjacency matrix or adjacency list):\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            int weight;
            cin >> weight;
            if (weight != 0 && i < j)
            {
                edges.push_back({i, j, weight});
            }
        }
    }
    int maximumSpanningWeight = findMaximumBudget(numVertices, edges);
    if (maximumSpanningWeight != -1)
        cout << "Maximum budget required: " << maximumSpanningWeight << endl;
    return 0;
}
