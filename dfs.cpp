#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &graph, int source, vector<int> &visited, vector<int> &result)
{
    visited[source] = 1;
    result.push_back(source);
    for (auto child : graph[source])
    {
        if (!visited[child])
        {
            dfs(graph, child, visited, result);
        }
    }
    return;
}
int main()
{
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<int>> graph;

    // Assuming adjacency list is given
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    vector<int> visited(v, 0);
    vector<int> result;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, result);
        }
    }
    for (auto i : result)
        cout << i << " ";
}