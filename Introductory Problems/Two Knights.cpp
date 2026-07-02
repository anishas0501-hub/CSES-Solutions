#include<bits/stdc++.h> 
using namespace std;

int main() {
    long long n;
    cin >> n;
    int i;

    for(i = 1; i <= n; i++){
        long long sq = 1LL * i * i;

        long long total = sq * (sq - 1) / 2;
        long long attack = 4LL * (i - 1) * (i - 2);

        cout << total - attack << "\n";
    }
    return 0;
} 