// Given a graph. Design an algorithm and implement it using a program to implement floyd-warshall algorithms(all pair shortest path algorithm)

#include <iostream>
#include <vector>
#define INF 99999

using namespace std;

void floydWarshall(int graph[][100], int V) {
    vector<vector<int>>dist(V,vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    
    floydWarshall(graph, V);

    return 0;
}