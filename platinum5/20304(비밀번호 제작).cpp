#include <bits/stdc++.h>
using namespace std;

int visited[1000001];
int n;

// 가져온 num과 안전 거리가 1.. 2... 3.. 인 숫자들을 기록
void bfs(int num){
    // (현재 숫자, 거리)를 저장하는 BFS 큐
    queue<pair<int, int>> q;

    q.push({num, 1});         // 시작 숫자와 거리 1로 기록
    visited[num] = 1;         // 스스로는 안전거리가 0이므로 1로 저장(나중에 -1 해줌)

    while(!q.empty()){
        pair<int, int> cur = q.front(); 
        q.pop();

        int cur_num = cur.first;   // 현재 숫자
        int dist = cur.second;     // 현재까지의 거리

        // i는 XOR 할 비트(1, 2, 4, 8, ...)
        // 비트 하나만 뒤집은 모든 숫자를 탐색
        for(int i = 1; i <= n; i*=2){
            int nxt = cur_num ^ i; // 해당 비트를 토글한 다음 숫자

            if(nxt > n) continue;  // 범위를 넘으면 무시

            // 아직 방문 X 이거나 더 짧은 거리로 갱신 가능할 때
            if(visited[nxt] == 0 || visited[nxt] > dist + 1){
                visited[nxt] = dist + 1;   // 거리 기록
                q.push({nxt, dist + 1});   // 다음 탐색
            }
        }
    }
}

int main(){
    cin >> n;          // 가능한 비밀번호 최대값
    int m; cin >> m;   // 훔친 비밀번호 개수

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        bfs(num);      // 각각의 훔친 비밀번호로 BFS 돌림
    }

    int res = 0;

    // 0 ~ n 중 가장 큰 안전거리 찾기
    for(int i = 0; i <= n; i++){
        res = max(visited[i], res);
    }

    cout << res - 1;   // BFS 시작을 1로 잡았으므로 -1 해서 출력
}
