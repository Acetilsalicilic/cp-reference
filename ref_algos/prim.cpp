#include <bitset>
#include <vector>
#include <queue>
using namespace std;
long long dijkstra(
        vector<vector<pair<int, int>>> const& adj
        ) 
{
    long long ans = 0;
    priority_queue<
        pair<long long, int>, 
        vector<pair<long long, int>>, 
        greater<pair<long long, int>>> 
            next;
    next.push({0, 1});
    bitset<100005> visited;
    while (!next.empty()) 
    {
        auto [cost, node] = next.top();
        next.pop();
        if (visited[node])
            continue;
        visited.set(node);
        ans += cost;

        for (auto [nc, nn] : adj[node]) 
        {
            if (visited[nn])
                continue;
            next.push({nc, nn});
        }
    }
    return ans;
}
