#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++) pos[arr[i]] = i;

    int rounds = 1;
    for(int i = 1; i < n ; i++) {
        if(pos[i] > pos[i+1]) rounds++;
    }  
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int x = arr[a];
        int y = arr[b];

        set<pair<int, int>> affected;
        affected.insert({x-1, x});
        affected.insert({x, x+1});
        affected.insert({y-1, y});
        affected.insert({y, y+1});

        //remove old contribution
        for(auto [u, v] : affected) {
            if(u >= 1 && v <= n) {
                if(pos[u] > pos[v]) rounds--;
            }
        }

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        //add new contribution
        for(auto [u, v] : affected) {
            if(u >= 1 && v <= n) {
                if(pos[u] > pos[v]) rounds++;
            }
        }
        cout << rounds << "\n"; 
    }
} 