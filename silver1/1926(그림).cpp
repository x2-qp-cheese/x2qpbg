#include <bits/stdc++.h> // C++ 표준 라이브러리 대부분을 포함합니다. (주로 알고리즘 문제를 풀 때 사용)
using namespace std; // 표준 네임스페이스를 사용합니다.

// 상하좌우 네 방향으로 이동하기 위한 좌표 변화량 배열
int dx[4] = {1, -1, 0, 0}; // x축 변화량: 오른쪽, 왼쪽, 제자리, 제자리
int dy[4] = {0, 0, 1, -1}; // y축 변화량: 제자리, 제자리, 아래, 위 (y를 행, x를 열로 간주)

queue<pair<int, int>> q; // BFS를 위한 큐. 방문할 (y좌표, x좌표) 쌍을 저장합니다.
int visited[501][501]; // 방문 여부를 체크하는 2차원 배열. 중복 탐색을 막습니다.
int board[501][501]; // 입력받는 맵/그리드 배열. 1은 그림의 일부, 0은 배경을 나타냅니다.
int res; // 발견된 연결 요소 중 최대 크기를 저장하는 변수입니다.

int main(){
    // 입출력 속도 향상 (선택 사항이지만 성능에 도움 됨)
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n, m; // n: 행의 개수 (세로), m: 열의 개수 (가로)
    int cnt = 0; // 그림(연결 요소)의 총 개수를 세는 카운터
    cin >> n >> m; // 행과 열의 크기를 입력받습니다.

    // 맵의 정보를 입력받습니다.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    // 전체 맵을 순회하며 연결 요소(그림)를 탐색합니다.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 조건: 1. 현재 칸이 그림의 일부이고 (board[i][j] == 1)
            //       2. 아직 방문하지 않았다면 (!visited[i][j])
            // -> 새로운 그림의 시작점을 발견한 것입니다.
            if(board[i][j] && !visited[i][j]){
                // 새로운 BFS 시작
                q.push({i, j}); // 시작점을 큐에 넣습니다.
                int cursize = 1; // 현재 그림의 크기를 1로 초기화합니다.
                visited[i][j] = 1; // 시작점을 방문 처리합니다.
                cnt++; // 그림의 개수를 하나 증가시킵니다.
                
                // --- BFS 탐색 시작 ---
                while(!q.empty()){
                    pair<int, int> cur = q.front(); 
                    q.pop(); // 큐에서 현재 좌표를 꺼냅니다.
                    int y = cur.first; // 현재 y (행) 좌표
                    int x = cur.second; // 현재 x (열) 좌표
                    
                    // 상하좌우 4방향을 탐색합니다.
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir]; // 다음 y 좌표
                        int nx = x + dx[dir]; // 다음 x 좌표
                        
                        // 1. 맵의 경계를 벗어나는지 확인 (맵 범위 체크)
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        
                        // 2. 다음 칸이 그림의 일부가 아닌지 확인 (0인지 체크)
                        if(!board[ny][nx])
                            continue;
                        
                        // 3. 이미 방문한 칸인지 확인
                        if(visited[ny][nx])
                            continue;
                        
                        // 위의 조건을 모두 통과하면 유효한 다음 그림 조각입니다.
                        q.push({ny, nx}); // 큐에 추가하여 나중에 방문하도록 예약
                        cursize++; // 현재 그림의 크기를 증가
                        visited[ny][nx] = 1; // 방문 처리
                    }
                }
                // 하나의 그림 탐색이 완료되면, 최대 크기(res)를 갱신합니다.
                res = max(res, cursize);
            }
        }
    }

    // 결과 출력
    cout << cnt << endl; // 그림의 총 개수 출력
    cout << res; // 가장 큰 그림의 크기 출력
}