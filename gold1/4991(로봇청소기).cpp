#include <bits/stdc++.h>
using namespace std;

// 최대 맵 크기를 정의합니다.
#define MAX 20

// BFS를 위한 상태 구조체 정의
struct State {
    int y, x;   // 현재 로봇의 (y, x) 좌표
    int mask;   // 청소된 더러운 지점들의 상태를 나타내는 비트마스크
    int dist;   // 현재 상태에 도달하기까지의 이동 거리
};

char board[MAX][MAX]; // 맵 정보를 저장하는 2차원 배열
// visited[y][x][mask]: (y, x) 좌표에 mask 상태로 도착한 적이 있는지 여부
bool visited[MAX][MAX][1<<10]; 
int dx[4] = {1, -1, 0, 0}; // x축 이동 (오, 왼, 제자리, 제자리)
int dy[4] = {0, 0, 1, -1}; // y축 이동 (제자리, 제자리, 아래, 위)


int main(){
    int w, h; // 맵의 너비(w)와 높이(h)
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break; // 입력이 0 0 이면 종료

        queue<State> q; // BFS를 위한 큐
        // visited 배열을 0으로 초기화 (방문하지 않음)
        memset(visited, 0, sizeof(visited)); 
        // 더러운 지점('*')들의 좌표를 저장하는 벡터
        vector<pair<int, int>> dirtyspot; 
        int result = -1; // 최소 이동 횟수. 초기값은 도달 불가능을 의미하는 -1

        // 맵 정보를 읽고 초기 상태 설정
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == '*'){
                    // 더러운 지점이면 좌표를 저장
                    dirtyspot.push_back({i, j}); 
                }
                if(board[i][j] == 'o'){
                    // 시작 위치('o')이면 큐에 초기 상태를 삽입
                    // 시작 위치, 마스크 0 (아무것도 청소 안 함), 거리 0
                    q.push({i, j, 0, 0}); 
                    visited[i][j][0] = true; // 시작 상태 방문 처리
                }
            }
        }

        // BFS 시작
        while(!q.empty()){
            State cur = q.front(); q.pop();

            int dirtysize = dirtyspot.size();
            // 모든 더러운 지점을 청소했을 때의 목표 마스크 값 (예: 3개면 111b = 7)
            int chk = (1<<dirtysize) - 1; 

            // 현재 마스크가 목표 마스크와 같으면 모든 곳을 청소한 것
            if(cur.mask == chk){ 
                result = cur.dist; // 현재 거리가 최소 이동 횟수
                break; // BFS 종료
            }

            // 4방향 이동 탐색
            for(int dir = 0; dir < 4; dir++){
                int ny = cur.y + dy[dir]; // 다음 y 좌표
                int nx = cur.x + dx[dir]; // 다음 x 좌표
                int nxtmask = cur.mask;   // 다음 마스크는 현재 마스크로 초기화
                
                // 다음 칸의 맵 정보를 가져옴 (경계 검사 전에 미리 가져옴)
                // 경계 밖이거나 벽('x')인 경우는 아래에서 continue됨
                char nxtcell = board[ny][nx]; 

                // 맵 경계 검사
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                // 벽('x')이면 이동 불가
                if(nxtcell == 'x') continue; 

                // 다음 상태 (ny, nx, nxtmask)가 이미 방문했는지 검사
                // (nxtcell == '*'일 경우 nxtmask가 변경될 수 있으므로 이 위치에서 검사)
                // 단, nxtcell이 '*'일 때 마스크가 변경되어 새로운 상태가 될 수 있으므로, 
                // 먼저 마스크가 변경되는지 확인 후 최종 방문 여부를 검사하는 것이 더 정확하지만,
                // 이 코드에서는 '*'이 아닐 때의 중복 방문을 막기 위해 여기서 먼저 검사합니다.
                // 다만, 아래에서 마스크가 업데이트될 수 있으므로, '*'에 대한 처리는 이후에 별도로 합니다.
                // 여기서는 '*'이 아닌 경우에만 의미가 있습니다.
                if(visited[ny][nx][nxtmask]) continue;
                
                // 다음 칸이 더러운 지점('*')인 경우
                if(nxtcell == '*'){
                    // dirtyspot 벡터에서 해당 지점의 인덱스를 찾음
                    for(int i = 0; i < dirtysize; i++){
                        if(ny == dirtyspot[i].first && nx == dirtyspot[i].second){
                            // 해당 인덱스에 해당하는 비트를 1로 설정하여 청소 상태 업데이트
                            nxtmask = nxtmask | (1 << i); 
                            break;
                        }
                    }
                }
                
                // 마스크가 업데이트된 후, 새로운 상태로 방문했는지 최종적으로 검사
                // (이전 상태에서 이미 방문한 상태라도 마스크가 변경되면 새로운 상태이므로 다시 방문 가능)
                if(visited[ny][nx][nxtmask]) continue;


                // 새로운 상태 방문 처리
                visited[ny][nx][nxtmask] = true; 
                // 큐에 다음 상태 삽입 (좌표, 업데이트된 마스크, 거리 + 1)
                q.push({ny, nx, nxtmask, cur.dist + 1}); 
            }
        }
        cout << result << endl; // 결과 출력
    }  
}