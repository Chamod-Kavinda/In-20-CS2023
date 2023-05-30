#include <iostream>
#include <vector>
#include <climits>
#include <stack>

#define V 6

using namespace std;

int minKey(vector<int> dist, vector<bool> visited) {
    int minVal = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(vector<int>& parent, int city) {
    stack<int> path;
    while (city != -1) {
        path.push(city);
        city = parent[city];
    }

    cout << "Path = ";
    cout << path.top();
    path.pop();
    while (!path.empty()) {
        cout << "->" << path.top();
        path.pop();
    }
    cout << endl;
}

void dijkstra(vector<vector<int>> graph, int source_city) {
    vector<int> parent(V);
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[source_city] = 0;
    parent[source_city] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] + dist[u] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (i != source_city) {
            cout << "Distance of node " << i << " from node " << source_city << " = " << dist[i] << endl;
            printPath(parent, i);
        }
    }
}

int main() {
    vector<vector<int>> graph = { { 0, 10, 0, 0, 15, 5 },
                                 { 10, 0, 10, 30, 0, 0 },
                                 { 0, 10, 0, 12, 5, 0 },
                                 { 0, 30, 12, 0, 0, 20 },
                                 { 15, 0, 5, 0, 0, 0 },
                                 { 5, 0, 0, 20, 0, 0 } };

    int source_city = 0;

    dijkstra(graph, source_city);

    return 0;
}
