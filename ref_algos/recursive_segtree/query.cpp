#include "common.cpp"

/* query tha tree */
int query(int l, int r, int tl=0, int tr=n-1, int i=1) {
    if (tr < l || tl > r)
        return 0; // Identity element insead of '0'
    if (tl >= l && tr <= r)
        // If curent node is in range, then return it's value
        return tree[i]; 

    int mid = tl + (tr-tl)/2;

    // Return the combination of the two halves. This is why 
    // an identity element is nice: if some half is not valid, 
    // then it won't affect the correct result.
    //
    // desired operation instead of '+'
    return query(l, r, tl, mid, i<<1) 
        + query(l, r, mid+1, tr, i<<1^1);
}
