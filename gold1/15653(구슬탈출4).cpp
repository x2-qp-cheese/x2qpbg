#include <bits/stdc++.h>
#define MAX 11
using namespace std;

// 보드 정보
char board[MAX][MAX];

// 방문 체크: (빨강 y,x, 파랑 y,x)
bool visited[MAX][MAX][MAX][MAX];

// 순서대로 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// BFS에서 사용할 상태 구조체
// ry, rx : 빨간 구슬 위치
// by, bx : 파란 구슬 위치
// cnt    : 현재까지 이동 횟수
struct Struct{
	int ry, rx;
	int by, bx;
	int cnt;
};

queue<Struct> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int rsy, rsx; // 빨간 구슬 시작 위치
	int bsy, bsx; // 파란 구슬 시작 위치

	// 보드 입력
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];

			// 빨간 구슬 위치 저장 후 보드는 빈 칸으로 처리
			if(board[i][j] == 'R'){
				board[i][j] = '.';
				rsy = i; rsx = j;
			}

			// 파란 구슬 위치 저장 후 보드는 빈 칸으로 처리
			if(board[i][j] == 'B'){
				board[i][j] = '.';
				bsy = i; bsx = j;
			}
		}
	}

	// BFS 시작 상태 삽입
	q.push({rsy, rsx, bsy, bsx, 0});
	visited[rsy][rsx][bsy][bsx] = true;

	int successflag = 0;

	// BFS 탐색
	while(!q.empty()){
		auto[curRy, curRx, curBy, curBx, curcnt] = q.front();
		q.pop();

		// 4방향 탐색
		for(int dir = 0; dir < 4; dir++){
			successflag = 0; // 방향마다 성공 여부 초기화

			/* ===== 빨간 구슬 이동 ===== */
			int nRy = curRy;
			int nRx = curRx;
			while(true){
				int tmpy = nRy + dy[dir];
				int tmpx = nRx + dx[dir];

				// 벽이면 정지
				if(board[tmpy][tmpx] == '#')
					break;

				// 구멍에 빠지면 성공 표시
				if(board[tmpy][tmpx] == 'O'){
					successflag |= 1;
					nRy = tmpy;
					nRx = tmpx;
					break;
				}

				// 계속 이동
				nRy = tmpy;
				nRx = tmpx;
			}

			/* ===== 파란 구슬 이동 ===== */
			int nBy = curBy;
			int nBx = curBx;
			while(true){
				int tmpy = nBy + dy[dir];
				int tmpx = nBx + dx[dir];

				// 벽이면 정지
				if(board[tmpy][tmpx] == '#')
					break;

				// 구멍에 빠지면 실패 표시
				if(board[tmpy][tmpx] == 'O'){
					successflag |= 2;
					nBy = tmpy;
					nBx = tmpx;
					break;
				}

				// 계속 이동
				nBy = tmpy;
				nBx = tmpx;
			}

			// 파란 구슬이 빠지면 이 방향은 무효
			if(successflag & 2) continue;

			// 빨간 구슬만 빠지면 성공
			if(successflag & 1){
				cout << curcnt + 1;
				return 0;
			}

			/* ===== 두 구슬이 같은 칸에 도착한 경우 처리 ===== */
			if(nRy == nBy && nRx == nBx){
				// 이동 방향 기준으로 더 뒤에 있던 구슬을 한 칸 뒤로 이동
				if(dir == 0){ // 상
					if(curRy < curBy) nBy++;
					else nRy++;
				}
				else if(dir == 1){ // 하
					if(curRy > curBy) nBy--;
					else nRy--;
				}
				else if(dir == 2){ // 좌
					if(curRx < curBx) nBx++;
					else nRx++;
				}
				else if(dir == 3){ // 우
					if(curRx > curBx) nBx--;
					else nRx--;
				}
			}

			// 방문하지 않은 상태라면 큐에 삽입
			if(!visited[nRy][nRx][nBy][nBx]){
				visited[nRy][nRx][nBy][nBx] = true;
				q.push({nRy, nRx, nBy, nBx, curcnt + 1});
			}
		}
	}

	// 성공하지 못한 경우
	cout << -1;
	return 0;
}