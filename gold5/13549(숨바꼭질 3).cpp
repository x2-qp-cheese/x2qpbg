#include <bits/stdc++.h>
using namespace std;

int vis[100001]; // 방문 체크 배열 (중복 방문 방지)

// 큐에는 {현재 위치, 걸린 시간} 저장
queue<pair<int, int>> q; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; // N: 수빈이 위치, K: 동생 위치
    cin >> N >> K;

    // 시작 위치 큐에 삽입
    q.push({N, 0}); // {현재 위치, 걸린 시간}
    vis[N] = 1;     // 시작 위치 방문 처리

    // BFS 시작
    while(!q.empty()){
        pair<int, int> cur = q.front(); // 큐의 맨 앞 원소
        q.pop();
        int pos = cur.first; // 현재 위치
        int sec = cur.second; // 지금까지 걸린 시간

        // 목표 위치 도달하면 정답 출력 후 종료
        if(pos == K){
            cout << sec << endl;
            break;
        }

        // 순간이동 (pos → 2*pos, 시간 추가 없음)
        if(2*pos <= 100000 && vis[2*pos] == 0){
            q.push({pos * 2, sec}); // 시간 증가 없음
            vis[2*pos] = 1;
        }

        // 한 칸 뒤로 이동 (pos → pos-1, 시간 +1)
        if(pos-1 >= 0 && vis[pos-1] == 0){
            q.push({pos - 1, sec + 1});
            vis[pos-1] = 1;
        }

        // 한 칸 앞으로 이동 (pos → pos+1, 시간 +1)
        if(pos+1 <= 100000 && vis[pos+1] == 0){
            q.push({pos + 1, sec + 1});
            vis[pos+1] = 1;
        }
    }
}
