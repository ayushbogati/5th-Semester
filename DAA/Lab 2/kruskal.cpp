#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// Comparison function to sort edges by weight
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];  // for union-find

// Find function with path compression
int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

// Union function
void unionSet(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa != pb)
        parent[pb] = pa;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Initialize parent array
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Sort edges by weight
    sort(edges, edges + e, cmp);

    int mstWeight = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // If adding edge doesn't form cycle
        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v << " : " << w << "\n";
            mstWeight += w;
            unionSet(u, v);
        }
    }

    cout << "Total weight of MST: " << mstWeight;

    return 0;
}

