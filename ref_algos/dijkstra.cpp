#include <vector>
#include <queue>
#include <climits>
using namespace std;
long long dijkstra(
        vector<vector<pair<int, int>>> const& adj, 
        int start, int goal
        ) 
{
    int n = adj.size();
    vector<long long> distance(n+1, LLONG_MAX);

    priority_queue<
        pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long, long long>>> 
            next;
    // {cost, node}
    next.push({0, start});

    while (!next.empty()) 
    {
        auto [weight, node] = next.top();
        next.pop();

        if (weight >= distance[node])
            continue;

        distance[node] = weight;

        for (auto [nweight, nnode] : adj[node]) 
        {
            if (nweight + distance[node] >= distance[nnode])
                continue;
            next.push({nweight + distance[node], nnode});
        }
    }
    return distance[goal];
}
