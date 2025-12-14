#include <bits/stdc++.h>
using namespace std;

// 숫자가 이미 사용되었는지 체크하는 배열
bool isused[10];

// n: 1부터 n까지의 숫자
// m: 뽑을 개수
int n, m;

// 현재 선택된 수열을 저장하는 배열
int res[10];

// 백트래킹 함수
// idx: 현재 수열에서 채울 위치
void backtrack(int idx){
    // m개를 모두 선택했으면 출력
    if(idx == m){
        for(int i = 0; i < m; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 1부터 n까지의 숫자를 하나씩 시도
    for(int i = 1; i <= n; i++){
        // 이미 사용한 숫자라면 건너뜀
        if(isused[i]) continue;

        // 숫자 i 사용 처리
        isused[i] = true;
        res[idx] = i;

        // 다음 위치로 재귀 호출
        backtrack(idx+1);

        // 사용 해제 (백트래킹)
        isused[i] = false;
    }
    return;
}

int main(){
    // n과 m 입력
    cin >> n >> m;

    // 백트래킹 시작 (0번째 위치부터)
    backtrack(0);
    return 0;
}
