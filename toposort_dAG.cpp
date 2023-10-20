#include <bits/stdc++.h>
using namespace std;

void toposort(unordered_map<int, vector<int>> &graph, int source, vector<int> &visited, stack<int> &result)
{
    visited[source] = 1;
    for (auto i : graph[source])
    {
        if (!visited[i])
            toposort(graph, i, visited, result);
    }
    result.push(source);
}
int main()
{
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    stack<int> result;
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            toposort(graph, i, visited, result);
    }
}