#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, 0, 1, -1};   // 상하좌우 이동을 위한 y 변화량
int dx[4] = {1, -1, 0, 0};   // 상하좌우 이동을 위한 x 변화량

char board[51][51];
int visited[51][51][64];      // visited[y][x][mask]: mask 상태로 (y,x)에 방문했는지 체크
                              // mask는 보유 중인 열쇠 상태(0~63)를 나타내는 비트마스크
queue<tuple<int,int,int,int>> q; // y, x, key_mask, dist

int main() {
    int n, m;
    cin >> n >> m;   // 미로의 세로 n, 가로 m 입력

    for(int i = 0; i < n; i++){
        string s; 
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j];

            // 시작 위치(‘0’)를 큐에 넣고 visited 표시
            if(board[i][j] == '0'){
                q.push({i, j, 0, 0});   // 열쇠 없음(mask=0), 거리 0
                visited[i][j][0] = 1;
            }
        }
    }

    // BFS 시작
    while(!q.empty()){
        auto [y, x, mask, dist] = q.front(); 
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 범위 밖이면 패스
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            // 벽이면 패스
            if(board[ny][nx] == '#') continue;

            // 출구 ‘1’ 발견 → dist+1 출력 후 종료
            if(board[ny][nx] == '1'){
                cout << dist + 1;
                return 0;
            }

            // 빈 칸 또는 시작점은 열쇠 상태 변화 없이 그냥 이동
            if(board[ny][nx] == '.' || board[ny][nx] == '0'){
                if(!visited[ny][nx][mask]){
                    visited[ny][nx][mask] = 1;
                    q.push({ny, nx, mask, dist+1});
                }
            }

            // 문(A~F): 해당 키(mask) 보유 시에만 통과 가능
            if(board[ny][nx] >= 'A' && board[ny][nx] <= 'F'){
                int need = board[ny][nx] - 'A'; // 필요한 열쇠 인덱스
                if(mask & (1 << need)){         // 해당 키가 있을 때
                    if(!visited[ny][nx][mask]){
                        visited[ny][nx][mask] = 1;
                        q.push({ny, nx, mask, dist+1});
                    }
                }
            }

            // 열쇠(a~f): 새로운 열쇠를 획득하여 mask를 업데이트
            if(board[ny][nx] >= 'a' && board[ny][nx] <= 'f'){
                int new_mask = mask | (1 << (board[ny][nx] - 'a')); // 열쇠 추가
                if(!visited[ny][nx][new_mask]){
                    visited[ny][nx][new_mask] = 1;
                    q.push({ny, nx, new_mask, dist+1});
                }
            }
        }
    }

    // 출구를 못 찾으면 -1 출력
    cout << "-1";
    return 0;
}
