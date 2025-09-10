#include <bits/stdc++.h>
using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// board : 입력받은 지도 (0은 빈칸, 1은 벽)
// visited[y][x][broken] : (y,x)에 도착했을 때의 최단 거리
// broken = 0 → 벽을 아직 부수지 않음, broken = 1 → 벽을 한 번 부숨
int board[1001][1001];
int visited[1001][1001][2];

// BFS 큐 (y좌표, x좌표, 벽 부쉈는지 여부)
queue<tuple<int, int, int>> q;

int main(){
    int n, m;
    cin >> n >> m;  // n = 세로, m = 가로
    
    // 지도 입력
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j]-'0'; // 문자 '0'/'1'을 정수 0/1로 변환
            visited[i][j][0] = visited[i][j][1] = -1; // 아직 방문하지 않은 상태
        }
    }

    // 시작점 (0,0), 아직 벽을 부수지 않은 상태
    visited[0][0][0] = 1;  
    q.push({0, 0, 0});     

    // BFS 시작
    while(!q.empty()){
        auto [y, x, broken] = q.front(); // 현재 좌표와 벽 부쉈는지 여부
        q.pop();

        // 4방향 탐색
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 지도 범위 벗어나면 무시
            if(ny < 0 || ny >= n) continue;
            if(nx < 0 || nx >= m) continue;

            // 이미 방문한 상태라면 무시
            if(visited[ny][nx][broken] != -1) continue;

            if(board[ny][nx] == 0){
                // 벽이 아닌 경우
                q.push({ny, nx, broken});
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
            }
            else if(board[ny][nx] == 1 && broken == 0){
                // 벽인데 아직 벽을 부순 적이 없는 경우 → 벽을 부수고 이동
                q.push({ny, nx, 1});
                visited[ny][nx][1] = visited[y][x][0] + 1;
            }
        }
    }

    // 도착 지점까지의 거리 (벽 안 부숨 vs 부숨)
    int ans1 = visited[n-1][m-1][0];
    int ans2 = visited[n-1][m-1][1];

    // 도달 불가능한 경우 처리
    if(ans1 == -1 && ans2 == -1)
        cout << -1;
    else if(ans1 == -1)
        cout << ans2;
    else if(ans2 == -1)
        cout << ans1;
    else
        cout << min(ans1, ans2); // 둘 다 가능하면 더 짧은 경로 출력
}
