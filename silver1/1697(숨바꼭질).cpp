#include <bits/stdc++.h>
using namespace std;

int visited[100001];   // 각 위치까지 도달하는 데 걸린 시간을 저장하는 배열
queue<int> q;          // BFS 탐색을 위한 큐

int main(){
    int n, k;
    cin >> n >> k;     // n: 시작 위치, k: 목표 위치
    
    // visited 배열을 -1로 초기화 (아직 방문하지 않은 상태 의미)
    fill(visited, visited+100001, -1);
    
    visited[n] = 0;    // 시작 위치는 방문 시간 0
    q.push(n);         // BFS 시작점 큐에 넣기
    
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        
        // 목표 지점(k)에 도달하면 현재까지 걸린 시간 출력 후 종료
        if(cur == k){
            cout << visited[k];
            return 0;
        }
        
        // 1) 순간이동: 위치 * 2
        if(2*cur <= 100000 && visited[2*cur] < 0){
            visited[2*cur] = visited[cur] + 1; // 한 번의 이동이므로 +1
            q.push(2*cur);
        }

        // 2) +1 이동
        if(cur+1 <= 100000 && visited[cur+1] < 0){
            visited[cur+1] = visited[cur] + 1;
            q.push(cur+1);
        }

        // 3) -1 이동
        if(cur-1 >= 0 && visited[cur-1] < 0){
            visited[cur-1] = visited[cur] + 1;
            q.push(cur-1);
        }
    }    
}
