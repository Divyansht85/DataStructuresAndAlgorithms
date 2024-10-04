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