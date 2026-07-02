#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    int arr, dep;
    while(n--) {
        cin >> arr >> dep;
        events.push_back({arr, 1});
        events.push_back({dep, -1});
    }
    sort(events.begin(), events.end());
    int current = 0;
    int ans = 0;
    for(auto event : events){
        current = current + event.second;
        ans = max(ans, current);
    }
    cout << ans << "\n";
    return 0;
}