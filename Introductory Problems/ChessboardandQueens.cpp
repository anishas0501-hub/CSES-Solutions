#include<bits/stdc++.h> 
using namespace std;

long long ans = 0;
bool col[8];
bool diag1[15]; //initially all are false
bool diag2[15];

void solve(int row, vector<string>& board) {
    if(row == 8){
        ans++;
        return;
    }

    for(int c = 0; c < 8; c++){
        if(board[row][c] == '*') continue;   
    

        if(col[c])  continue;

        if(diag1[row - c + 7]) continue;

        if(diag2[row + c]) continue;

        col[c] = true;
        diag1[row - c + 7] = true;
        diag2[row + c] = true;

        solve(row+1, board);

        col[c] = false;
        diag1[row - c + 7] = false;
        diag2[row + c] = false;
    }
}

int main() {
    vector<string> board(8);
    for(int i = 0; i < 8; i++) 
        cin >> board[i];

    solve(0, board);
    cout << ans << "\n";
}