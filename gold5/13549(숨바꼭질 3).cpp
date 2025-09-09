#include <bits/stdc++.h>
using namespace std;

int vis[100001];

queue<pair<int, int>> q; // 위치

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    q.push({N, 0});
    vis[N] = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int pos = cur.first;
        int sec = cur.second;
        if(pos == K){
            cout << sec << endl;
            break;
        }
        if(2*pos <= 100000 && vis[2*pos] == 0){
            q.push({pos * 2, sec});
            vis[2*pos] = 1;
        }
        if(pos-1 >= 0 && vis[pos-1] == 0){
            q.push({pos - 1, sec + 1});
            vis[pos-1] = 1;;
        }
        if(pos+1 <= 100000 && vis[pos+1] == 0){
            q.push({pos + 1, sec + 1});
            vis[pos+1] = 1;
        }
    }
}