#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = unique(a.begin(), a.end()) - a.begin();
    cout << ans << "\n";
    return 0;
}