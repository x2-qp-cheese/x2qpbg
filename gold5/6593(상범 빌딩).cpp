#include <bits/stdc++.h>
using namespace std;
 
char building[31][31][31]; // 빌딩 구조 ('.', '#', 'S', 'E')
int vis[31][31][31];       // 방문 및 시간 기록 배열

// 6방향 이동: 동, 서, 남, 북, 상, 하
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    int l, r, c;        // l: 층 수, r: 행, c: 열
    int ez, ey, ex;     // 출구 좌표
    queue<tuple<int,int,int>> q; // BFS 큐: {z, y, x}

    while(1){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0){ // 입력 종료 조건
            break;
        }

        // 빌딩 입력 받기
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                string s;
                cin >> s;
                for(int k = 0; k < c; k++){
                    building[i][j][k] = s[k];
                    
                    if(s[k] == '.'){ 
                        // 빈 공간: 아직 방문하지 않음 (-1로 표시)
                        vis[i][j][k] = -1;
                    }
                    else if(s[k] == 'S'){
                        // 시작 지점
                        vis[i][j][k] = 1;   // 시작은 1분부터 (출력 시 -1 해줌)
                        q.push({i,j,k});    // BFS 시작점 삽입
                    }
                    else if(s[k] == 'E'){
                        // 출구 지점
                        ez = i;
                        ey = j;
                        ex = k;
                        vis[i][j][k] = -1; // 방문하지 않은 상태
                    }
                    else{
                        // 벽('#'): 방문 불가 (0으로 표시)
                        vis[i][j][k] = 0;    
                    }
                }
            }
        }

        // BFS 탐색
        while(!q.empty()){
            auto [z, y, x] = q.front();
            q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nz = z + dz[dir];
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                // 빌딩 범위 벗어나면 무시
                if(nz < 0 || nz >= l) continue;
                if(ny < 0 || ny >= r) continue;
                if(nx < 0 || nx >= c) continue;
                // 이미 방문했거나 벽이라면 무시
                if(vis[nz][ny][nx] >= 0) continue;

                // 이동 가능한 칸이면 큐에 삽입
                q.push({nz, ny, nx});
                vis[nz][ny][nx] = vis[z][y][x] + 1; // 시간 갱신
            }
        }

        // 결과 출력
        if(vis[ez][ey][ex] == -1){
            cout << "Trapped!" << endl; // 출구에 도달 못함
        }
        else{
            cout << "Escaped in " << vis[ez][ey][ex]-1 <<" minute(s)." << endl;
        }
    }
    return 0;
}