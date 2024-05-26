/*
Q2 :- Given a directed graph, write an algorithm and a program to find
mother vertex in a graph. A mother vertex is a vertex v such that there exists
a path from v to all other vertices of the graph.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int n, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[n] = true;

    for (int i=0; i<n; i++)
        if (adj[n][i]==1 && !visited[i])
            dfs(i, visited, adj);
}

int findMotherVertex(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int lastFinishedVertex = 0;

    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adj);
            lastFinishedVertex = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(lastFinishedVertex, visited, adj);

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            return -1; 
    }
    return lastFinishedVertex;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>adj[i][j];
        }
    }

    int motherVertex = findMotherVertex(n, adj);
    if (motherVertex == -1)
        cout << "No mother vertex exists in the graph." << endl;
    else
        cout << "The mother vertex is: " << motherVertex << endl;

    return 0;
}
