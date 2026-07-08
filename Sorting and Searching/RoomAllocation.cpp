#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int start, end, id;
};

int main() {

    int n;
    cin >> n;

    vector<Customer> customers(n);

    for (int i = 0; i < n; i++) {
        cin >> customers[i].start >> customers[i].end;
        customers[i].id = i;
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end(),
         [](Customer a, Customer b) {
             return a.start < b.start;
         });

    // Min-heap:
    // (departure_time, room_number)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> answer(n);

    int rooms = 0;

    for (auto customer : customers) {
        // No room available yet
        if (pq.empty()) {
            rooms++;
            answer[customer.id] = rooms;
            pq.push({customer.end, rooms});
        }

        // Earliest room is free BEFORE current arrival
        else if (pq.top().first < customer.start) {
            auto room = pq.top();
            pq.pop();
            answer[customer.id] = room.second;
            pq.push({customer.end, room.second});
        }

        // Need a new room
        else {
            rooms++;
            answer[customer.id] = rooms;
            pq.push({customer.end, rooms});
        }
    }
    cout << rooms << "\n";
    for (int x : answer)
        cout << x << " ";
}