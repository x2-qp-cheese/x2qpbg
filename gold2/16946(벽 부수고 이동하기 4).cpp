#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];       // 입력으로 주어진 지도 (0: 빈 칸, 1: 벽)
int group[1001][1001];       // 각 빈 칸이 속한 그룹 번호 저장
int groupsize[1000001];      // 그룹별 크기 저장 (최대 N*M까지 가능)
int dy[4] = {0, 0, 1, -1};   // 상하좌우 이동용
int dx[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;     // BFS 탐색용 큐

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 지도 입력
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - '0';  // 문자 '0'/'1' → 정수 0/1 변환
        }
    }

    // group 배열을 -1로 초기화 (아직 그룹 배정되지 않음)
    memset(group, -1, sizeof(group));
    int groupnum = 0;  // 그룹 번호 (1부터 시작)

    // 빈 칸(0)마다 BFS로 연결된 구역을 탐색하여 그룹화
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 && group[i][j] == -1){
                groupnum++;                      // 새로운 그룹 생성
                group[i][j] = groupnum;          // 그룹 번호 부여
                groupsize[groupnum] = 1;         // 그룹 크기 1로 시작
                q.push({i, j});                  // BFS 시작점

                // BFS로 같은 그룹에 속하는 빈 칸 탐색
                while(!q.empty()){
                    auto [cury, curx] = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cury + dy[dir];
                        int nx = curx + dx[dir];
                        if(ny < 0 || ny >= n) continue;   // 범위 체크
                        if(nx < 0 || nx >= m) continue;
                        if(group[ny][nx] != -1) continue; // 이미 그룹에 속함
                        if(board[ny][nx] == 1) continue;  // 벽이면 무시
                        q.push({ny, nx});
                        group[ny][nx] = groupnum;        // 그룹 번호 부여
                        groupsize[groupnum]++;           // 그룹 크기 증가
                    }
                }
            }
        }
    }

    // 벽(1)인 칸마다 인접한 그룹들을 확인하여 합산
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1){
                set<int> adj;   // 인접한 그룹 번호 모음 (중복 방지)
                int sum = 1;    // 자기 자신 벽 부수고 빈 칸이 되므로 기본값 1
                for(int dir = 0; dir < 4; dir++){
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny < 0 || ny >= n) continue;
                    if(nx < 0 || nx >= m) continue;
                    if(board[ny][nx] == 0){
                        adj.insert(group[ny][nx]);  // 인접 그룹 번호 추가
                    }
                }
                // 인접한 그룹들의 크기 합산
                for(int g : adj){
                    sum += groupsize[g];
                }
                board[i][j] = sum % 10;  // 문제 조건에 따라 10으로 나눈 나머지 출력
            }
        }
    }

    // 결과 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}
