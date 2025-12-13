#include <bits/stdc++.h>
using namespace std;

// 상, 하, 좌, 우 이동
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char board[101][101];        // 건물 지도
bool visited[101][101];      // 방문 체크
int h, w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase; 
    cin >> testcase;

    while(testcase--){
        cin >> h >> w;
        int result = 0;      // 획득한 문서 수

        memset(visited, 0, sizeof(visited));

        queue<pair<int,int>> q;           // BFS 큐
        queue<pair<int,int>> door[26];    // 아직 못 여는 문 좌표 저장
        unordered_set<char> key;          // 가지고 있는 열쇠 (소문자)

        // 지도 입력
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
            }
        }

        // 초기 열쇠 입력
        string userkey; 
        cin >> userkey;

        if(userkey != "0"){
            for(char c : userkey){
                key.insert(c);   // 열쇠는 소문자로 저장
            }
        }

        // ===== 테두리에서 시작 가능한 지점 처리 =====
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                // 테두리가 아니면 스킵
                if(i != 0 && j != 0 && i != h-1 && j != w-1) continue;
                if(board[i][j] == '*' || visited[i][j]) continue;

                char cur = board[i][j];

                // 빈 칸 또는 문서
                if(cur == '.' || cur == '$'){
                    visited[i][j] = true;
                    q.push({i, j});
                    if(cur == '$') result++;
                }
                // 열쇠
                else if(cur >= 'a' && cur <= 'z'){
                    visited[i][j] = true;
                    q.push({i, j});
                    key.insert(cur);

                    // 이 열쇠로 열 수 있는 문들 모두 큐에 추가
                    int idx = cur - 'a';
                    while(!door[idx].empty()){
                        q.push(door[idx].front());
                        door[idx].pop();
                    }
                }
                // 문
                else if(cur >= 'A' && cur <= 'Z'){
                    int idx = cur - 'A';
                    // 열쇠가 있으면 통과
                    if(key.count(cur + 32)){
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                    // 없으면 나중을 위해 저장
                    else{
                        door[idx].push({i, j});
                    }
                }
            }
        }

        // ===== BFS 탐색 =====
        while(!q.empty()){
            auto [y, x] = q.front(); 
            q.pop();

            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                // 범위 밖
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                // 벽이거나 이미 방문
                if(visited[ny][nx] || board[ny][nx] == '*') continue;

                char cur = board[ny][nx];

                // 빈 칸 또는 문서
                if(cur == '.' || cur == '$'){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    if(cur == '$') result++;
                }
                // 열쇠
                else if(cur >= 'a' && cur <= 'z'){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    key.insert(cur);

                    // 새로 얻은 열쇠로 열 수 있는 문 처리
                    int idx = cur - 'a';
                    while(!door[idx].empty()){
                        q.push(door[idx].front());
                        door[idx].pop();
                    }
                }
                // 문
                else if(cur >= 'A' && cur <= 'Z'){
                    int idx = cur - 'A';
                    // 열쇠가 있으면 통과
                    if(key.count(cur + 32)){
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                    // 없으면 대기
                    else{
                        door[idx].push({ny, nx});
                    }
                }
            }
        }

        // 결과 출력
        cout << result << '\n';
    }
}