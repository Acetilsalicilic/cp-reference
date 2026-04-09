#include "common.cpp"

/* update lazy prop */
void sum_query(
        int l, int r, int k, 
        int tl=0, int tr=n-1, int i=1
        ) {
    if (tr < tl) return;
    if (tr < l || tl > r) return;

    if (tl >= l && tr <= r) {
        tree[i].lazy_sum_flag = true;
        tree[i].lazy_sum_value += k;
        tree[i].value += (r - l + 1)*k;

        return;
    }
    
    int mid = tl + (tr - tl)/2;

    push(tree[i], 
            tree[i<<1], 
            tl, mid,
            tree[i<<1^1],
            mid+1, tr);

    sum_query(l, r, k, tl, mid, i<<1);
    sum_query(l, r, k, mid+1, tr, i<<1^1);
    
    tree[i] = tree[i<<1] + tree[i<<1^1];
}

