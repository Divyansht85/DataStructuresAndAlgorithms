//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void DFS(vector<vector<int>> &adj, vector<bool> &isVisited, stack<int> &st, int node)
    {
        isVisited[node] = true;
        for (int &x : adj[node])
            if (!isVisited[x])
                DFS(adj, isVisited, st, x);
        st.push(node);
    }
    void DFS2(vector<int> adj[], vector<bool> &isVisited, int node)
    {
        isVisited[node] = true;
        for (int &x : adj[node])
            if (!isVisited[x])
                DFS2(adj, isVisited, x);
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> st;
        vector<bool> isVisited(V, false);
        for (int i = 0; i < V; i++)
            if (!isVisited[i])
                DFS(adj, isVisited, st, i);
        vector<int> revAdj[V];
        for (int i = 0; i < V; i++)
        {
            isVisited[i] = false;
            for (int &x : adj[i])
                revAdj[x].push_back(i);
        }
        int scc = 0;
        while (!st.empty())
        {
            if (!isVisited[st.top()])
            {
                scc++;
                DFS2(revAdj, isVisited, st.top());
            }
            st.pop();
        }
        return scc;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends