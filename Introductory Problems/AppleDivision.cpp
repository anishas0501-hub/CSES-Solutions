#include<bits/stdc++.h> 
using namespace std;

long long ans = 1e18;
int n;
vector<long long> wt;

void solve(int index, long long sumA, long long sumB) {
    if(index == n) {
        ans = min(ans, abs(sumA - sumB));
        return;
    }

    //put current apple in grp A
    solve(index + 1, sumA + wt[index], sumB);

    //put current apple in grp B
    solve(index + 1, sumA, sumB + wt[index]);
        
}

int main() {
    cin >> n;
    wt.resize(n);
    for(int i = 0; i < n; i++) cin >> wt[i];

    solve(0, 0, 0);
    cout << ans << endl;

    return 0;

} 