#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> lengths;
    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);
    while(n--){
        int p;
        cin>>p;
        auto it = lights.upper_bound(p);
        int right = *it;
        it--;
        int left = *it;
        lengths.erase(lengths.find(right - left));
        lengths.insert(p-left);
        lengths.insert(right-p);
        lights.insert(p);
        cout << *lengths.rbegin() << " ";
    }
} 