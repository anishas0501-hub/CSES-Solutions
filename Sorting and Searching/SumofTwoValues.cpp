#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        a.push_back({val, i+1});    //i+1 -> 1 based indexing
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = n - 1;
    while(l < r) {
      long long sum = a[l].first + a[r].first;
      if(sum == x) {
        cout << a[l].second << " " << a[r].second;
        return 0;
      }  
      else if(sum < x) l++;
      else r--;
    }
    cout << "IMPOSSIBLE";
    return 0;
} 