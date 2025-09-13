#include <bits/stdc++.h>
using namespace std;

// 미로 보드와 방문 기록 저장 배열 선언
int board[1001][1001];  // 미로 상태 저장 (0: 빈 공간, 1: 벽)
int visited[1001][1001][11];  // [y][x][벽 부순 횟수]별 방문 횟수 기록

// 사방 이동 방향 설정 (상하좌우)
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

// BFS용 큐 선언: (현재 y좌표, x좌표, 벽 부순 횟수, 낮(0)/밤(1))
queue<tuple<int, int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  // 빠른 입력 처리를 위한 최적화

    // 입력 받기
    int n, m, k;  // 세로(n), 가로(m), 벽 부술 수 있는 최대 횟수(k)
    cin >> n >> m >> k;

    // 미로 입력 처리
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';  // 문자열을 정수로 변환 ('0'→0, '1'→1)
        }
    }

    // 방문 배열 초기화
    memset(visited, 0, sizeof(visited));
    q.push({0, 0, 0, 0});  // 시작점 (0,0), 벽 부순 횟수 0, 낮 시간
    visited[0][0][0] = 1;  // 시작점 방문 처리

    while (!q.empty()) {
        // 현재 상태 추출 (튜플 언패킹 사용)
        auto [y, x, wallBroken, dayNight] = q.front();
        q.pop();

        // 목적지 도착 시 결과 출력 후 종료
        if (y == n - 1 && x == m - 1) {
            cout << visited[y][x][wallBroken];
            return 0;
        }

        // 다음 시간대 계산 (낮 ↔ 밤 전환)
        int nxtdayNight = 1 - dayNight;

        // 네 방향으로 이동 시도
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            
            // 맵 범위 벗어나면 무시
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            // 이미 방문한 상태라면 건너뜀 (같은 벽 부순 횟수 & 같은 시간대에서 중복 방문 방지)
            if (visited[ny][nx][wallBroken]) continue;

            // 빈 공간 이동 처리
            if (board[ny][nx] == 0) {
                visited[ny][nx][wallBroken] = visited[y][x][wallBroken] + 1;
                q.push({ny, nx, wallBroken, nxtdayNight});
            }

            // 낮에만 벽 부술 수 있음 (벽이 있고, 부술 횟수 남은 경우)
            if (dayNight == 0 && board[ny][nx] == 1 && wallBroken < k) {
                visited[ny][nx][wallBroken + 1] = visited[y][x][wallBroken] + 1;
                q.push({ny, nx, wallBroken + 1, nxtdayNight});
            }
        }

        // 밤에는 현재 위치에 머무를 수 있음 (낮으로 넘어가기 전 상태 기록)
        if (dayNight == 1) {
            visited[y][x][wallBroken]++;
            q.push({y, x, wallBroken, nxtdayNight});
        }
    }

    // 도달 불가 시 -1 출력
    cout << -1;
}