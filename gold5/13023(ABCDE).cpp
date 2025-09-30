#include <bits/stdc++.h>
using namespace std;

int arr[2001];              // 방문 여부 체크용 배열
vector<int> fnd[2001];      // 각 노드와 연결된 친구(간선) 정보 저장

// 깊이 우선 탐색(DFS) 함수
int dfs(int n, int cnt){
    if(cnt == 5){           // 깊이가 5(즉, A-B-C-D-E 관계)라면 조건 충족
        return 1;
    }
    for(int i = 0; i < (int)fnd[n].size(); i++){   // 현재 노드와 연결된 모든 노드 탐색
        if(arr[fnd[n][i]] == 1) continue;          // 이미 방문한 노드는 건너뜀
        arr[fnd[n][i]] = 1;                        // 방문 처리
        if (dfs(fnd[n][i], cnt+1)) return 1;       // 재귀적으로 DFS 진행, 성공하면 즉시 반환
        arr[fnd[n][i]] = 0;                        // 탐색 후 방문 처리 해제(백트래킹)
    }
    return 0;   // 깊이 5에 도달하지 못한 경우
}

int main(){
    int n, m;
    cin >> n >> m;          // 정점 개수(n), 간선 개수(m) 입력
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;      // 친구 관계 입력
        fnd[a].push_back(b);
        fnd[b].push_back(a); // 양방향 그래프
    }

    // 모든 정점에서 DFS 시작 시도
    for(int i = 0; i < n; i++){
        arr[i] = 1;                         // 시작 노드 방문 처리
        if(dfs(i, 1) == 1){                 // DFS 시작, 깊이 카운트 1부터
            cout << 1;                      // 조건 충족 시 1 출력
            return 0;                       // 프로그램 종료
        }
        arr[i] = 0;                         // 방문 해제
    }
    cout << 0;   // 조건 만족하는 경우가 없으면 0 출력
    return 0;
}
