#include <bits/stdc++.h>
using namespace std;

char board[101][101]; // 그림을 저장할 2차원 배열 (R, G, B)

int visRG[101][101];   // 적록색약용 방문 배열
int visNRG[101][101];  // 정상인용 방문 배열

// 상, 우, 하, 좌 탐색 방향
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

queue<pair<int,int>> qRG;   // 적록색약용 BFS 큐
queue<pair<int,int>> qNRG;  // 정상인용 BFS 큐

int main(){
    int n;
    int resRG = 0;   // 적록색약 영역 개수
    int resNRG = 0;  // 정상인 영역 개수
    cin >> n;
    
    // 그림 입력 받기
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            board[i][j] = s[j];
        }
    }

    // 정상인 경우
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visNRG[i][j] == 0){ // 아직 방문하지 않은 칸이면
                resNRG++; // 새로운 구역 발견
                qNRG.push({i, j}); // BFS 시작
                visNRG[i][j] = 1;
                while(!qNRG.empty()){
                    pair<int,int> cur = qNRG.front();
                    qNRG.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        // 보드 범위 벗어나면 무시
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        // 이미 방문한 칸이면 무시
                        if(visNRG[ny][nx] == 1)
                            continue;
                        // 같은 색깔이면 같은 구역으로 연결
                        if(board[i][j] == board[ny][nx]){
                            qNRG.push({ny, nx});
                            visNRG[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }


    // 적록색약인 경우
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visRG[i][j] == 0){ // 아직 방문하지 않은 칸이면
                resRG++; // 새로운 구역 발견
                qRG.push({i,j}); // BFS 시작
                visRG[i][j] = 1;
                while(!qRG.empty()){
                    pair<int,int> cur = qRG.front();
                    qRG.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        // 보드 범위 벗어나면 무시
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        // 이미 방문한 칸이면 무시
                        if(visRG[ny][nx] == 1)
                            continue;
                        // 적록색약은 'R'과 'G'를 같은 색으로 인식
                        if(board[i][j] == 'B' && board[ny][nx] == 'B'){
                            qRG.push({ny, nx});
                            visRG[ny][nx] = 1;
                        }
                        else if((board[i][j] == 'R' || board[i][j] == 'G') && (board[ny][nx] == 'R' || board[ny][nx] == 'G')){
                            qRG.push({ny, nx});
                            visRG[ny][nx] = 1;
                        }
                    }
                } 
            }
        }
    }

    // 결과 출력: 정상인 구역 수, 적록색약 구역 수
    cout << resNRG << " " << resRG;
}
