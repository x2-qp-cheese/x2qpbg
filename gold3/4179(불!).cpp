#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];                // 미로 지도 저장
queue<pair<int, int>> qJ;              // 지훈이(J)의 BFS 큐
queue<pair<int, int>> qF;              // 불(F)의 BFS 큐
int distJ[1001][1001];                 // 지훈이가 각 칸에 도달하는 최소 시간
int distF[1001][1001];                 // 불이 각 칸에 도달하는 최소 시간
int dy[4] = {1, 0, -1, 0};             // 방향 벡터 (상하좌우 이동)
int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;                          // r: 행(세로), c: 열(가로)
    cin >> r >> c;
    
    // 입력 처리
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            
            // 빈 칸인 경우, 아직 도달하지 않았음을 표시 (-1)
            if(board[i][j] == '.'){
                distF[i][j] = -1;
                distJ[i][j] = -1;
            }
            
            // 지훈이의 시작 위치
            if(board[i][j] == 'J'){
                // 시작 위치가 이미 탈출구(가장자리)라면 바로 탈출
                if(i == 0 || j == 0 || i == r-1 || j == c-1){
                    cout << "1";
                    return 0;
                }
                qJ.push({i, j});
                // distJ[i][j] = 0;   ← 여기 초기화 넣어주는 게 더 안전
            }
            
            // 불의 시작 위치
            if(board[i][j] == 'F'){
                qF.push({i, j});
                // distF[i][j] = 0;   ← 여기 초기화 넣어주는 게 더 안전
            }
        }
    }
    
    // 🔥 불의 BFS (모든 불이 퍼지는 시간을 먼저 계산)
    while(!qF.empty()){
        pair<int, int> cur = qF.front();
        qF.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            // 범위 벗어나면 무시
            if(ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            // 이미 불이 방문한 칸이면 무시
            if(distF[ny][nx] >= 0)
                continue;
            
            // 불 도착 시간 = 현재 칸 시간 + 1
            distF[ny][nx] = distF[cur.first][cur.second] + 1;
            qF.push({ny, nx});
        }
    }
    
    int ans = INT_MAX;                 // 최소 탈출 시간
    
    // 🧑 지훈이 BFS
    while(!qJ.empty()){
        pair<int, int> cur = qJ.front();
        qJ.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            // 범위 벗어나면 무시
            if(ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            // 이미 방문한 곳이면 무시
            if(distJ[ny][nx] >= 0)
                continue;
            
            // (불이 아직 안 옴) 또는 (불보다 먼저 도착 가능할 때만 이동)
            if(distF[ny][nx] == -1 || distF[ny][nx] > distJ[cur.first][cur.second] + 1){
                distJ[ny][nx] = distJ[cur.first][cur.second] + 1;
                qJ.push({ny, nx});
                
                // 가장자리에 도달 → 탈출 성공
                if(ny == 0 || nx == 0 || ny == r-1 || nx == c-1)
                    ans = min(ans, distJ[ny][nx]);
            }
        }
    }
    
    // 결과 출력
    if(ans == INT_MAX)
        cout << "IMPOSSIBLE";          // 탈출 불가
    else
        cout << ans+1;                 // 시작칸 포함해서 시간 출력
}