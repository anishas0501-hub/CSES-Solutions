#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> p;
    for(int i = 1; i <= n; i++) p.push_back(i);
    //start from the first person
    auto it = p.begin();

    while(!p.empty()){
    //move to the next person
    it++;

    //wrap around if we reach end
    if(it == p.end()) it = p.begin();

    //remove this person  
    cout << *it << " ";

    //erase() returns iterator to the next element
    it = p.erase(it);

    //if the erased person was the last one, continue from the beginning
    if(it == p.end()) it = p.begin();
    }
    return 0;   
} 