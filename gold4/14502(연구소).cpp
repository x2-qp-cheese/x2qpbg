#include <bits/stdc++.h>
using namespace std;

int board[10][10];      // 원본 연구소 지도 (0: 빈 칸, 1: 벽, 2: 바이러스)
int tmpboard[10][10];   // 벽을 세우고 바이러스가 퍼진 후의 임시 지도
int visited[10][10];    // BFS 방문 체크 배열
int dy[4] = {-1, 1, 0, 0}; // 상하좌우 이동
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> q; // BFS용 큐
int n, m, res;           // n: 세로 크기, m: 가로 크기, res: 최대 안전 영역 크기

// 바이러스 확산을 시뮬레이션하는 BFS
void bfs(){
    int cnt = 0; // 안전 영역 개수
    memset(visited, 0, sizeof(visited)); // 방문 배열 초기화
    copy(&board[0][0], &board[0][0]+100, &tmpboard[0][0]); // 원본 지도 복사

    // 모든 바이러스 위치에서 BFS 시작
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 2 && !visited[i][j]){
                q.push({i, j});
                visited[i][j] = 1;

                while(!q.empty()){
                    auto[y,x] = q.front(); q.pop();

                    // 4방향으로 확산
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        // 연구소 범위를 벗어나면 무시
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        // 벽이 있거나 이미 바이러스가 퍼진 칸은 무시
                        if(board[ny][nx] == 1 || board[ny][nx] == 2) continue;
                        if(visited[ny][nx]) continue;

                        // 바이러스 확산
                        tmpboard[ny][nx] = 2;
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    // 확산 후 안전 영역(0인 칸) 개수 세기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmpboard[i][j] == 0){
                cnt++;
            }
        }
    }

    // 최대 안전 영역 갱신
    res = max(res, cnt);
}

int main(){
    cin >> n >> m;

    // 연구소 지도 입력
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }

    // 벽 3개를 세우는 모든 조합 탐색 (3중 for문)
    for(int i = 0; i < n*m; i++){
        int y1 = i / m;
        int x1 = i % m;

        if(board[y1][x1] == 0){ // 빈 칸일 때만 벽을 세움
            board[y1][x1] = 1;
            for(int j = i + 1; j < n*m; j++){
                int y2 = j / m;
                int x2 = j % m;
                if(board[y2][x2] == 0){
                    board[y2][x2] = 1;
                    for(int k = j + 1; k < n*m; k++){
                        int y3 = k / m;
                        int x3 = k % m;
                        if(board[y3][x3] == 0){
                            board[y3][x3] = 1;

                            // 벽을 3개 세운 후 바이러스 확산 시뮬레이션
                            bfs();

                            // 원상 복구
                            board[y3][x3] = 0;
                        }
                    }
                    board[y2][x2] = 0;
                }
            }
            board[y1][x1] = 0;
        }
    }

    // 최대 안전 영역 출력
    cout << res;
}