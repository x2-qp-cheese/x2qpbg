#include <bits/stdc++.h>
using namespace std;

int board[301][301];  // 빙산 상태를 나타내는 보드
int tmp[301][301];    // 빙산 상태가 변할 때 임시로 저장할 배열
int vis[301][301];    // 방문 여부를 체크하는 배열

int n, m;  // n은 세로 크기, m은 가로 크기
queue<pair<int, int>> q;  // BFS를 위한 큐
int dy[4] = {0, 0, 1, -1};  // 상, 하, 좌, 우 방향에 대한 y 좌표 변화량
int dx[4] = {1, -1, 0, 0};  // 상, 하, 좌, 우 방향에 대한 x 좌표 변화량

// 빙산이 나눠져있는지 확인하는 BFS 함수
int bfs(){
    memset(vis, 0, sizeof(vis));  // 방문 배열 초기화
    int cnt = 0;  // 나누어진 빙산 덩어리의 개수
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 빙산이 있고 아직 방문하지 않은 곳이 있다면
            if(board[i][j] && vis[i][j] == 0){
                q.push({i, j});  // 큐에 시작점을 넣고
                vis[i][j] = 1;  // 방문 처리
                cnt+=1;  // 새로운 빙산 덩어리가 발견되었으므로 카운트 증가
                // BFS 시작
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    // 4방향으로 이동하며 연결된 빙산을 찾음
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];  // 새로운 y 좌표
                        int nx = cur.second + dx[dir];  // 새로운 x 좌표
                        if(ny < 0 || ny >= n) continue;  // 범위 벗어나면 skip
                        if(nx < 0 || nx >= m) continue;  // 범위 벗어나면 skip
                        if(board[ny][nx] == 0) continue;  // 빙산이 아닌 곳은 skip
                        if(vis[ny][nx] != 0) continue;  // 이미 방문한 곳은 skip
                        vis[ny][nx] = 1;  // 방문 처리
                        q.push({ny, nx});  // 큐에 추가
                    }
                }
            }
        }
    }
    return cnt;  // 나누어진 빙산 덩어리 개수 리턴
}

int main(){
    cin >> n >> m;  // 보드의 크기 입력
    int time = 0;  // 경과 시간

    // 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];  // 빙산의 상태를 입력받음
        }
    }

    // 시간 동안 반복
    while(1){
        int icebergNum = bfs();  // 빙산이 몇 덩어리로 나뉘었는지 확인
        if(icebergNum == 0){  // 빙산이 모두 녹았다면
            cout << 0;  // 시간이 끝난 후 0을 출력하고 종료
            return 0;
        }
        else if(icebergNum > 1){  // 두 개 이상의 덩어리가 발견되었다면
            cout << time;  // 경과 시간을 출력하고 종료
            return 0;
        }
        time+=1;  // 시간이 흐름

        // 빙산이 녹는 과정
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]){
                    int zeroNum = 0;  // 주변의 0인 칸 개수
                    // 상하좌우 방향으로 확인
                    for(int dir = 0; dir < 4; dir++){
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if(ny < 0 || ny >= n) continue;  // 범위 벗어나면 skip
                        if(nx < 0 || nx >= m) continue;  // 범위 벗어나면 skip
                        if(board[ny][nx] == 0) zeroNum+=1;  // 주변이 바다면 count 증가
                    }
                    // 주변 0 개수만큼 녹음
                    tmp[i][j] = board[i][j] > zeroNum ? board[i][j] - zeroNum : 0;
                }
            }
        }

        // tmp 배열의 상태를 board로 복사
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = tmp[i][j];
            }
        }
        memset(tmp, 0, sizeof(tmp));  // tmp 배열 초기화
    }
}
