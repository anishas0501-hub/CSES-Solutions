#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    //multiset : sorted automatically, duplicates allowed, erase on eossurence efficiently
    multiset<int> tickets;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for(int i = 0; i < m; i++) {
        int budget;
        cin >> budget;

        //find first ticket strictly greate than budget
        auto it = tickets.upper_bound(budget);

        //if upper_bound returns begin(),
        //then even the cheapest ticket is too expensive
        if(it == tickets.begin())   cout << -1 << "\n";

        else{
            //move one step left
            //now we get the largest ticket <= budget
            --it;

            //print the ticket sold
            cout << *it << "\n";

            //remove exactly this ticket
            tickets.erase(it);
        }
    }
    
    return 0;
} 