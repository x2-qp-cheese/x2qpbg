#include <bits/stdc++.h>
using namespace std;

int visited[500001][2];  // 각 위치에서의 방문 여부를 2차원 배열로 저장 (시간에 따라 방문 여부를 기록)
queue<pair<int, int>> q;  // BFS에서 사용할 큐 (현재 위치와 시간을 저장)

int main() {
    int n, k;
    cin >> n >> k;  // 수빈이의 위치(n)와 동생의 위치(k) 입력

    // 만약 수빈이와 동생의 위치가 같으면, 이동할 필요 없이 0을 출력
    if (n == k) {
        cout << 0;
        return 0;
    }

    int kvisited[500001];  // 동생의 위치를 방문한 시간을 저장
    memset(kvisited, -1, sizeof(kvisited));  // 초기화 (모든 값 -1로 설정)

    int time = 0;
    int accel = 1;
    kvisited[k] = 0;  // 동생의 초기 위치는 시간 0에 방문한 것으로 설정

    // 동생이 이동하는 시간 기록
    // 동생은 처음에 k에서 시작하여, 매번 1씩 이동하고, 시간이 1초씩 증가
    while (k <= 500000) {
        kvisited[k] = time;
        k += accel;  // 동생은 점점 더 빠르게 이동
        time++;
        accel++;  // 이동 속도 증가
    }

    q.push({n, 0});  // BFS 큐에 수빈이의 시작 위치와 시간을 넣기
    visited[n][0] = 1;  // 수빈이의 시작 위치 방문 처리

    int res = INT_MAX;  // 동생을 만날 수 있는 최소 시간을 기록할 변수

    // BFS 시작
    while (!q.empty()) {
        auto cur = q.front();  // 큐에서 현재 위치와 시간 꺼내기
        q.pop();
        int pos = cur.first;  // 현재 위치
        int curtime = cur.second;  // 현재 시간
        int nxttime = curtime + 1;  // 다음 시간

        // 동생이 현재 위치에 도달할 수 있는 시간보다 먼저 도달했다면
        // 또는 도달할 수 있는 시간과 동일한 시간에 도달했다면, 결과를 갱신
        if (kvisited[pos] >= 0 && (curtime % 2 == kvisited[pos] % 2) && curtime <= kvisited[pos]) {
            res = min(res, kvisited[pos]);  // 최소 시간 갱신
        }

        // 현재 위치에서 이동 가능한 3가지 방향을 큐에 추가
        if (pos + 1 <= 500000 && !visited[pos + 1][nxttime % 2]) {
            q.push({pos + 1, nxttime});  // 오른쪽으로 이동
            visited[pos + 1][nxttime % 2] = 1;  // 방문 처리
        }

        if (pos - 1 >= 0 && !visited[pos - 1][nxttime % 2]) {
            q.push({pos - 1, nxttime});  // 왼쪽으로 이동
            visited[pos - 1][nxttime % 2] = 1;  // 방문 처리
        }

        if (2 * pos <= 500000 && !visited[2 * pos][nxttime % 2]) {
            q.push({2 * pos, nxttime});  // 두 배로 이동
            visited[2 * pos][nxttime % 2] = 1;  // 방문 처리
        }
    }

    // 동생을 만날 수 없다면 -1 출력, 그렇지 않으면 최소 시간을 출력
    if (res == INT_MAX)
        cout << -1;
    else
        cout << res;
}
