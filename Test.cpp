//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    class DisjointSet
    {
        int *size;
        int *parent;

    public:
        DisjointSet(int n) : size(new int[n]), parent(new int[n])
        {
            for (int i = 0; i < n; i++)
            {
                size[i] = 1;
                parent[i] = i;
            }
        }
        int find(int x)
        {
            if (x == parent[x])
                return x;
            parent[x] = find(parent[x]);
            return parent[x];
        }
        void unionBySize(int x, int y)
        {
            int x_rep = find(x);
            int y_rep = find(y);
            if (x_rep == y_rep)
                return;
            if (size[x_rep] < size[y_rep])
            {
                parent[x_rep] = y_rep;
                size[y_rep] += size[x_rep];
            }
            else
            {
                parent[y_rep] = x_rep;
                size[x_rep] += size[y_rep];
            }
        }
        bool isSameComponent(int x, int y)
        {
            return find(x) == find(y);
        }
    };

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
            for (auto &v : adj[i])
                edges.push_back({v[1], {i, v[0]}});

        sort(edges.begin(), edges.end());
        int weight = 0;
        DisjointSet DSU(V);
        for (auto &edge : edges)
        {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (!DSU.isSameComponent(u, v))
            {
                weight += wt;
                DSU.unionBySize(u, v);
            }
        }
        return weight;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends