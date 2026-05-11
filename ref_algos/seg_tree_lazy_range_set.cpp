#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node
{
    ll value = 0;
    ll lazyVal = 0;
    bool hasLazy = false;   
};

Node operate(Node& a, Node& b)
{
    return {a.value + b.value, 0, false};
}

int n, q;
vector<ll> nums;
vector<Node> tree;

void build(int index, int low, int high)
{
    if(low == high)
    {
        tree[index].value = nums[low];
        return;
    }
 
    int mid = low + (high - low)/2;
    build(index<<1, low, mid);
    build(index<<1^1, mid+1, high);
 
    tree[index] = operate(tree[index<<1], tree[index<<1^1]);
}

void push(int index, int low, int high)
{
    if(tree[index].hasLazy) //There is a lazy update
    {
        tree[index].value = (ll)(high - low + 1) * tree[index].lazyVal;

        if(low != high) //We are not in a leaf
        {
            tree[index<<1].lazyVal = tree[index].lazyVal;
            tree[index<<1].hasLazy = true;

            tree[index<<1^1].lazyVal = tree[index].lazyVal;
            tree[index<<1^1].hasLazy = true;
        }

        tree[index].hasLazy = false;
        tree[index].lazyVal = 0;
    }
}

Node query(int a, int b, int index = 1, int low = 0, int high = n-1)
{
    push(index, low, high);

    if(high < a || b < low) return {0};

    if(a <= low && high <= b) return tree[index]; //We are in the correct range

    int mid = low + (high - low)/2;
    Node left = query(a, b, index<<1, low, mid);
    Node right = query(a, b, index<<1^1, mid+1, high);

    return operate(left, right);
}

void update(int a, int b, ll k, int index = 1, int low = 0, int high = n-1)
{
    push(index, low, high);

    if(high < a || b < low) return;

    if(a <= low && high <= b) //We are in a correct range
    {
        tree[index].lazyVal = k;
        tree[index].hasLazy = true;
        push(index, low, high);
        return;
    }

    int mid = low + (high - low)/2;
    update(a, b, k, index<<1, low, mid);
    update(a, b, k, index<<1^1, mid+1, high);

    tree[index] = operate(tree[index<<1], tree[index<<1^1]);
}

void _solve()
{
    int type; cin >> type;

    if(type == 1)
    {
        int l, r; cin >> l >> r;
        ll k; cin >> k;

        update(l-1, r-1, k);
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

    nums.assign(n, 0);
    tree.assign(4*n + 1, {});

    for(ll& i : nums) cin >> i;

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