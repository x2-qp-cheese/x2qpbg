#include <bits/stdc++.h>
using namespace std;

char board[21][21];        // 보드(알파벳 격자)
int dy[4] = {1, -1, 0, 0}; // 상하좌우 y 방향 이동
int dx[4] = {0, 0, 1, -1}; // 상하좌우 x 방향 이동
int r, c;                  // 보드의 행(r), 열(c)
int res;                   // 최대 이동 칸 수 결과
int alphabet[26];          // 방문한 알파벳 기록 (0: 미사용, 1: 사용됨)

// 깊이 우선 탐색 (DFS)
void dfs(int y, int x, int cnt){
    // 현재까지 이동한 칸 수(cnt)로 결과 갱신
    res = max(cnt, res);

    // 4방향 탐색
    for(int dir = 0; dir < 4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 보드 범위를 벗어나면 패스
        if(ny < 0 || ny >= r) continue;
        if(nx < 0 || nx >= c) continue;

        // 이미 방문한 알파벳이면 패스
        if(alphabet[board[ny][nx] - 'A'] == 1) continue;

        // 새로운 알파벳 방문 체크
        alphabet[board[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt+1);               // 다음 칸으로 DFS 진행
        alphabet[board[ny][nx] - 'A'] = 0; // 백트래킹 (방문 해제)
    }
}

int main(){
    cin >> r >> c; // 보드 크기 입력

    // 보드 입력
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j < c; j++){
            board[i][j] = s[j];
        }
    }

    // 시작점 (0,0)의 알파벳 사용 체크
    alphabet[board[0][0] - 'A']++;

    // DFS 시작
    dfs(0, 0, 1);

    // 결과 출력
    cout << res;
}