#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];              // 지도 정보 (0: 빈 칸, 1: 벽)
int visited[1001][1001][11];        // visited[y][x][broken] : (y,x)에 벽 broken개 부수고 도착했을 때의 거리

queue<tuple<int,int,int>> q;        // BFS 큐 (y좌표, x좌표, 부순 벽 개수)

int dx[4] = {1, -1, 0, 0};          // 상하좌우 이동
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m, k;
    cin >> n >> m >> k;             // n: 세로 크기, m: 가로 크기, k: 부술 수 있는 벽의 최대 개수
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;  
        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - '0';   // 문자열 입력을 숫자로 변환하여 보드에 저장
        }
    }
    int res = INT_MAX;                  // 결과값 (최단거리), 초기에는 무한대로 설정
    q.push({0, 0, 0});                  // 시작점 (0,0), 부순 벽 0개
    visited[0][0][0] = 1;               // 시작점 방문 처리, 거리 = 1

    // BFS 탐색 시작
    while(!q.empty()){
        auto[y, x, broken] = q.front();
        q.pop();

        // 도착지 (n-1, m-1)에 도달했을 경우
        if(y == n - 1 && x == m - 1)
            res = min(res, visited[y][x][broken]);

        // 4방향 탐색
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 보드 범위를 벗어나면 무시
            if(ny < 0 || ny >= n) continue;
            if(nx < 0 || nx >= m) continue;

            // (1) 벽을 만난 경우 → 아직 벽을 더 부술 수 있는 경우만 가능
            if(board[ny][nx] == 1 && broken < k && visited[ny][nx][broken+1] == 0){
                visited[ny][nx][broken+1] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken+1});
            }
            // (2) 빈 칸을 만난 경우
            if(board[ny][nx] == 0 && visited[ny][nx][broken] == 0){
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }
        }
    }

    // 최단 경로가 없는 경우 -1 출력
    if(res == INT_MAX)
        cout << -1;
    else
        cout << res;
}
