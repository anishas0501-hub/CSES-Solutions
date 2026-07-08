#include <bits/stdc++.h>
using namespace std;

struct Range {
    int l, r, id;
};

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

int main() {

    int n;
    cin >> n;

    vector<Range> a(n);

    vector<int> rights;

    // Read intervals
    for (int i = 0; i < n; i++) {

        cin >> a[i].l >> a[i].r;

        a[i].id = i;

        rights.push_back(a[i].r);
    }

   
    // Coordinate Compression
    sort(rights.begin(), rights.end());

    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    // Sort intervals
    sort(a.begin(), a.end(), [](Range A, Range B) {

        if (A.l == B.l)
            return A.r > B.r;

        return A.l < B.l;
    });

    vector<int> contains(n);

    vector<int> contained(n);

    Fenwick bit(rights.size());

    
    // Find contained[]
    int processed = 0;

    for (int i = 0; i < n; i++) {

        // compressed index of current right endpoint
        int idx =
            lower_bound(rights.begin(), rights.end(), a[i].r)
            - rights.begin() + 1;

        // query(idx-1)
        // = number of previous intervals
        // having right endpoint < current

        // processed - that
        // = number having right >= current

        contained[a[i].id] =
            processed - bit.query(idx - 1);

        // insert current right endpoint

        bit.update(idx, 1);

        processed++;
    }

    // Clear Fenwick

    bit = Fenwick(rights.size());

    
    // Find contains[]

    for (int i = n - 1; i >= 0; i--) {

        int idx =
            lower_bound(rights.begin(), rights.end(), a[i].r)
            - rights.begin() + 1;

        // query(idx)
        // = number of later intervals
        // whose right endpoint <= current

        contains[a[i].id] = bit.query(idx);

        bit.update(idx, 1);
    }

    // Print answers
    for (int x : contains)
        cout << x << " ";

    cout << "\n";

    for (int x : contained)
        cout << x << " ";
} 