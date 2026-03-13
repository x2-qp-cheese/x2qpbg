#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cntminus;
int cntzero;
int cntplus;

void solve(int x, int y, int len){
    if(len == 0) return;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(board[y][x] != board[y+i][x+j]){
                int nlen = len/3;
                solve(x, y, nlen);
                solve(x, y + nlen, nlen);
                solve(x, y + 2*nlen, nlen);

                solve(x + nlen, y, nlen);
                solve(x + nlen, y + nlen, nlen);   
                solve(x + nlen, y + 2*nlen, nlen);
                
                solve(x + 2*nlen, y, nlen);
                solve(x + 2*nlen, y + nlen, nlen);
                solve(x + 2*nlen, y + 2*nlen, nlen);
                return;
            }
        }
    }
    if(board[y][x] == 0) cntzero++;
    if(board[y][x] == 1) cntplus++;
    if(board[y][x] == -1) cntminus++;
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    solve(0, 0, n);

    cout << cntminus << "\n";
    cout << cntzero << "\n";
    cout << cntplus << "\n";
}