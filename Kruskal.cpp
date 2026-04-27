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

int parent[100];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v) {
    parent[u] = v;
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    for (auto e : edges) {
        int u = find(e.u);
        int v = find(e.v);

        if (u != v) {
            cout << e.u << " - " << e.v << " : " << e.weight << endl;
            unionSet(u, v);
        }
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    kruskal(V, edges);
}