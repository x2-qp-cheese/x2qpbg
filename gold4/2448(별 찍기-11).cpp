#include <bits/stdc++.h>
using namespace std;
int n;
char board[3100][6200];


void solve(int len, int y, int x){
    if(len == 3){
        board[y][x+2] = '*';
        board[y+1][x+1] = '*';
        board[y+1][x+3] = '*';
        for(int i = 0; i < 5; i++){
            board[y+2][x + i] = '*';
        }
        return;
    }
    int half = len/2;

    solve(half, y, x + half);
    solve(half, y + half, x);
    solve(half, y + half, x + len);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++){
            board[i][j] = ' ';
        }
    }
    solve(n, 0, 0);
    for(int i = 0; i <n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
                cout << board[i][j];
        }
        cout << "\n";
    }
}