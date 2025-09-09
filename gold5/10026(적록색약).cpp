#include <bits/stdc++.h>
using namespace std;

char board[101][101];

int visRG[101][101];
int visNRG[101][101];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

queue<pair<int,int>> qRG;
queue<pair<int,int>> qNRG;

int main(){
    int n;
    int resRG = 0;
    int resNRG = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            board[i][j] = s[j];
        }
    }
    //정상인 경우
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visNRG[i][j] == 0){
                resNRG++;
                qNRG.push({i, j});
                visNRG[i][j] = 1;
                while(!qNRG.empty()){
                    pair<int,int> cur = qNRG.front();
                    qNRG.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        if(visNRG[ny][nx] == 1)
                            continue;
                        if(board[i][j] == board[ny][nx]){
                            qNRG.push({ny, nx});
                            visNRG[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }


    //적록색약인 경우
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visRG[i][j] == 0){
                resRG++;
                qRG.push({i,j});
                visRG[i][j] = 1;
                while(!qRG.empty()){
                    pair<int,int> cur = qRG.front();
                    qRG.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        if(visRG[ny][nx] == 1)
                            continue;
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
    cout << resNRG << " " << resRG;
}