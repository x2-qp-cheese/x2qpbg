#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int pos[100005]; // 각 위치에 도달하는 최단 시간을 기록 (0은 미방문)
int n, k, result; // n: 시작, k: 목표, result: 최단 경로 방법의 수
queue<int> q;

void userInput(){
    cin >> n >> k;
    
    // 시작점과 목표점이 같은 경우 예외 처리
    if (n == k) {
        pos[n] = 1;
        result = 1;
        return;
    }
    
    pos[n] = 1; // 시작 위치 방문 표시 (시간 계산을 위해 1부터 시작)
    q.push(n);
}

void solve(){
    // 시작점과 목표점이 같으면 결과를 바로 출력하고 종료
    if(n == k){
        cout << 0 << "\n" << 1;
        return;
    }

    while(!q.empty()){
        int curpos = q.front(); q.pop();

        // 이미 k에 도달한 최단 시간보다 현재 탐색 시간이 크거나 같으면 더 이상 탐색 불필요
        if (pos[k] != 0 && pos[curpos] >= pos[k]) continue;

        // 이동 가능한 3가지 경우의 수
        int next_steps[3] = {curpos * 2, curpos + 1, curpos - 1};

        for (int i = 0; i < 3; i++) {
            int next = next_steps[i];

            // 범위를 벗어나지 않는지 확인
            if (next >= 0 && next <= MAX) {
                // 1. 처음 방문하는 위치인 경우 (최단 거리 발견)
                if (pos[next] == 0) {
                    pos[next] = pos[curpos] + 1;
                    q.push(next);
                    
                    // 목표점에 처음 도달했다면 방법의 수를 1로 초기화
                    if (next == k) result = 1;
                }
                // 2. 이미 방문한 위치지만, 현재 탐색 경로가 기존 최단 시간과 일치하는 경우
                else if (pos[next] == pos[curpos] + 1) {
                    // 목표점에 도달하는 또 다른 최단 경로를 찾은 경우 결과 카운트 증가
                    if (next == k) result++;
                    
                    // k가 아닌 다른 지점이더라도 최단 시간 내의 다른 경로라면 큐에 넣어 계속 탐색
                    q.push(next);
                }
            }
        }
    }
    
    // pos[n]을 1로 시작했으므로 출력 시 1을 빼줌
    cout << pos[k] - 1 << "\n";
    cout << result;
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    userInput();
    solve();
    return 0;
}