#include <bits/stdc++.h>
using namespace std;
int n;

char board[2200][2200];

void solve(int len, int y, int x){
    if(len == 1){
        board[y][x] = '*';
        return;
    }
    solve(len/3, y, x);
    solve(len/3, y, x + len/3);
    solve(len/3, y, x + 2*len/3);

    solve(len/3, y + len/3, x);
    solve(len/3, y + len/3, x + 2*len/3);

    solve(len/3, y + 2*len/3, x);
    solve(len/3, y + 2*len/3, x + len/3);
    solve(len/3, y + 2*len/3, x + 2*len/3);
    return;
}

int main(){
    cin >> n;
    solve(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '*')
                cout << board[i][j];
            else
                cout << " ";
        }
        cout << "\n";
    }
}