#include<bits/stdc++.h> 
using namespace std;

int main() {

    string s;
    cin >> s;
    long long n = s.length();
    int curcnt = 1, maxcnt = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) curcnt +=1;
        else curcnt = 1;

        maxcnt = max(maxcnt, curcnt);
        
    }
    cout << maxcnt;
    return 0;
} 