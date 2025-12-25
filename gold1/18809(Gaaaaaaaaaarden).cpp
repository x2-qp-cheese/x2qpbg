#include <bits/stdc++.h>
using namespace std;

int n, m, g, r;
int garden[51][51];
int dist[51][51];  // 각 칸에 배양액이 도달한 시간
int state[51][51]; // 각 칸의 상태 (0:빈칸, 1:초록, 2:빨강, 3:꽃)
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<pair<int, int>> avail; // 배양액을 뿌릴 수 있는 땅(2)의 좌표들
int selected[11]; // 각 avail 땅의 선택 상태 (0:미선택, 1:초록, 2:빨강)
int result = 0;

int solve_bfs() {
    int flower_cnt = 0;
    queue<pair<int, int>> q;
    
    // 매 시뮬레이션마다 시간과 상태 배열을 초기화
    memset(dist, -1, sizeof(dist));
    memset(state, 0, sizeof(state));

    // 선택된 배양액 위치를 큐에 넣고 초기 상태 설정
    for (int i = 0; i < avail.size(); i++) {
        if (selected[i] == 1) { // 초록 배양액
            state[avail[i].first][avail[i].second] = 1;
            dist[avail[i].first][avail[i].second] = 0;
            q.push(avail[i]);
        } else if (selected[i] == 2) { // 빨간 배양액
            state[avail[i].first][avail[i].second] = 2;
            dist[avail[i].first][avail[i].second] = 0;
            q.push(avail[i]);
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        
        // 현재 칸이 확산되기 전에 이미 꽃이 되었다면 더 이상 퍼지지 않음
        if (state[y][x] == 3) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위를 벗어나거나 호수(0)인 경우 무시
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (garden[ny][nx] == 0) continue;

            // 1. 아직 아무것도 도달하지 않은 빈 땅인 경우
            if (state[ny][nx] == 0) {
                state[ny][nx] = state[y][x]; // 현재 배양액 색깔 전파
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            } 
            // 2. 다른 색깔의 배양액과 동시에 만나는 경우 (꽃 판정)
            else if (state[ny][nx] == 1) { // 이미 초록색이 퍼진 곳에
                if (state[y][x] == 2 && dist[ny][nx] == dist[y][x] + 1) {
                    state[ny][nx] = 3; // 꽃으로 변경
                    flower_cnt++;
                }
            } else if (state[ny][nx] == 2) { // 이미 빨간색이 퍼진 곳에
                if (state[y][x] == 1 && dist[ny][nx] == dist[y][x] + 1) {
                    state[ny][nx] = 3; // 꽃으로 변경
                    flower_cnt++;
                }
            }
        }
    }
    return flower_cnt;
}

// idx: 현재 결정할 땅의 인덱스, gcnt: 선택된 초록 개수, rcnt: 선택된 빨강 개수
void select_subset(int idx, int gcnt, int rcnt) {
    // 모든 배양 가능한 땅에 대해 결정을 마친 경우
    if (idx == avail.size()) {
        // 정확히 g개와 r개를 사용한 조합만 BFS 시뮬레이션 실행
        if (gcnt == g && rcnt == r) {
            result = max(result, solve_bfs());
        }
        return;
    }

    // 1. 해당 자리에 초록색 배양액을 뿌리는 경우
    if (gcnt < g) {
        selected[idx] = 1;
        select_subset(idx + 1, gcnt + 1, rcnt);
    }

    // 2. 해당 자리에 빨간색 배양액을 뿌리는 경우
    if (rcnt < r) {
        selected[idx] = 2;
        select_subset(idx + 1, gcnt, rcnt + 1);
    }

    // 3. 해당 자리에 아무것도 뿌리지 않는 경우
    selected[idx] = 0;
    select_subset(idx + 1, gcnt, rcnt);
}

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
            // 배양액을 뿌릴 수 있는 땅(2)의 위치 정보만 따로 저장
            if (garden[i][j] == 2) avail.push_back({i, j});
        }
    }
    
    // 부분 집합 탐색 시작
    select_subset(0, 0, 0);
    
    cout << result;
    return 0;
}
