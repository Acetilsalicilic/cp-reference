#include "common.cpp"

/* update a position */
void update(int pos, int val, int tl=0, int tr=n-1, int i=1) {
    if (tr < tl) return;
    if (tr < pos || tl > pos) return;
    if (tl == tr) {
        if (tl != pos) return;
        tree[i] = val;
        return;
    }

    int mid = tl + (tr - tl)/2;

    update(pos, val, tl, mid, i<<1);
    update(pos, val, mid+1, tr, i<<1^1);

    // Desired operation instead of '+'
    tree[i] = tree[i<<1] + tree[i<<1^1];
}
