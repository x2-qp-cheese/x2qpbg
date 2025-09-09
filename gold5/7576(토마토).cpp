#include <bits/stdc++.h>
using namespace std;

int board[1001][1001]; // 토마토 상자의 상태 저장 (1: 익음, 0: 안익음, -1: 없음)
int vis[1001][1001];   // BFS 탐색 시 걸린 날짜 저장 (미방문: -1)

int dx[4] = {1, 0, -1, 0};  // 상하좌우 이동
int dy[4] = {0, 1, 0, -1};

queue<pair<int,int>> Q; // BFS 큐

int main(){
    int m, n;
    cin >> m >> n; // m == 가로 칸 수, n == 세로 칸 수
    
    // 입력 처리
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) 
                Q.push({i, j}); // 익은 토마토 위치를 큐에 삽입
            if(board[i][j] == 0) 
                vis[i][j] = -1; // 안 익은 토마토는 아직 방문 전(-1)으로 표시
        }
    }

    // BFS 시작
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 4방향 탐색
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            // 범위 밖이면 무시
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) 
                continue;
            // 이미 방문했거나 익은 토마토는 무시
            if(vis[ny][nx] >= 0) 
                continue;

            // (cur에서 하루 후 익음) → 익은 날짜 갱신
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            Q.push({ny, nx});
        }
    }

    int res = 0; // 결과: 모든 토마토가 익는 데 걸린 최대 일수
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == -1){ 
                // 아직 안 익은 토마토가 존재 → 불가능
                cout << -1;
                return 0;
            }
            res = max(res, vis[i][j]); // 가장 오래 걸린 날짜 찾기
        }
    }
    cout << res;
}
