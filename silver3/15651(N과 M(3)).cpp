#include <bits/stdc++.h>
using namespace std;

// n : 1부터 n까지의 자연수
// m : 수열의 길이
int n, m;

// 현재 만들고 있는 수열을 저장하는 배열
int arr[10];

// 백트래킹 함수
// len : 현재까지 선택한 숫자의 개수 (수열의 길이)
void backtrack(int len){
    // 수열의 길이가 m이 되면 출력
    if(len == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    // 1부터 n까지의 숫자를 현재 위치에 넣어봄
    for(int i = 1; i <= n; i++){
        // 현재 위치에 숫자 i 저장
        arr[len] = i;

        // 다음 위치로 재귀 호출
        backtrack(len + 1);
    }
}

int main(){
    // n과 m 입력
    cin >> n >> m;

    // 백트래킹 시작 (아직 아무 숫자도 선택하지 않은 상태)
    backtrack(0);
}
