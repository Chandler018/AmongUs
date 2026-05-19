#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    for (Edge e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mst.push_back(e);
            totalWeight += e.weight;
            unionSet(e.u, e.v, parent);
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    cout << "\nTotal weight of MST: " << totalWeight << endl;

    return 0;
}
