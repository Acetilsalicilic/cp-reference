#include <vector>
using namespace std;
typedef long long ll;
ll knapsack(int n, int cap, 
        vector<int> const& weights, 
        vector<int> const& values) {
    vector<ll> dp(n+1, -1);
    dp[0]=0;

    for (int item = 0; item <= cap; item++) {
        for (int price=n; price >= weights[item]; price--) {
            if (weights[item - weights[item]] != -1)
                dp[price] = 
                    max(dp[price], 
                        dp[price - weights[item]] + values[item]);
        }
    }

    ll ans = -1;
    for (ll e: dp)
        ans = max(ans, e);
    return ans;
}
