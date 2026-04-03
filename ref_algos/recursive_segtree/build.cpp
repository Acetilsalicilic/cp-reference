#include "common.cpp"

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

