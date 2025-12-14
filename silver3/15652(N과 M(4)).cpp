#include <bits/stdc++.h>
using namespace std;

int n, m;        // n: 사용할 숫자의 최대값, m: 수열의 길이
int arr[10];    // 선택한 숫자를 저장할 배열

// num : 이번 위치에서 선택할 수 있는 최소 숫자
// len : 현재까지 선택한 숫자의 개수
void backtrack(int num, int len){
    // 수열의 길이가 m이 되면 하나 완성
    if(len == m){
        // 완성된 수열 출력
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return; // 더 이상 내려가지 않고 종료
    }

    // num부터 n까지 숫자를 선택
    // 이전에 고른 값 이상만 선택 → 비내림차순 유지 (중복 허용)
    for(int i = num; i <= n; i++){
        arr[len] = i;          // 현재 위치에 숫자 저장
        backtrack(i, len+1);   // 다음 위치로 재귀 호출
    }

    return; // 함수 종료 (사실 없어도 됨)
}

int main(){
    cin >> n >> m;     // n과 m 입력
    backtrack(1, 0);   // 1부터 시작, 아직 아무것도 선택 안 한 상태
}