#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    map<int, int>freq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x; freq[x]++;
    }
    long long ans = 1;
    for(auto &it : freq) 
        ans = (ans*(it.second + 1LL)) % MOD;

    ans = (ans-1+MOD)%MOD;
    cout << ans;
} 