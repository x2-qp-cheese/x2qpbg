#include <bits/stdc++.h>
using namespace std;

int n, m;        // n: 입력된 숫자의 개수, m: 선택할 수열의 길이
int arr[10];    // 입력으로 주어진 n개의 숫자 배열
int res[10];    // 현재 선택한 길이 m짜리 조합을 저장하는 배열

// idx : 다음에 선택할 수 있는 시작 인덱스
// len : 현재까지 선택한 숫자의 개수
void backtrack(int idx, int len){
    // m개를 모두 선택했으면 하나의 조합 완성
    if(len == m){
        // 완성된 조합 출력
        for(int i = 0; i < m; i++)
            cout << res[i] << " ";
        cout << "\n";
        return; // 더 이상 재귀하지 않음
    }

    // idx부터 n-1까지 숫자를 하나씩 선택
    // 이전에 선택한 인덱스보다 뒤쪽만 사용 → 중복 없이 오름차순 조합
    for(int i = idx; i < n; i++){
        res[len] = arr[i];        // 현재 위치에 숫자 저장
        backtrack(i + 1, len + 1); // 다음 인덱스부터 선택
    }

    return; // 함수 종료 (생략 가능)
}

int main(){
    cin >> n >> m;        // n과 m 입력

    // n개의 숫자 입력
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);  // 사전순(오름차순) 출력을 위한 정렬

    backtrack(0, 0);     // 0번 인덱스부터, 아직 아무 것도 선택하지 않은 상태
}
