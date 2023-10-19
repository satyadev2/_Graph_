#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int source, vector<int> &visited, vector<int> &result)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int top = q.front();

        q.pop();
        result.push_back(top);
        for (auto i : graph[top])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
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
    vector<int> result;
    for (int i = 0; i < v; i++)
    {
        bfs(graph, 0, visited, result);
    }

    for (auto i : result)
    {
        cout << i << " ";
    }
}