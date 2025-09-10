#include <bits/stdc++.h>
using namespace std;

int vis[100001];  // 방문 여부 체크 배열
int bef[100001];  // 직전 위치를 저장하는 배열 (경로 복원용)

queue<pair<int, int>> q; // BFS 큐: {현재 위치, 걸린 시간}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; // N: 수빈이 시작 위치, K: 동생 위치
    cin >> N >> K;

    // 시작 지점 초기화
    q.push({N, 0});  // 시작 위치와 시간(0)
    vis[N] = 1;      // 방문 처리
    bef[N] = -1;     // 시작 지점은 이전 노드가 없음(-1로 표시)

    // BFS 탐색
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int pos = cur.first; // 현재 위치
        int sec = cur.second; // 걸린 시간

        // 목표 지점에 도착하면 탐색 종료
        if(pos == K){
            cout << sec << endl; // 최단 시간 출력
            break;
        }

        // 순간이동 (pos → 2*pos, 시간 +1)
        if(2*pos <= 100000 && vis[2*pos] == 0){
            q.push({pos * 2, sec + 1});
            vis[2*pos] = 1;
            bef[2*pos] = pos; // 경로 추적을 위해 이전 위치 저장
        }

        // 한 칸 뒤로 이동 (pos → pos-1, 시간 +1)
        if(pos-1 >= 0 && vis[pos-1] == 0){
            q.push({pos - 1, sec + 1});
            vis[pos-1] = 1;
            bef[pos-1] = pos; // 이전 위치 저장
        }

        // 한 칸 앞으로 이동 (pos → pos+1, 시간 +1)
        if(pos+1 <= 100000 && vis[pos+1] == 0){
            q.push({pos + 1, sec + 1});
            vis[pos+1] = 1;
            bef[pos+1] = pos; // 이전 위치 저장
        }
    }
    
    // ---- 경로 복원 ----
    vector<int> res;
    int cur = K;
    // 도착 지점 K에서 시작해서 역으로 추적 (bef 배열 이용)
    while(cur != -1){
        res.push_back(cur);
        cur = bef[cur];
    }

    // 경로는 역순으로 저장되어 있으므로 뒤집어서 출력
    for(int i = res.size()-1; i >= 0; i--){
        cout << res[i] << " ";
    }
}