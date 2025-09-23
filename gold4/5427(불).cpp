#include <bits/stdc++.h>
using namespace std;

// 상하좌우 방향 벡터
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

// 맵과 방문 시간 저장 배열
char board[1001][1001];               // 맵 정보: '.', '#', '@', '*'
int visited_fire[1001][1001];         // 불이 도착한 시간
int visited_human[1001][1001];        // 사람이 도착한 시간

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin >> testcase;

    while(testcase--){
        int w, h;
        cin >> w >> h;

        queue<pair<int, int>> q_fire;     // 불 위치 저장 큐
        queue<pair<int, int>> q_human;    // 사람 위치 저장 큐

        // 이전 테스트 케이스 정보 초기화
        memset(visited_fire, 0, sizeof(visited_fire));
        memset(visited_human, 0, sizeof(visited_human));

        // 맵 입력 및 초기 불/사람 위치 저장
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == '*'){
                    q_fire.push({i, j});
                    visited_fire[i][j] = 1;  // 불의 시작 시간: 1
                } else if(board[i][j] == '@'){
                    q_human.push({i, j});
                    visited_human[i][j] = 1;  // 사람의 시작 시간: 1
                }
            }
        }

        // 🔥 1. 불 BFS 전파
        while(!q_fire.empty()){
            auto [y, x] = q_fire.front(); q_fire.pop();

            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                // 범위 밖이거나 벽이면 건너뜀
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(board[ny][nx] == '#') continue;
                if(visited_fire[ny][nx]) continue;  // 이미 불이 번졌으면 skip

                visited_fire[ny][nx] = visited_fire[y][x] + 1;  // 불 시간 갱신
                q_fire.push({ny, nx});
            }
        }

        // 🧍 2. 사람 BFS
        int answer = -1;  // 탈출 못한 경우 -1
        while(!q_human.empty()){
            auto [y, x] = q_human.front(); q_human.pop();

            // 탈출 조건: 가장자리에 도달
            if(y == 0 || y == h-1 || x == 0 || x == w-1){
                answer = visited_human[y][x];  // 탈출 시간 저장
                break;  // 더 이상 탐색할 필요 없음
            }

            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                // 범위를 벗어나거나 벽이거나 이미 방문했으면 건너뜀
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(board[ny][nx] == '#') continue;
                if(visited_human[ny][nx]) continue;

                int next_time = visited_human[y][x] + 1;

                // 사람이 이동하려는 칸에 불이 오지 않았거나,
                // 사람이 불보다 먼저 도착할 수 있는 경우에만 이동
                if(visited_fire[ny][nx] == 0 || next_time < visited_fire[ny][nx]){
                    visited_human[ny][nx] = next_time;
                    q_human.push({ny, nx});
                }
            }
        }

        // 결과 출력
        if(answer == -1) cout << "IMPOSSIBLE\n";  // 탈출 실패
        else cout << answer << '\n';              // 탈출 성공 시간 출력
    }

    return 0;
}
