#include <bits/stdc++.h>
using namespace std;
#define MAX 11
int dy[4] = {-1, 1, 0, 0}; 
int dx[4] = {0, 0, -1, 1};

char board[MAX][MAX];

// 하나의 상태에 빨강/파랑을 같이 넣기
struct State {
    int ry, rx;
    int by, bx;
    int cnt;
};

int visited[MAX][MAX][MAX][MAX]; 

queue<State> q;

int main() {
    int n, m; cin >> n >> m;
    int result = -1;

    int ry, rx, by, bx;

    // 보드 입력과 동시에 R과 B의 초기 좌표를 탐색해 저장한다.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                ry = i; rx = j;  // 빨간 구슬 출발 위치
            }
            if(board[i][j] == 'B'){
                by = i; bx = j;  // 파란 구슬 출발 위치
            }
        }
    }

    // 초기 BFS 상태 push
    q.push({ry, rx, by, bx, 0});
    visited[ry][rx][by][bx] = 1; // 방문 체크: 두 구슬의 위치 조합

    while(!q.empty()){
        State cur = q.front(); 
        q.pop();

        // 이동 횟수 제한: 10번 이내에 성공해야 함
        if(cur.cnt >= 10) continue;

        // 4방향으로 굴리기
        for(int dir = 0; dir < 4; dir++){
            int successflag = 0; // bit 1: R 성공, bit 2: B 성공

            // *** 빨간 구슬 이동 ***
            int rednY = cur.ry, rednX = cur.rx;
            while(true){
                int tmpny = rednY + dy[dir];
                int tmpnx = rednX + dx[dir];

                // 벽을 만나면 이동 종료
                if(board[tmpny][tmpnx] == '#') break;

                // 구멍을 만나면 성공 상태 체크 후 종료
                if(board[tmpny][tmpnx] == 'O'){
                    successflag |= 1;  // red success
                    rednY = tmpny; rednX = tmpnx;
                    break;
                }

                // 빈 칸이면 계속 전진
                rednY = tmpny; rednX = tmpnx;
            }

            // *** 파란 구슬 이동 ***
            int bluenY = cur.by, bluenX = cur.bx;
            while(true){
                int tmpny = bluenY + dy[dir];
                int tmpnx = bluenX + dx[dir];

                // 벽을 만나면 이동 종료
                if(board[tmpny][tmpnx] == '#') break;

                // 구멍을 만나면 파란 구슬 실패 상태 표시
                if(board[tmpny][tmpnx] == 'O'){
                    successflag |= 2;  // blue fail
                    bluenY = tmpny; bluenX = tmpnx;
                    break;
                }

                // 빈 칸이면 계속 이동
                bluenY = tmpny; bluenX = tmpnx;
            }

            // 파란 공이 빠지면 이 방향은 실패 → 다음 방향
            if(successflag & 2) continue;

            // 빨간 공만 빠진 경우 → 즉시 성공
            if(successflag & 1){
                result = cur.cnt + 1;
                cout << result;
                return 0;
            }

            // 두 구슬이 같은 칸에 겹치면 위치 조정해야 함
            if(rednY == bluenY && rednX == bluenX){
                // 이동 방향에 따라 원래 위치가 더 뒤에 있던 구슬을 한 칸 뒤로 밀어낸다.
                if(dir == 0){ // 상
                    if(cur.ry < cur.by) bluenY++;  // 파란 구슬이 더 뒤에서 따라온 경우
                    else rednY++;
                }
                else if(dir == 1){ // 하
                    if(cur.ry > cur.by) bluenY--;
                    else rednY--;
                }
                else if(dir == 2){ // 좌
                    if(cur.rx < cur.bx) bluenX++;
                    else rednX++;
                }
                else if(dir == 3){ // 우
                    if(cur.rx > cur.bx) bluenX--;
                    else rednX--;
                }
            }

            // 아직 방문한 적 없는 위치라면 큐에 삽입
            if(visited[rednY][rednX][bluenY][bluenX] == 0){
                visited[rednY][rednX][bluenY][bluenX] = 1;
                q.push({rednY, rednX, bluenY, bluenX, cur.cnt + 1});
            }
        }
    }

    // 10번 안에 빠지지 못한 경우
    cout << result;
    return 0;
}
