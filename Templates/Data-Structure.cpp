#include <bits/stdc++.h>
using namespace std;

// array
int arr[100];  // array of 100 integers
vector<int> arr(100);  // array of 100 integers

// unordered map faster than vector

    unordered_map<string, int> ump;  // hash table
    // ump["cat"] = 5;

//-------------------------------//
//        BASIC STRUCTS          //
//-------------------------------//

// Pair (similar to std::pair, but you can add methods if needed)
struct Pair {
    int first, second;
    Pair(int f = 0, int s = 0) : first(f), second(s) {}
};

// Node for linked list / tree
struct Node {
    int val;
    Node* next;
    Node* left;
    Node* right;
    Node(int v = 0) : val(v), next(nullptr), left(nullptr), right(nullptr) {}
};

// Edge for graphs
struct Edge {
    int u, v;
    int w; // weight (can ignore if unweighted)
    Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

//-------------------------------//
//         GRAPH TEMPLATE        //
//-------------------------------//

struct Graph {
    int n; // number of nodes
    vector<vector<Edge>> adj;

    Graph(int _n = 0) {
        n = _n;
        adj.assign(n + 1, {}); // 1-indexed
    }

    void addEdge(int u, int v, int w = 1, bool directed = false) {
        adj[u].push_back(Edge(u, v, w));
        if (!directed) adj[v].push_back(Edge(v, u, w));
    }
};

//-------------------------------//
//         DISJOINT SET          //
//-------------------------------//

struct DSU {
    vector<int> parent, sz;
    DSU(int n = 0) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

//-------------------------------//
//          EXAMPLE USAGE        //
//-------------------------------//

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example: Graph with 5 nodes
    Graph g(5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);

    cout << "Graph adjacency list:\n";
    for (int i = 1; i <= 5; i++) {
        for (auto &e : g.adj[i]) {
            cout << i << " -> " << e.v << " (w=" << e.w << ")\n";
        }
    }

    // Example: DSU (Union-Find)
    DSU dsu(5);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    cout << "Find(2) = " << dsu.find(2) << "\n";
    cout << "Find(4) = " << dsu.find(4) << "\n";

    return 0;
}
