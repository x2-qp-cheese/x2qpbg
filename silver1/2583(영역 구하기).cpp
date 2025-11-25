#include <bits/stdc++.h>
using namespace std;

// BFS 이동 방향 (상, 하, 좌, 우)
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int board[101][101];      // 0 = 빈 영역, 1 = 직사각형 내부(막힌 영역)
int visited[101][101];    // 방문 체크
queue<pair<int, int>> q;  // BFS 큐

int main(){
    int m, n, k;
    cin >> m >> n >> k;    // m = 높이(행), n = 너비(열)

    int cnt = 0;           // 분리된 영역 개수
    vector<int> res;       // 각 영역의 넓이 저장

    // K개의 직사각형 입력받아 board[][]에 표시
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 직사각형 내부를 board = 1로 채움
        // y1 ≤ y < y2, x1 ≤ x < x2 범위
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                board[i][j] = 1;    // 1 = 막힌 영역
            }
        }
    }

    // 전체 격자를 돌며 BFS로 빈 영역(0) 탐색
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            // 빈 칸이면서 방문하지 않은 곳을 발견하면 BFS 시작
            if(board[i][j] == 0 && visited[i][j] == 0){

                cnt++;                  // 새로운 영역 발견
                visited[i][j] = 1;
                q.push({i, j});

                int ssize = 1;          // 현재 영역의 넓이

                // BFS 탐색
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    int y = cur.first;
                    int x = cur.second;

                    // 4방향 탐색
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        // 범위를 벗어나면 무시
                        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

                        // 이미 방문했거나, 직사각형 내부(1)면 skip
                        if(board[ny][nx] == 1 || visited[ny][nx] == 1) continue;

                        // 방문 처리 후 큐에 추가
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                        ssize++;        // 넓이 증가
                    }
                }

                // 현재 영역 넓이 저장
                res.push_back(ssize);
            }
        }
    }

    // 오름차순 출력
    sort(res.begin(), res.end());

    cout << cnt << endl;           // 총 영역 개수 출력
    for(int i = 0; i < cnt; i++){
        cout << res[i] << " ";     // 각 영역 넓이 출력
    }
}
