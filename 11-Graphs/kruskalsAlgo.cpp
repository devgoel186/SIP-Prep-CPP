// Spanning tree is a tree which is made up of all vertices in a graph whose weight sum is minimum

// Kruskal's Algorithm - Total Vertices - N ; Total Edges in MST - N - 1
// Complexity = Sorting Input (O(nlogn)) + Cycle Detection (O(EV))
// In worst case, E = V^2

#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
    int source;
    int dest;
    int weight;
};

bool compare(Edge k1, Edge k2)
{
    return k1.weight < k2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void kruskalsAlgo(Edge *input, int n, int e)
{
    sort(input, input + n, compare);
    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != n - 1)
    {
        Edge curr = input[i];
        int sourceParent = findParent(curr.source, parent);
        int destParent = findParent(curr.dest, parent);

        if (sourceParent != destParent)
        {
            output[count] = curr;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    cout << "\n### MST (Minimum Spanning Tree) ###" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskalsAlgo(input, n, e);
}