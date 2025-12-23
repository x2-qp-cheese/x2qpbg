#include <bits/stdc++.h>
using namespace std;

// 5x5 학생 배치 정보 ('S' 또는 'Y')
char board[5][5];

// 선택된 위치를 표시하는 보조 보드
int chkboard[5][5];

// BFS 방문 체크 배열
bool visited[5][5];

// 25칸 중 선택 여부 (조합용)
bool sel[25];

// 상하좌우 이동
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int cnts;    // 선택된 7명 중 'S' 학생 수
int result;  // 정답 개수

//중복 확인
// 선택된 7칸이 서로 인접해 있는지 확인하는 함수
bool chkadj(){
	int cnt = 0;  // 연결된 컴포넌트 개수
	queue<pair<int, int>> q;

	// sel 배열을 chkboard(2차원)로 변환
	for(int i = 0; i < 25; i++){
		if(sel[i]){
			chkboard[i/5][i%5] = 1;
		}
	}

	// 모든 칸을 순회하며 BFS 시작점 탐색
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			// 선택된 칸이고 아직 방문하지 않았다면
			if(chkboard[i][j] && !visited[i][j]){
				if(board[i][j] == 'S') cnts++;  // 'S' 학생 수 증가
				q.push({i, j});
				visited[i][j] = true;
				cnt++;  // 새로운 연결 요소 발견

				// BFS로 인접한 선택 칸 탐색
				while(!q.empty()){
					auto [y, x] = q.front(); q.pop();
					for(int dir = 0; dir < 4; dir++){
						int ny = y + dy[dir];
						int nx = x + dx[dir];

						// 범위 체크
						if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
						// 선택되지 않았거나 이미 방문한 칸 제외
						if(!chkboard[ny][nx] || visited[ny][nx]) continue;

						if(board[ny][nx] == 'S') cnts++;  // 'S' 학생 수 증가
						visited[ny][nx] = true;
						q.push({ny, nx});
					}
				}
			}
		}
	}

	// 선택된 7칸이 하나의 컴포넌트면 true
	if(cnt == 1) return true;
	return false;
}

// 25칸 중 7칸을 고르는 조합 함수
void combination(int idx, int cnt){
	// 7명을 모두 선택한 경우
	if(cnt == 7){
		cnts = 0;  // 'S' 학생 수 초기화
		memset(chkboard, 0, sizeof(chkboard));
		memset(visited, 0, sizeof(visited));

		// 인접 조건 + 'S' 학생 4명 이상
		if(chkadj() && cnts >= 4){
			result++;
		}
		return;
	}

	// 조합 생성 (중복 없이 증가 방향)
	for(int i = idx; i < 25; i++){
		if(!sel[i]){
			sel[i] = true;
			combination(i, cnt + 1);
			sel[i] = false;
		}
	}
}

int main(){
	// 입력 받기
	for(int i = 0; i < 5; i++){
		string s; cin >> s;
		for(int j = 0; j < 5; j++){
			board[i][j] = s[j];
		}
	}

	// 조합 시작
	combination(0, 0);

	// 결과 출력
	cout << result;
}