#include <queue>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> plli;
int main() {
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    ll ans = 0;

    priority_queue<plli, vector<plli>, greater<plli>> next;
    next.push({0, 1});
    bitset<100005> visited;

        while (!next.empty()) {
        auto [cost, node] = next.top();
        next.pop();
        if (visited[node])
            continue;
        visited.set(node);
        ans += cost;

        for (auto [nc, nn] : adj[node]) {
            if (visited[nn])
                continue;
            next.push({nc, nn});
        }
    }

    if (visited.count() < n) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<ans<<'\n';
}
