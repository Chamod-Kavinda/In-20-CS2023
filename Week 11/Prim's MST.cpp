#include <iostream>
#include <vector>
#include <climits>

#define V 6

using namespace std;

int minKey(vector<int> key, vector<bool> mstSet) {
    int minVal = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(vector<int> parent, vector<vector<int>> graph) {
    std::cout << "Edge \t:  Weight\n";
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "\t:    " << graph[i][parent[i]] << std::endl;
    }
}

void primMST(vector<vector<int>> graph) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = { { 0, 3, 0, 0, 0, 1 },
                                { 3, 0, 2, 1, 10, 0 },
                                { 0, 2, 0, 3, 0, 5 },
                                { 0, 1, 3, 0, 5, 0 },
                                { 0, 10, 0, 5, 0, 4 },
                                { 1, 0, 5, 0, 4, 0 } };

    primMST(graph);

    return 0;
}
