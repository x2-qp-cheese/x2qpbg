#include <bits/stdc++.h>
using namespace std;

// 3차원 보드를 나타내는 배열
int board[101][101][101];
// 방문 여부를 나타내는 배열
int visited[101][101][101];
// 이동 방향을 나타내는 배열 (6방향)
int dy[6] = {1, -1, 0, 0, 0, 0}; // y축 방향 이동
int dx[6] = {0, 0, 1, -1, 0, 0}; // x축 방향 이동
int dz[6] = {0, 0, 0, 0, 1, -1}; // z축 방향 이동
// 큐를 사용하여 BFS를 수행
queue<tuple<int, int, int>> q;

int main() {
    int m, n, h;
    // 입력: m, n, h는 각각 x, y, z축의 크기
    cin >> m >> n >> h;

    // 3차원 보드 초기화
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                // 시작점(1)을 큐에 추가하고, 벽(0)은 방문 불가로 설정
                if (board[i][j][k] == 1) {
                    q.push({i, j, k});
                } else if (board[i][j][k] == 0) {
                    visited[i][j][k] = -1;
                }
            }
        }
    }

    // BFS 수행
    while (!q.empty()) {
        // 현재 위치를 큐에서 꺼냄
        auto [curz, cury, curx] = q.front(); q.pop();
        // 6방향 탐색
        for (int dir = 0; dir < 6; dir++) {
            int nz = curz + dz[dir]; // 새로운 z 좌표
            int ny = cury + dy[dir]; // 새로운 y 좌표
            int nx = curx + dx[dir]; // 새로운 x 좌표

            // 범위를 벗어나면 무시
            if (nz < 0 || nz >= h) continue;
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;

            // 이미 방문한 곳이면 무시
            if (visited[nz][ny][nx] >= 0) continue;

            // 큐에 추가하고 방문 처리
            q.push({nz, ny, nx});
            visited[nz][ny][nx] = visited[curz][cury][curx] + 1;
        }
    }

    // 최대 거리 계산 및 결과 출력
    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                // 벽이 있는 경우는 -1 출력 후 종료
                if (visited[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                // 최대 거리 갱신
                res = max(res, visited[i][j][k]);
            }
        }
    }
    cout << res;
}
