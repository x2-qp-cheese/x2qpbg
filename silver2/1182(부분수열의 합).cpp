#include <bits/stdc++.h>
using namespace std;

// n : 수열의 길이
// s : 목표 합
// res : 합이 s가 되는 부분수열의 개수
int n, s, res;

// 입력으로 주어지는 수열
int arr[21];

// 백트래킹 함수
// idx : 다음에 선택할 수 있는 시작 인덱스
// sum : 현재까지 선택한 원소들의 합
void backtrack(int idx, int sum){
    // 공집합을 제외하기 위해
    // 최소 하나 이상의 원소를 선택한 경우(idx > 0)만 체크
    // 현재 합이 목표 합 s와 같으면 개수 증가
    if(idx > 0 && sum == s) res++;

    // idx부터 n-1까지 원소를 하나씩 선택
    for(int i = idx; i < n; i++){
        // i번째 원소를 선택하고
        // 다음 원소는 i+1부터 탐색하여 중복 선택 방지
        backtrack(i + 1, sum + arr[i]);
    }
}

int main(){
    // n과 목표 합 s 입력
    cin >> n >> s;

    // 수열 입력
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 백트래킹 시작 (아직 아무 것도 선택하지 않은 상태)
    backtrack(0, 0);

    // 결과 출력
    cout << res;
}