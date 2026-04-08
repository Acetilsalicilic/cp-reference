#include "common.cpp"

/* iterative update */
void update(int pos, int val) {
    tree[pos+=n<<1] = val;
    for (pos>>=1; pos >=1; pos>>=1) 
        /* merge nodes operator instead of '+' */
        tree[pos] = tree[pos<<1] + tree[pos<<1^1];
}

