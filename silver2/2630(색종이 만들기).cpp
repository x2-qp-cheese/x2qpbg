#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int white;
int blue;

void solve(int n, int y, int x){
    if(n == 1){
        if(board[y][x] == 0) white++;
        else blue++;
        return;
    }
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(board[y][x] != board[i][j]){
                solve(n/2, y, x);
                solve(n/2, y + n/2, x);
                solve(n/2, y, x + n/2);
                solve(n/2, y + n/2, x + n/2);
                return;
            }
        }
    }
    if(board[y][x] == 0) white++;
    else blue++;
    return;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    solve(n, 0, 0);
    cout << white << "\n";
    cout << blue << "\n";
}