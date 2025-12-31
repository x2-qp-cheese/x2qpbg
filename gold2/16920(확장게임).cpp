#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define MAXUSER 10

int n, m, p;
int board[MAX][MAX];
int castle_speed[MAXUSER]; // 각 플레이어가 한 턴에 확장할 수 있는 거리 (S_i)
int result[MAXUSER];       // 각 플레이어별 최종 영토 크기
queue<pair<int, int>> q[MAXUSER]; // 플레이어별 확장 경계선(Frontier)을 담는 큐

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void userInput() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> m >> p;
    
    // 1번부터 P번 플레이어의 이동 속도(S) 입력
    for (int i = 1; i <= p; i++) cin >> castle_speed[i];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') board[i][j] = 0;    // 빈 공간
            else if (s[j] == '#') board[i][j] = -1; // 벽
            else {
                int user = s[j] - '0';
                board[i][j] = user;
                q[user].push({i, j}); // 초기 성 위치를 해당 유저의 큐에 저장
                result[user]++;       // 초기 성 개수 카운트
            }
        }
    }
}

void solve() {
    // 게임은 더 이상 아무도 영토를 확장할 수 없을 때까지 반복
    while (true) {
        bool moved = false; // 이번 라운드에 확장이 일어났는지 체크

        // 1번 플레이어부터 순서대로 턴 진행
        for (int i = 1; i <= p; i++) {
            
            // 각 플레이어는 자신의 속도(castle_speed)만큼 '단계별'로 확장
            for (int step = 0; step < castle_speed[i]; step++) {
                int size = q[i].size(); // 현재 확장이 가능한 지점들의 개수 (현재 레벨)
                if (size == 0) break;   // 더 이상 확장할 곳이 없으면 이번 턴 종료

                // 현재 큐에 있는 모든 지점에서 상하좌우 1칸씩 확장 시도
                while (size--) {
                    auto [y, x] = q[i].front();
                    q[i].pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        // 격자 범위 밖이거나 이미 주인이 있는 경우(벽 포함) 무시
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        
                        // 빈 공간(0)인 경우에만 내 땅으로 만들 수 있음
                        if (board[ny][nx] == 0) {
                            board[ny][nx] = i;      // 땅 점령
                            result[i]++;            // 영토 수 증가
                            q[i].push({ny, nx});    // 다음 확장을 위해 큐에 삽입
                            moved = true;           // 확장이 일어났음을 기록
                        }
                    }
                }
            }
        }
        
        // 모든 플레이어가 한 바퀴 돌았는데 아무도 확장하지 못했다면 종료
        if (!moved) break;
    }

    // 결과 출력
    for (int i = 1; i <= p; i++) cout << result[i] << " ";
}

int main() {
    userInput();
    solve();
    return 0;
}