#include <bits/stdc++.h>
 
using namespace std;
 
struct Node
{
    int value = INT_MAX;
};
 
Node operate(Node a, Node b)
{
    return {min(a.value, b.value)};
}
 
int n, q;
vector<Node> nums, tree;
 
void build(int index, int low, int high)
{
    if(low == high)
    {
        tree[index].value = nums[low].value;
        return;
    }
 
    int mid = low + (high - low)/2;
    build(index<<1, low, mid);
    build(index<<1^1, mid+1, high);
 
    tree[index] = operate(tree[index<<1], tree[index<<1^1]);
}
 
Node query(int a, int b, int index = 1, int low = 0, int high = n-1)
{
    if(high < a || b < low)
        return {INT_MAX};
 
    if(a <= low && high <= b)
        return tree[index];
 
    int mid = low + (high - low)/2;
    Node left = query(a, b, index<<1, low, mid);
    Node right = query(a, b, index<<1^1, mid+1, high);
 
    return operate(left, right);
}
 
void update(int pos, int val, int index = 1, int low = 0, int high = n-1)
{
    if(low == high)
    {
        tree[index].value = val;
        return;
    }
 
    int mid = low + (high - low)/2;
 
    if(pos <= mid)
        update(pos, val, index<<1, low, mid);
    else
        update(pos, val, index<<1^1, mid+1, high);
 
    tree[index] = operate(tree[index<<1], tree[index<<1^1]);
}
 
void _solve()
{
    int type; cin >> type;
 
    if(type == 1)
    {
        int k, u; cin >> k >> u;
        update(k-1, u);
    }
    else
    {
        int a, b; cin >> a >> b;
        
        Node ans = query(a-1, b-1);
 
        cout << ans.value << "\n";
    }
}
 
void solve()
{
    cin >> n >> q;
 
    nums.assign(n, {});
    tree.assign(4*n + 1, {INT_MAX});
 
    for(Node& i : nums) cin >> i.value;
 
    build(1, 0, n-1);
 
    while(q--)
        _solve();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    solve();
 
    return 0;
}