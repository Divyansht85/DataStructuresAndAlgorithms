#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity;
    int size;

    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void createNewHeap()
    {
        int *temp = new int[2 * capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        capacity *= 2;
    }

public:
    MinHeap(int c = 10) : arr(new int[c]), capacity(c), size(0)
    {
        if (c <= 0)
        {
            capacity = 10; // default capacity if an invalid size is given
            arr = new int[capacity];
        }
    }

    ~MinHeap()
    {
        delete[] arr;
    }
    void printHeapAsTree()
    {
        if (size == 0)
            return;

        struct NodeInfo
        {
            int index;
            int depth;
            int pos;
        };

        int h = log2(size) + 1;
        int max_width = (1 << h) - 1;
        vector<string> lines(h * 2 - 1, string(max_width * 4 - 1, ' ')); // Increased space for better alignment

        queue<NodeInfo> q;
        q.push({0, 0, max_width / 2});

        while (!q.empty())
        {
            NodeInfo curr = q.front();
            q.pop();

            int pos = curr.pos * 4; // Adjust the position multiplier for better spacing
            string value = to_string(arr[curr.index]);
            for (int i = 0; i < value.length(); i++)
            {
                lines[curr.depth * 2][pos + i] = value[i];
            }

            int left = leftChild(curr.index);
            int right = rightChild(curr.index);

            if (left < size)
            {
                q.push({left, curr.depth + 1, curr.pos - (1 << (h - curr.depth - 2))});
                lines[curr.depth * 2 + 1][pos - (1 << (h - curr.depth - 2)) * 2] = '/';
            }
            if (right < size)
            {
                q.push({right, curr.depth + 1, curr.pos + (1 << (h - curr.depth - 2))});
                lines[curr.depth * 2 + 1][pos + (1 << (h - curr.depth - 2)) * 2] = '\\';
            }
        }

        for (const string &line : lines)
        {
            cout << line << endl;
        }
        cout << endl
             << endl
             << endl;
    }

    void insert(int d)
    {
        if (size == capacity)
            createNewHeap();

        size++;
        arr[size - 1] = d;

        for (int i = size - 1; i > 0 && arr[i] < arr[parent(i)]; i = parent(i))
        {
            swap(arr[i], arr[parent(i)]);
        }
    }

    void minHeapify(int i)
    {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] < arr[minIndex])
            minIndex = left;
        if (right < size && arr[right] < arr[minIndex])
            minIndex = right;

        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            minHeapify(minIndex);
        }
    }

    void makeHeap(vector<int> &v)
    {
        if (arr != nullptr)
            delete[] arr;

        capacity = v.size();
        size = v.size();
        arr = new int[capacity];

        for (int i = 0; i < v.size(); i++)
            arr[i] = v[i];

        for (int i = (size - 2) / 2; i >= 0; i--)
            minHeapify(i);
    }
    void extractMin()
    {
        if (size == 0)
            return;
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
    }
    void decreaseKey(int i, int x)
    {
        if (i < size)
        {
            arr[i] = x;
            for (i; i > 0; i = parent(i))
                if (arr[i] < arr[parent(i)])
                    swap(arr[i], arr[parent(i)]);
        }
    }
    void deleteKey(int i)
    {
        if (i < size)
        {
            decreaseKey(i, INT_MIN);
            extractMin();
        }
    }
    void printHeapAsArray()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
class MaxHeap
{
    int *arr;
    int capacity;
    int size;

    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void createNewHeap()
    {
        int *temp = new int[2 * capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        capacity *= 2;
    }

public:
    MaxHeap(int c = 10) : arr(new int[c]), capacity(c), size(0)
    {
        if (c <= 0)
        {
            capacity = 10; // default capacity if an invalid size is given
            arr = new int[capacity];
        }
    }

    ~MaxHeap()
    {
        delete[] arr;
    }
    void printHeapAsTree()
    {
        if (size == 0)
            return;

        struct NodeInfo
        {
            int index;
            int depth;
            int pos;
        };

        int h = log2(size) + 1;
        int max_width = (1 << h) - 1;
        vector<string> lines(h * 2 - 1, string(max_width * 4 - 1, ' ')); // Increased space for better alignment

        queue<NodeInfo> q;
        q.push({0, 0, max_width / 2});

        while (!q.empty())
        {
            NodeInfo curr = q.front();
            q.pop();

            int pos = curr.pos * 4; // Adjust the position multiplier for better spacing
            string value = to_string(arr[curr.index]);
            for (int i = 0; i < value.length(); i++)
            {
                lines[curr.depth * 2][pos + i] = value[i];
            }

            int left = leftChild(curr.index);
            int right = rightChild(curr.index);

            if (left < size)
            {
                q.push({left, curr.depth + 1, curr.pos - (1 << (h - curr.depth - 2))});
                lines[curr.depth * 2 + 1][pos - (1 << (h - curr.depth - 2)) * 2] = '/';
            }
            if (right < size)
            {
                q.push({right, curr.depth + 1, curr.pos + (1 << (h - curr.depth - 2))});
                lines[curr.depth * 2 + 1][pos + (1 << (h - curr.depth - 2)) * 2] = '\\';
            }
        }

        for (const string &line : lines)
        {
            cout << line << endl;
        }
        cout << endl
             << endl
             << endl;
    }

    void insert(int d)
    {
        if (size == capacity)
            createNewHeap();

        size++;
        arr[size - 1] = d;

        for (int i = size - 1; i > 0 && arr[i] > arr[parent(i)]; i = parent(i))
        {
            swap(arr[i], arr[parent(i)]);
        }
    }

    void maxHeapify(int i)
    {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] > arr[maxIndex])
            maxIndex = left;
        if (right < size && arr[right] > arr[maxIndex])
            maxIndex = right;

        if (maxIndex != i)
        {
            swap(arr[i], arr[maxIndex]);
            maxHeapify(maxIndex);
        }
    }

    void makeHeap(vector<int> &v)
    {
        if (arr != nullptr)
            delete[] arr;

        capacity = v.size();
        size = v.size();
        arr = new int[capacity];

        for (int i = 0; i < v.size(); i++)
            arr[i] = v[i];

        for (int i = (size - 2) / 2; i >= 0; i--)
            maxHeapify(i);
    }
    void extractMax()
    {
        if (size == 0)
            return;
        swap(arr[0], arr[size - 1]);
        size--;
        maxHeapify(0);
    }
    void increaseKey(int i, int x)
    {
        if (i < size)
        {
            arr[i] = x;
            for (i; i > 0; i = parent(i))
                if (arr[i] > arr[parent(i)])
                    swap(arr[i], arr[parent(i)]);
        }
    }
    void deleteKey(int i)
    {
        if (i < size)
        {
            increaseKey(i, INT_MAX);
            extractMax();
        }
    }
    void printHeapAsArray()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    vector<int> v = {1, 2, 3, 6, 9, 2, 4, 5, 7, 8, 20};
    MaxHeap heap;
    heap.makeHeap(v);
    heap.printHeapAsTree();
    heap.printHeapAsArray();
    heap.deleteKey(4);
    heap.printHeapAsArray();
    heap.printHeapAsTree();
    return 0;
}
