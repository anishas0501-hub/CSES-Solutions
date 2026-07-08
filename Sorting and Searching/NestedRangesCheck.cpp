#include <bits/stdc++.h>
using namespace std;

struct Range{
    int l, r, id;
};

int main() {
    int n;
    cin >> n;
    vector<Range> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), [](Range &x, Range &y){
        if(x.l == y.l) return x.r > y.r;
        return x.l < y.l;
    });

    vector<int> contains(n), contained(n);

    int maxRight = 0;
    for(auto &cur : a){
        if(cur.r <= maxRight) contained[cur.id] = 1;
        maxRight = max(maxRight, cur.r);
    }
    int minRight = INT_MAX;
    for(int i = n-1; i >= 0; i--) {
        if(a[i].r >= minRight) contains[a[i].id] = 1;

        minRight = min(minRight, a[i].r);
    }
    for(int x : contains) cout << x << " ";
    cout << "\n";
    for(int x : contained) cout << x << " ";
} 