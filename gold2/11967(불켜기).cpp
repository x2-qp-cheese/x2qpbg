#include <bits/stdc++.h>
using namespace std;

int board[101][101][2]; 
// board[x][y][0] = 불이 켜져있는지 여부 (0: 꺼짐, 1: 켜짐)
// board[x][y][1] = 방문 여부 (0: 방문 안함, 1: 방문함)

int dy[4] = {0, 0, 1, -1}; // 상하좌우 이동 (y 좌표 변화)
int dx[4] = {1, -1, 0, 0}; // 상하좌우 이동 (x 좌표 변화)

queue<pair<int,int>> q; // BFS 탐색을 위한 큐
vector<pair<int,int>> poss[101][101]; 
// poss[x][y] = (x,y) 방에서 켤 수 있는 전등의 좌표 리스트

int main(){
    int n, m; // n = 방의 크기 (n x n), m = 스위치의 개수
    int cnt = 1; // 불이 켜진 방의 개수 (초기값 = (1,1) 방이 켜져있음)

    cin >> n >> m;

    // m개의 스위치 정보 입력
    // (x,y) 방에 들어가면 (a,b) 방의 불을 켤 수 있다
    for(int i = 0; i < m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        poss[x][y].push_back({a, b});
    }

    // 시작 지점 (1,1)
    q.push({1, 1});
    board[1][1][0] = 1; // (1,1)은 불이 켜져 있음
    board[1][1][1] = 1; // (1,1)은 방문 처리

    // BFS 탐색 시작
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        // (x,y) 방에 있는 스위치를 눌러서 켤 수 있는 방 확인
        if(!poss[x][y].empty()){
            for(auto nxt : poss[x][y]){
                // 아직 불이 켜진 적 없는 방이라면
                if(board[nxt.first][nxt.second][0] == 0){
                    cnt++; // 새로 불이 켜졌으므로 카운트 증가
                    board[nxt.first][nxt.second][0] = 1;

                    // 새로 불이 켜진 방이 이동 가능한지 확인
                    for(int dir = 0; dir < 4; dir++){
                        int nx = nxt.first + dx[dir];
                        int ny = nxt.second + dy[dir];
                        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        // 인접한 칸이 불이 켜져 있고, 이미 방문한 칸이라면 이동 가능
                        if(board[nx][ny][0] == 1 && board[nx][ny][1] == 1){
                            q.push({nxt.first, nxt.second});
                            board[nxt.first][nxt.second][1] = 1;
                        }
                    }
                }
            }
        }

        // (x,y) 방에서 상하좌우 인접한 방으로 이동 시도
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // 불이 켜져 있고, 아직 방문하지 않았다면 이동 가능
            if(board[nx][ny][0] == 1 && board[nx][ny][1] == 0){
                board[nx][ny][1] = 1;
                q.push({nx, ny});
            }
        }
    }

    // 최종적으로 불이 켜진 방의 개수 출력
    cout << cnt;
}