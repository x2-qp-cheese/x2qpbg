#include <bits/stdc++.h> // 대부분의 표준 라이브러리를 포함 (iostream, vector, queue 등)
using namespace std;

// 상하좌우 네 방향 탐색을 위한 배열 정의
// dx: x축(열) 이동 변화량 {1, -1, 0, 0} -> {오른쪽, 왼쪽, 변화 없음, 변화 없음}
// dy: y축(행) 이동 변화량 {0, 0, 1, -1} -> {변화 없음, 변화 없음, 아래, 위}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// BFS 탐색에 사용할 큐. (y, x) 좌표 쌍을 저장
queue<pair<int, int>> q; 

// 지도의 상태를 저장하는 2차원 배열 (최대 25x25 크기이지만 안전하게 26x26으로 선언)
// 1은 집이 있음, 0은 집이 없음
int board[26][26]; 

// 방문 여부를 체크하는 2차원 배열
bool visited[26][26]; 

int main(){
    // 입출력 속도 향상 (선택 사항)
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n; // 지도의 크기 (N x N)
    cin >> n; 
    
    int cnt = 0; // 총 단지의 개수를 저장하는 변수
    vector<int> result; // 각 단지의 크기(집의 개수)를 저장할 벡터

    // --- 지도 입력 받기 ---
    for(int i = 0; i < n; i++){
        string s;
        cin >> s; // 한 줄 전체를 문자열로 입력 받음
        for(int j = 0; j < n; j++){
            // 문자 '0' 또는 '1'을 정수 0 또는 1로 변환하여 board에 저장
            board[i][j] = s[j] - '0'; 
        }
    }

    // --- 전체 지도를 순회하며 단지 찾기 (BFS 탐색 시작점 찾기) ---

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // **새로운 단지 탐색 시작 조건:**
            // 1. 현재 위치에 집이 있고 (board[i][j] == 1)
            // 2. 아직 방문하지 않았다면 (!visited[i][j])
            if(board[i][j] && !visited[i][j]){
                // BFS 시작
                q.push({i, j}); // 큐에 시작 좌표 삽입
                visited[i][j] = true; // 방문 처리
                cnt += 1; // 새로운 단지 발견, 단지 개수 증가
                int ssize = 1; // 현재 단지의 크기 (집의 개수) 초기화. 시작점 포함 1

                // --- BFS 탐색 루프 ---
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop(); // 큐에서 현재 좌표 꺼냄
                    int y = cur.first; // 현재 행(y) 좌표
                    int x = cur.second; // 현재 열(x) 좌표
                    
                    // 상하좌우 네 방향 탐색
                    for(int dir = 0; dir < 4; dir++){
                        int ny = y + dy[dir]; // 다음 행(y) 좌표
                        int nx = x + dx[dir]; // 다음 열(x) 좌표
                        
                        // 1. **경계 조건 체크**: 지도의 범위를 벗어나는지 확인
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        
                        // 2. **방문 및 집 존재 조건 체크**:
                        //    - 다음 위치에 집이 없거나 (!board[ny][nx] == 0)
                        //    - 이미 방문했다면 (visited[ny][nx])
                        //    -> 탐색하지 않고 건너뜀
                        if(!board[ny][nx] || visited[ny][nx]) continue;
                        
                        // 위의 조건을 모두 통과했다면, 연결된 새 집 발견
                        visited[ny][nx] = true; // 방문 처리
                        ssize++; // 단지 크기 증가
                        q.push({ny, nx}); // 큐에 새 좌표 삽입하여 다음 탐색 예약
                    }                    
                }
                // BFS가 끝나면 하나의 단지 탐색 완료.
                result.push_back(ssize); // 계산된 단지 크기를 결과 벡터에 저장
            }
        }
    }
    
    // --- 결과 출력 ---
    sort(result.begin(), result.end()); // 단지 크기를 오름차순으로 정렬
    
    cout << cnt << endl; // 1. 총 단지 개수 출력
    
    // 2. 각 단지의 크기를 한 줄씩 출력
    for(int i = 0; i < cnt; i++){
        cout << result[i] << endl;
    }
}