#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, -1, 0, 0};   // 상하좌우 이동을 위한 y좌표 변화
int dx[4] = {0, 0, 1, -1};   // 상하좌우 이동을 위한 x좌표 변화
char board[51][51];          // 지도 정보 ('.', 'X', '*', 'D', 'S')
int visited[51][51][2];      // 방문 배열
                             // visited[y][x][0] : 해당 칸에 물이 차는 시간
                             // visited[y][x][1] : 고슴도치가 해당 칸에 도착하는 시간
queue<pair<int, int>> qs;    // 고슴도치 이동 BFS 큐
queue<pair<int, int>> qw;    // 물 확산 BFS 큐

int main(){
    int r, c;
    cin >> r >> c;
    memset(visited, -1, sizeof(visited)); // -1로 초기화 (아직 방문 안 한 상태)

    // 입력 처리
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S'){          // 고슴도치 시작 위치
                qs.push({i, j});
                visited[i][j][1] = 0;        // 시작 시각은 0
            }
            if(board[i][j] == '*'){          // 물 시작 위치
                qw.push({i, j});
                visited[i][j][0] = 0;        // 시작 시각은 0
            }
        }
    }

    // 1️⃣ 물 BFS (물이 각 칸에 언제 차는지 기록)
    while(!qw.empty()){
        auto[y, x] = qw.front(); qw.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            // 지도 범위 벗어나면 스킵
            if(ny < 0 || ny >= r) continue;
            if(nx < 0 || nx >= c) continue;
            // 벽이거나 비버의 굴(D)인 경우 물이 퍼지지 않음
            if(board[ny][nx] == 'X' || board[ny][nx] == 'D') continue;
            // 이미 방문(물이 찬 시간 기록됨)한 칸은 스킵
            if(visited[ny][nx][0] >= 0) continue;
            // 물 확산
            qw.push({ny, nx});
            visited[ny][nx][0] = visited[y][x][0] + 1; // 이전 칸보다 1시간 뒤
        }
    }

    // 2️⃣ 고슴도치 BFS (물이 차기 전에만 이동 가능)
    while(!qs.empty()){
        auto[y, x] = qs.front(); qs.pop();
        // 비버 굴에 도착하면 종료
        if(board[y][x] == 'D'){
            cout << visited[y][x][1];
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= r) continue;
            if(nx < 0 || nx >= c) continue;
            if(board[ny][nx] == 'X') continue;       // 벽은 못 감
            if(visited[ny][nx][1] >= 0) continue;    // 이미 고슴도치가 방문한 칸은 스킵

            // 물이 안 오거나(visited[ny][nx][0] == -1),
            // 고슴도치가 물보다 먼저 도착할 수 있는 경우만 이동 가능
            if(visited[ny][nx][0] == -1 || visited[y][x][1] + 1 < visited[ny][nx][0]){
                qs.push({ny, nx});
                visited[ny][nx][1] = visited[y][x][1] + 1; // 현재 시간 + 1
            }
        }
    }

    // 비버 굴까지 도달하지 못한 경우
    cout << "KAKTUS";
    return 0;
}