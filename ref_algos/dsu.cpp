#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> _size;

void make_set(int v) {
    parent[v] = v;
    _size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// Union by size/rank - small to large
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (_size[a] < _size[b])
            swap(a, b);
        parent[b] = a;
        _size[a] += _size[b];
    }
}
