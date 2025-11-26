#include <bits/stdc++.h> // 대부분의 표준 라이브러리를 포함 (iostream, vector 등)
using namespace std; // std:: 네임스페이스 사용 선언

// 인접 리스트(Adjacency List)로 그래프를 표현
// linked[i]는 i번 노드와 연결된 노드들의 리스트를 저장
vector<int> linked[101]; 
// 방문 여부를 체크하는 배열. chk[i]가 true면 i번 노드는 방문했음을 의미
bool chk[101];
// 1번 컴퓨터를 통해 감염된(방문한) 컴퓨터의 수 (1번 컴퓨터는 제외)
int cnt; 

// 깊이 우선 탐색(DFS) 함수
// x: 현재 탐색 중인 노드의 번호
void dfs(int x){
    // 현재 노드를 방문했다고 표시
    chk[x] = true; 

    // 현재 노드(x)와 연결된 모든 노드를 순회
    for(int i = 0; i < linked[x].size(); i++){
        // next_node: 현재 노드 x와 연결된 다음 노드
        int next_node = linked[x][i]; 
        
        // 만약 다음 노드를 아직 방문하지 않았다면
        if(!chk[next_node]){
            // 다음 노드를 방문했다고 표시
            // (이 줄은 사실상 아래의 재귀 호출을 통해 수행되지만, 코드가 이중으로 방문 체크를 하고 있음)
            // 깊이 우선 탐색의 일반적인 구현에서는 이 줄(chk[linked[x][i]] = true;)은 생략하거나
            // 아니면 for문 바깥의 chk[x] = true; 와 같은 위치에 놓는 것이 더 명확합니다.
            // 여기서는 코드의 원형을 유지합니다.
            chk[next_node] = true; 
            
            // 다음 노드부터 다시 DFS를 수행 (재귀 호출)
            dfs(next_node);
            
            // 재귀 호출이 끝난 후, 즉 연결된 컴퓨터 하나를 발견하고 그 서브트리까지 모두 탐색 완료 후
            // 감염된 컴퓨터의 수(cnt)를 1 증가시킴.
            cnt++; 
        }
    }
}

// 메인 함수
int main(){
    // n: 컴퓨터(노드)의 수 (1부터 n까지)
    // m: 연결된 쌍(간선)의 수
    int n, m;
    
    // n과 m 입력 받기
    cin >> n >> m;
    
    // m개의 연결 정보(간선) 입력 받기
    for(int i = 0; i < m; i++){
        int frm, to; // 연결된 두 컴퓨터 번호
        cin >> frm >> to;
        
        // 양방향 그래프이므로, 두 컴퓨터 모두에게 연결 정보를 추가
        // frm과 to를 연결
        linked[frm].push_back(to);
        // to와 frm을 연결
        linked[to].push_back(frm);
    }
    
    // 1번 컴퓨터부터 DFS 탐색 시작 (바이러스는 1번 컴퓨터를 통해 전파)
    dfs(1);
    
    // 1번 컴퓨터를 통해 연결된(감염된) 컴퓨터의 수(cnt)를 출력
    // cnt에는 1번 컴퓨터는 포함되지 않음
    cout << cnt;
    
    // 프로그램 종료
    return 0;
}