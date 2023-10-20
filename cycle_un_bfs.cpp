#include <bits/stdc++.h>
using namespace std;

bool cycle_un_BFS(unordered_map<int, vector<int>> &graph, vector<int> &visited, int source)
{
    queue<pair<int, int>> q;
    q.push({source, -1});
    visited[source] = 1;
    while (!q.empty())
    {
        int src = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto i : graph[src]) // Corrected 'graph[src]' instead of 'graph[source]'
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push({i, src});
            }
            else if (par != i)
            {
                return true;
            }
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
        graph[y].push_back(x);
    }
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && cycle_un_BFS(graph, visited, i))
        {
            return true;
        }
    }
    return false;
}