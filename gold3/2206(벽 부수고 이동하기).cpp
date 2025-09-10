#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[1001][1001];
int visited[1001][1001][2];
queue<tuple<int, int, int>> q;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j]-'0';
            visited[i][j][0] = visited[i][j][1] = -1;
        }
    }
    visited[0][0][0] = 1;
    q.push({0, 0, 0});
    while(!q.empty()){
        auto[y, x, broken] = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n) continue;
            if(nx < 0 || nx >= m) continue;
            if(visited[ny][nx][broken] != -1) continue;
            if(board[ny][nx] == 0){
                q.push({ny, nx, broken});
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
            }
            else if(board[ny][nx] == 1 && broken == 0){
                q.push({ny, nx, 1});
                visited[ny][nx][1] = visited[y][x][0] + 1;
            }
        }
    }
    int ans1 = visited[n-1][m-1][0];
    int ans2 = visited[n-1][m-1][1];

    if(ans1 == -1 && ans2 == -1)
        cout << -1;
    else if(ans1 == -1)
        cout << ans2;
    else if(ans2 == -1)
        cout << ans1;
    else{
        cout << min(ans1, ans2);
    }
}