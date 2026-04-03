#include <bits/stdc++.h>
using namespace std;

vector<int> tree; // size() = len = N * 2
vector<int> a; // size() = n
int n, N, len;

/* build the tree */
void build(int tl=0, int tr=n-1, int i=1) {
    // range is [tl, tr]. If tr < tl, it isn't a valid range
    if (tr < tl) return;
    // if tl = tr, we've reached a leaf
    if (tl == tr) {
        // set the leaves of the tree
        tree[i] = a[tl];
        return;
    }

    int mid = tl + (tr - tl)/2;

    // update the children recursively
    build(tl, mid, i<<1);
    build(mid+1, tr, i<<1^1);

    // update parent with new children's values
    // desired operator instead '+'
    tree[i] = tree[i<<1] + tree[i<<1^1];
}

/* update in a location */
void update(int pos, int val, int tl=0, int tr=n-1, int i=1) {
    if (tr < tl) return;
    if (tl == tr) {
        tree[i] = val;
        return;
    }

    int mid = tl + (tr - tl)/2;

    if (pos > mid)
        update(pos, val, mid+1, tr, i<<1^1);
    else
        update(pos, val, tl, mid, i<<1);

    tree[i] = tree[i<<1] + tree[i<<1^1];
}

/* query a range */
int query(int l, int r, int tl=0, int tr=n-1, int i=1) {
    if (tr < l || tl > r) return 0; // the identity value instead of 0
    // if [l, r] is the range, and l <= tl <= tr <= r, then we want this
    // node, cause it's on the desired range.
    if (tl >= l && tr <= r) {
        return tree[i];
    }

    int mid = tl + (tr - tl)/2;

    // the desired operator instead of +
    return query(l, r, tl, mid, i<<1) + query(l, r, mid+1, tr, i<<1^1);
}
