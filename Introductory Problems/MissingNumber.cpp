#include<bits/stdc++.h> 
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long expsum = n * (n + 1) / 2;
    long long actsum = 0;
    for(int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        actsum += x;
    }
    cout << expsum - actsum;
    return 0;
} 