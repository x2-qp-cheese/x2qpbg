#include <bits/stdc++.h>
using namespace std;

int n, m;                       // 세로(n), 가로(m)
int board[100][100];            // 현재 치즈 상태
int tmpboard[100][100];         // 한 시간 후 상태를 저장할 임시 배열
bool visited[100][100];         // BFS 방문 여부 체크

int dy[4] = {-1, 1, 0, 0};      // 상, 하, 좌, 우 이동
int dx[4] = {0, 0, -1, 1};

int result;                     // 현재 남아있는 전체 치즈 개수
int chzsize;                    // 이번 시간에 녹은 치즈 개수
int hr;                         // 치즈가 모두 녹을 때까지 걸린 시간

queue<pair<int, int>> q;        // 외부 공기 BFS를 위한 큐

// src 배열을 dst 배열로 복사
// 한 시간 단위 시뮬레이션에서 상태 스냅샷/적용 용도
void copyboard(int src[100][100], int dst[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dst[i][j] = src[i][j];
        }
    }
}

// 입력 처리
// board를 채우면서 초기 치즈 개수(result)를 계산
void boardInput(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j]) result++;
        }
    }
}

// 치즈가 남아있는 동안 한 시간씩 시뮬레이션
void solve(){
    while(result){
        hr++;                   // 시간 경과
        chzsize = 0;            // 이번 시간에 녹은 치즈 개수 초기화

        // 현재 board 상태를 tmpboard에 복사
        copyboard(board, tmpboard);

        // 방문 배열 초기화
        memset(visited, 0, sizeof(visited));

        // (0,0)에서 시작하여 외부 공기를 BFS로 탐색
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()){
            auto[y, x] = q.front(); q.pop();

            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                // 범위를 벗어나면 무시
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                // 이미 방문한 칸이면 스킵
                if(visited[ny][nx]) continue;

                // 치즈인 경우 → 외부 공기와 접촉한 치즈이므로 녹임
                if(board[ny][nx]){
                    chzsize++;              // 녹은 치즈 개수 증가
                    tmpboard[ny][nx] = 0;  // 다음 상태에서 제거
                }
                // 공기인 경우 → 계속 외부 공기 BFS 확장
                else{
                    q.push({ny, nx});
                }

                visited[ny][nx] = true;    // 방문 처리
            }
        }

        // 전체 치즈 개수에서 이번 시간에 녹은 개수만큼 감소
        result -= chzsize;

        // tmpboard 상태를 board에 반영
        copyboard(tmpboard, board);
    }
}

int main(){
    boardInput();               // 입력
    solve();                    // 치즈 녹이기 시뮬레이션

    cout << hr << endl;         // 치즈가 모두 녹는 데 걸린 시간
    cout << chzsize;            // 마지막 시간에 녹은 치즈 개수
}
