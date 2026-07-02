#include<bits/stdc++.h> 
using namespace std;

vector<string> ans;

void solve(string &s, string &curr, vector<bool> &used) {
    int n = s.length();

    if(curr.length() == n) {
        ans.push_back(curr);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;

        if(i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

        //choose
        used[i] = true;
        curr.push_back(s[i]);

        solve(s, curr, used);

        //undo
        curr.pop_back();
        used[i] = false;
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string curr;
    vector<bool> used(s.length(), false);
    solve(s, curr, used);
    
    cout << ans.size() << "\n";
    for(string x : ans) cout << x << "\n";

    return 0;
}