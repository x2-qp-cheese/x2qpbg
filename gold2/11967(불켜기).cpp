#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
queue<pair<int,int>> q;

int main(){
    int n, m; // n은 board 크기, m은 스위치 갯수
    int cnt = 1; //0, 0불은 켜져있음


    cin >> n >> m;
    q.push({0, 0});

    //vector을 돌면서 
}