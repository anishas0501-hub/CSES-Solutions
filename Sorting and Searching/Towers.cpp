#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> size(n);
    for(int i = 0; i < n; i++) cin >> size[i];
    multiset<int> tops; //stores the top cube of every tower
    for(int i = 0; i < n; i++) {
        int x = size[i];
        //find the first tower whose top is STRICTLY GREATER than x
        auto it = tops.upper_bound(x);
        if(it == tops.end()) {
            //no tower can accommodate tis cube
            //so start a new tower
            tops.insert(x);
        }
        else{
            //we found the best tower, remove its old top
            tops.erase(it);
            //and make x the new top
            tops.insert(x);
        }
    }
    cout << tops.size();
    return 0;
} 