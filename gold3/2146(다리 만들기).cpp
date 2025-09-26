#include <bits/stdc++.h>
using namespace std;

int board[101][101];        // 지도 (0 = 바다, 1 이상 = 나라 번호)
int dy[4] = {1, -1, 0, 0};  // 상하좌우 이동
int dx[4] = {0, 0, 1, -1};
int visited[101][101];      // 방문 체크 배열
queue<pair<int, int>> q;    // BFS용 큐

int main(){
    int n;
    cin >> n;
    int num = 1; // 나라 번호 (1번부터 시작)

    // 지도 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    // 1단계: 나라 번호 붙이기 (BFS로 섬 구분)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] && !visited[i][j]){ // 땅이면서 아직 방문 X
                q.push({i, j});
                board[i][j] = num;     // 현재 땅을 num번 나라로 설정
                visited[i][j] = 1;
                while(!q.empty()){
                    auto[y, x] = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        // 범위 밖이면 무시
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        // 이미 방문했거나 바다면 무시
                        if(visited[ny][nx] || board[ny][nx] == 0) continue;
                        q.push({ny, nx});
                        board[ny][nx] = num;  // 같은 나라 번호로 칠하기
                        visited[ny][nx] = 1;
                    }
                }
                num++; // 다음 나라 번호
            }
        }
    }
    
    int res = INT_MAX; // 최단 다리 길이 결과

    // 2단계: 각 나라별로 BFS 돌려서 최단 다리 길이 찾기
    for(int numid = 1; numid < num; numid++){ // 나라 번호는 1 ~ num-1까지
        memset(visited, -1, sizeof(visited)); // 방문 배열 초기화 (-1 = 방문 X)
        queue<pair<int,int>> q;

        // 현재 나라의 모든 '경계 좌표(바다와 맞닿은 육지)'를 큐에 넣기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == numid){
                    for(int dir = 0; dir < 4; dir++){
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(board[ny][nx] == 0){ // 바다와 맞닿아 있으면 경계
                            q.push({i, j});
                            visited[i][j] = 0; // 다리 길이 0부터 시작
                            break; // 한 칸이 여러 번 들어가는 것 방지
                        }
                    }
                }
            }
        }

        // BFS 시작 (다리를 넓혀가며 다른 나라를 만날 때까지 탐색)
        while(!q.empty()){
            auto [y, x] = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                // 다른 나라를 만났을 경우 -> 다리 길이 갱신
                if(board[ny][nx] > 0 && board[ny][nx] != numid){
                    res = min(res, visited[y][x]);
                }
                // 바다이고 아직 방문하지 않았다면 다리 확장
                if(board[ny][nx] == 0 && visited[ny][nx] == -1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }

    // 최단 다리 길이 출력
    cout << res;
}
