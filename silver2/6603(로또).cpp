#include <bits/stdc++.h>
using namespace std;

// 입력으로 주어지는 k개의 숫자
int arr[15];

// 선택된 6개의 로또 번호를 저장
int lotto[6];

// 숫자의 개수
int k;

// 백트래킹 함수
// idx : 다음에 선택할 수 있는 시작 인덱스
// len : 현재까지 선택한 숫자의 개수
void backtrack(int idx, int len){
    // 숫자 6개를 모두 선택했으면 출력
    if(len == 6){
        for(int i = 0; i < 6; i++){
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }

    // idx부터 k-1까지 숫자를 하나씩 선택
    for(int i = idx; i < k; i++){
        // 현재 숫자를 로또 배열에 저장
        lotto[len] = arr[i];

        // 다음 숫자는 i+1부터 선택하여
        // 중복 선택 및 순서 뒤바뀜 방지
        backtrack(i + 1, len + 1);
    }
    return;
}

int main(){
    // 여러 테스트 케이스 처리
    while(true){
        // 숫자의 개수 입력
        cin >> k;

        // k가 0이면 종료
        if(k == 0) break;

        // k개의 숫자 입력
        for(int i = 0; i < k; i++){
            cin >> arr[i];
        }

        // 백트래킹 시작
        backtrack(0, 0);

        // 각 테스트 케이스 사이에 빈 줄 출력
        cout << "\n";
    }
}