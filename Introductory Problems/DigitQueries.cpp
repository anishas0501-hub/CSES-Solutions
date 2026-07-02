#include<bits/stdc++.h> 
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        long long digits = 1;
        long long count = 9;
        long long start = 1;
        while(k > digits*count) {
            k -= digits*count;
            digits++;
            count *= 10;
            start *= 10;
        }
        long long number = start + (k-1)/digits;
            int index = (k-1) % digits;

            string s = to_string(number);
            cout << s[index] << "\n";
    }
    return 0;
}