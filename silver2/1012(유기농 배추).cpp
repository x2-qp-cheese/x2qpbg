#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visited[51][51];
queue<pair<int, int>> q;

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
        int m, n; cin >> m >> n;
        int k; cin >> k;
        int result = 0;
        for(int i = 0; i < k; i++){
            int x, y; cin >> x >> y;
            board[x][y] = 1;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] && !visited[i][j]){
                    q.push({i, j});
                    visited[i][j] = true;
                    result++;
                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if(nx >= m || nx < 0 || ny >= n || ny < 0) continue;
                            if(!board[nx][ny] || visited[nx][ny]) continue;
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }

            }
        }
                        cout << result << endl;
    }
}