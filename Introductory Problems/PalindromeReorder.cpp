#include<bits/stdc++.h> 
using namespace std;

int main() {
    string s;
    cin >> s;
    //counts occurrences of each uppercase letter
    vector<int> freq(26, 0);
    for(char c : s) freq[c - 'A']++;

    //coutns odd frequencies
    int oddCount = 0;
    
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2) {
            oddCount++;
        }
    }

    if(oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    } 

    string left = "", middle = "";
    //half of each character goes to the left side
    //the odd frequency character becomes the middle
    for(int i = 0; i < 26; i++) {
        left += string(freq[i] / 2, 'A' + i);
        if(freq[i] % 2) middle = string(1, 'A' + i);
    }

    //produces a valid palindrome
    string right = left;
    reverse(right.begin(), right.end());
    cout << left + middle + right;
    return 0;

} 