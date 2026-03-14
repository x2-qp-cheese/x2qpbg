#include <bits/stdc++.h>
using namespace std;

int board[65][65];

void solve(int n, int y, int x){
    if(n == 1){
        if(board[y][x] == 0) cout << 0;
        else cout << 1;
        return;
    }

    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(board[i][j] != board[y][x]){
                cout << "(";
                solve(n/2, y, x);
                solve(n/2, y, x + n/2);
                solve(n/2, y + n/2, x);
                solve(n/2, y + n/2, x + n/2);
                cout << ")";
                return;
            }
        }
    }
    if(board[y][x] == 0) cout << 0;
    else cout << 1;
    return;
}

int main(){
    int n;  cin >> n;

    for(int i = 0; i < n; i++) {
        string row; cin >> row; 
        for(int j = 0; j < n; j++) {
            board[i][j] = row[j] - '0'; 
        }
    }   

    solve(n, 0, 0);

}