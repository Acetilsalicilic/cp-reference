#include "common.cpp"

void build(int tl=0, int tr=n-1, int i=1) {
    // the range of the current node is [tl, tr]
    // if tr < tl, then it's not a valid range
    if (tr < tl) return;

    // We've reached a leaf
    if (tl == tr) {
        // Since i is the node's index on the tree,
        // and tl = tr represents the range over the original
        // array a, then we need to initialize this leaf
        // to it's corresponding value on the array
        tree[i].value = a[tl];
        return;
    }

    int mid = tl + (tr - tl)/2;

    build(tl, mid, i<<1);
    build(mid+1, tr, i<<1^1);

    // We use the custom combine "+" operator here
    // to build the parent from the already initialized
    // children.
    tree[i] = tree[i<<1] + tree[i<<1^1];
}

