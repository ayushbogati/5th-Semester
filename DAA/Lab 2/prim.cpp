#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int parent[100];       // store MST
    int key[100];          // weight to pick minimum
    bool mstSet[100];      // vertices included in MST

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;    // start from vertex 0
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        // Pick minimum key vertex not in MST
        int minKey = INT_MAX, u;
        for (int v = 0; v < n; v++)
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }

        mstSet[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print MST
    int totalWeight = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }

    cout << "Total weight of MST: " << totalWeight;

    return 0;
}

