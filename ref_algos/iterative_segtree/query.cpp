#include "common.cpp"

/* l and r are zero indexed */
int query(int l, int r) {
    int ans = 1; /* identity element */
    for (l += n<<1, r += (n<<1) + 1; l < r; l>>=1, r>>=1) {
        /* merge nodes operator instead of '+=' */
        if (l & 1)
            ans += tree[l++];
        if (r & 1)
            ans += tree[--r];
    }
    return ans;
}
