#include <bits/stdc++.h>
using namespace std;

// 이동 방향 배열 (상, 하, 좌, 우)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// BFS에 사용할 큐
queue<pair<int, int>> q;

int board[101][101];   // 미로 정보를 저장 (1:길, 0:벽)
int visited[101][101]; // 방문 여부 + 시작점에서의 거리 저장

int main(){
    int n, m;
    cin >> n >> m;

    // 미로 입력
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - '0';
        }
    }

    // BFS 시작점(0,0)
    q.push({0, 0});
    visited[0][0] = 1; // 시작점까지 거리 1

    // BFS 실행
    while(!q.empty()){
        pair<int, int> cur = q.front(); 
        q.pop();

        int y = cur.first;
        int x = cur.second;

        // 4방향 탐색
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 미로 범위를 벗어나는 경우 패스
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)  
                continue;

            // 벽이거나, 이미 방문한 칸이면 패스
            if(board[ny][nx] == 0 || visited[ny][nx] != 0) 
                continue;

            // 방문 처리 + 거리 기록
            visited[ny][nx] = visited[y][x] + 1;

            // BFS 큐에 넣기
            q.push({ny, nx});
        }
    }

    // 도착 지점(n-1, m-1)까지의 최단 거리 출력
    cout << visited[n-1][m-1];
}