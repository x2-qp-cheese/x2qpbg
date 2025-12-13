#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int board[MAX][MAX];   // 각 칸의 높이 정보
int dp[MAX][MAX];      // dp[y][x] : (y,x)에서 도착점까지 갈 수 있는 경로 수

// 상, 하, 좌, 우 이동
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int m, n; 

int dfs(int y, int x){
	// 도착점에 도달하면 경로 1개 완성
	if(y == m - 1 && x == n - 1) return 1;

	// 이미 계산한 칸이면 저장된 값 재사용
	if(dp[y][x] != -1) return dp[y][x];
	 
	// 아직 계산 안 된 칸 → 경로 수 0으로 초기화
	dp[y][x] = 0;

	// 4방향 탐색
	for(int dir = 0; dir < 4; dir++){
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 범위 밖이면 스킵
		if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

		// 더 낮은 높이로만 이동 가능
		if(board[ny][nx] < board[y][x]){
			dp[y][x] += dfs(ny, nx); 
		}
	}

	// (y,x)에서 도착점까지 갈 수 있는 총 경로 수 반환
	return dp[y][x];
}

int main(){
	cin >> m >> n;

	// 높이 정보 입력
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	// dp 배열을 -1로 초기화 (아직 계산 안 함 표시)
	memset(dp, -1, sizeof(dp));

	// 출발점 (0,0)에서 시작
	cout << dfs(0, 0);
}
