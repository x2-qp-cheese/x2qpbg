#include <bits/stdc++.h>
using namespace std;
 
char building[31][31][31];
int vis[31][31][31];
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    int l, r, c;
    int ez, ey, ex;
    queue<tuple<int,int,int>> q;
    while(1){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0){
            break;
        }
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                string s;
                cin >> s;
                for(int k = 0; k < c; k++){
                    building[i][j][k] = s[k];
                    if(s[k] == '.')
                        vis[i][j][k] = -1;
                    else if(s[k] == 'S'){
                        vis[i][j][k] = 1;
                        q.push({i,j,k});
                    }
                    else if(s[k] == 'E'){
                        ez = i;
                        ey = j;
                        ex = k;
                        vis[i][j][k] = -1;
                    }
                    else
                        vis[i][j][k] = 0;    
                }
            }
        }
        while(!q.empty()){
            auto [z, y, x] = q.front();
            q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nz = z + dz[dir];
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(nz < 0 || nz >= l) continue;
                if(ny < 0 || ny >= r) continue;
                if(nx < 0 || nx >= c) continue;
                if(vis[nz][ny][nx] >= 0) continue;
                q.push({nz, ny, nx});
                vis[nz][ny][nx] = vis[z][y][x] + 1;
            }
        }
        if(vis[ez][ey][ex] == -1){
            cout << "Trapped!" << endl;
        }
        else{
            cout << "Escaped in " << vis[ez][ey][ex]-1 <<" minute(s)." << endl;
        }
    }
    return 0;
}