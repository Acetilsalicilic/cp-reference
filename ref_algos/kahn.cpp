#include <bits/stdc++.h>
using namespace std;
int V; // Number of vertices
int E; // Number of edges
vector<int> indegree(V+1,0); // Needs to be populated

vector<int> kahn(vector<vector<int>> const& graph)
{
    vector<int> order, deg = indegree; // copy
    queue<int> q;
    for(int i = 1; i <= V; i++)
        if(deg[i] == 0)
            q.push(i);
    while(! q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v : graph[u]) {
            deg[v]--;
            if(deg[v] == 0)
                q.push(v);
        }
    }
    return order;
};
