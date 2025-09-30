#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[501][501];   // 격자에 입력되는 방향 정보 (U, D, L, R)
int state[501][501];    // 각 칸의 탐색 상태 (0: 미방문, 1: 방문 중, 2: 탈출 가능, 3: 사이클)

// 방향 매핑용 배열 (board에 저장된 문자 'U','D','L','R'를 인덱스로 사용)
int dy[256], dx[256];

// 깊이 우선 탐색 (DFS)
int dfs(int y, int x){
    // 격자 범위를 벗어난 경우 → 탈출 성공
    if(y < 0 || y >= n || x < 0 || x >= m) return 2; 

    // 현재 칸을 다시 방문한 경우 (재귀 도중 같은 칸을 만남) → 사이클
    if(state[y][x] == 1) return 3;

    // 이미 결과가 확정된 칸이라면 그 결과를 그대로 반환
    if(state[y][x] == 2 || state[y][x] == 3) return state[y][x];

    state[y][x] = 1; // 방문 중 상태 표시

    // 현재 칸의 방향에 따라 다음 칸 좌표 계산
    int ny = y + dy[(int)board[y][x]];
    int nx = x + dx[(int)board[y][x]];

    // 다음 칸으로 DFS 진행 후 결과를 현재 칸에도 기록
    state[y][x] = dfs(ny, nx);
    return state[y][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력: 격자 크기
    cin >> n >> m;

    // 격자 입력 (각 칸의 방향 저장)
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j];
        }
    }

    // 방향 매핑 (각 문자에 해당하는 이동 벡터 저장)
    dy['U'] = -1; dx['U'] = 0;
    dy['D'] = 1;  dx['D'] = 0;
    dy['L'] = 0;  dx['L'] = -1;
    dy['R'] = 0;  dx['R'] = 1;

    int res = 0; // 탈출 가능한 시작점의 개수
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dfs(i, j) == 2) res++; // 탈출 가능이면 개수 증가
        }
    }

    cout << res; // 결과 출력
}
