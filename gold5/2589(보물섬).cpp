#include <bits/stdc++.h>
using namespace std;

char board[50][50];             // 지도 정보 ('L' = 육지, 'W' = 물)
int visited[50][50];            // BFS 거리 겸 방문 체크 배열

int dy[4] = {-1, 1, 0, 0};      // 상, 하, 좌, 우 이동
int dx[4] = {0, 0, -1, 1};

int n, m;                       // 세로(n), 가로(m)
int result;                     // 가장 긴 최단 거리(보물 사이의 최대 거리)

queue<pair<int, int>> q;        // BFS 탐색을 위한 큐

// 입력 처리 함수
// 지도 크기와 각 행의 지형 정보를 입력받음
void userInput(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
}

// 모든 육지('L')를 시작점으로 BFS 수행
// 각 BFS에서 가장 먼 육지까지의 거리를 계산
void bfs(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            // 새로운 시작점마다 방문 배열 초기화
            memset(visited, 0, sizeof(visited));

            // 육지이면서 아직 방문하지 않은 경우 BFS 시작
            if(board[i][j] == 'L' && !visited[i][j]){
                visited[i][j] = 1;      // 시작 지점 거리 = 1
                q.push({i, j});

                while(!q.empty()){
                    auto[y, x] = q.front(); q.pop();

                    // 현재 BFS에서의 최대 거리 갱신
                    result = max(result, visited[y][x]);

                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        // 범위를 벗어나면 무시
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        // 물이거나 이미 방문한 칸은 이동 불가
                        if(board[ny][nx] == 'W' || visited[ny][nx]) continue;

                        // 이전 칸 거리 + 1로 거리 갱신
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main(){
    userInput();        // 입력
    bfs();              // 모든 육지에서 BFS 수행
    cout << result - 1; // 시작 거리를 1로 두었으므로 1을 빼서 출력
}
