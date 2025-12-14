#include <bits/stdc++.h>
using namespace std;

// n : 1부터 n까지의 자연수
// m : 선택할 숫자의 개수
int n, m;

// 현재 선택된 수열(조합)을 저장하는 배열
int arr[10];

// 백트래킹 함수
// num : 다음에 선택할 수 있는 최소 숫자
// len : 현재까지 선택한 숫자의 개수
void backtrack(int num, int len){
    // m개를 모두 선택했으면 출력
    if(len == m){
        for(int i = 0; i < len; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // num부터 n까지 숫자를 하나씩 선택
    // 이전에 선택한 숫자보다 큰 값만 선택하여
    // 중복과 순서 뒤바뀜을 방지
    for(int i = num; i <= n; i++){
        // 현재 숫자를 선택
        arr[len] = i;

        // 다음 숫자는 i+1부터 선택
        backtrack(i + 1, len + 1);
    }
}

int main(){
    // n과 m 입력
    cin >> n >> m;

    // 백트래킹 시작 (1부터 선택)
    backtrack(1, 0);
}