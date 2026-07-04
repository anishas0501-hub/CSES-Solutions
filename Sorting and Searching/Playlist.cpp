#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> id(n);
    for(int i = 0; i < n; i++) cin >> id[i];
    unordered_set<int> st;
    int l = 0, ans = 0;
    for(int r = 0; r < n; r++) {
        while(st.count(id[r])) {
            st.erase(id[l]);
            l++;
        }
        st.insert(id[r]);
        ans = max(ans, r - l + 1);
    }
    cout << ans; 
}