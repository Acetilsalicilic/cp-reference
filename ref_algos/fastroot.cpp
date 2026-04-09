#include <bits/stdc++.h>
using namespace std;

long long root(long long a) {
    if (a < 0) return 0;

    long long ans = a;

    long long h = INT_MAX;
    long long l = 0;
    while (l <= h) {
        int mid = l + (h-l)/2;

        if (mid*mid <= a)
            ans = mid;

        if (mid*mid <= a) l = mid+1;
        else h = mid - 1;
    }

    return ans;
}

int main() {
    long long a;
    cin>>a;
    cout<<root(a)<<'\n';
}
