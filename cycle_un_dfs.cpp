#include <bits/stdc++.h>
using namespace std;

bool detectcycleDFS(unordered_map<int, vector<int>> &graph, int parent, int source, vector<int> &visited)
{
    visited[source] = 1;
    for (auto i : graph[source])
    {
        if (i == parent)
        {
            continue;
        }
        if (visited[i])
        {
            return true;
        }
        if (detectcycleDFS(graph, source, i, visited))
        {
            return true;
        }
    }
    return false;
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
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && detectcycleDFS(graph, -1, i, visited))
        {
            return true;
        }
    }
    return false;
}
