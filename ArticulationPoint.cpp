#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void DFS(vector<int> adj[], int discoveryTime[], int lowTime[], vector<bool> &isVisited, vector<bool> &isArticulationPoint, int node, int parent)
{
    discoveryTime[node] = timer;
    lowTime[node] = timer;
    timer++;
    isVisited[node] = true;
    int children = 0;
    for (int &x : adj[node])
    {
        if (!isVisited[x])
        {
            children++;
            DFS(adj, discoveryTime, lowTime, isVisited, isArticulationPoint, x, node);
            lowTime[node] = min(lowTime[node], lowTime[x]);
            if (discoveryTime[node] <= lowTime[x] && parent != -1)
                isArticulationPoint[node] = true;
        }
        else if (x != parent)
            lowTime[node] = min(lowTime[node], discoveryTime[x]);
    }
    if (parent == -1 && children > 1)
        isArticulationPoint[0] = true;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    int discoveryTime[V];
    int lowTime[V];
    vector<bool> isVisited(V, false);
    vector<bool> isArticulationPoint(V, false);
    DFS(adj, discoveryTime, lowTime, isVisited, isArticulationPoint, 0, -1);
    vector<int> articulationPoints;
    for (int i = 0; i < V; i++)
        if (isArticulationPoint[i])
            articulationPoints.push_back(i);
    if (articulationPoints.size() == 0)
        return {-1};
    return articulationPoints;
}
