#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coin(n);
    for(int i = 0; i < n; i++)  cin >> coin[i];
    sort(coin.begin(), coin.end());
    long long reachable = 0;
    for(int i = 0; i < n; i++){
        if(coin[i] > reachable + 1)  {
            cout << reachable + 1;
            return 0;
        }
        reachable += coin[i];
    }
    cout << reachable + 1;
    return 0;
}
