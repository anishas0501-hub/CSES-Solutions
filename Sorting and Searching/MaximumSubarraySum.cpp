#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    long long curr = arr[0];
    long long best = arr[0];
    for(int i = 1;i < n; i++){
        curr = max((long long)arr[i], curr + arr[i]);
        best = max(best, curr);
    }
    cout << best;
    return 0;
}