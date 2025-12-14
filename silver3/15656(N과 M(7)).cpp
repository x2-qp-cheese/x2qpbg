#include <bits/stdc++.h>
using namespace std;

int n, m;        // n: 입력된 숫자의 개수, m: 수열의 길이
int arr[10];    // 입력으로 주어진 n개의 숫자 배열
int res[10];    // 현재 만들고 있는 길이 m짜리 수열

// len : 현재까지 선택한 숫자의 개수
void backtrack(int len){
    // 길이가 m이 되면 하나의 수열 완성
    if(len == m){
        // 완성된 수열 출력
        for(int i = 0; i < len; i++)
            cout << res[i] << " ";
        cout << "\n";
        return; // 더 이상 재귀 호출하지 않음
    }

    // arr에 있는 n개의 숫자 중 하나를 선택
    // 같은 숫자를 여러 번 선택할 수 있음 (중복 허용)
    for(int i = 0; i < n; i++){
        res[len] = arr[i];   // 현재 위치에 숫자 저장
        backtrack(len + 1);  // 다음 위치로 재귀 호출
    }

    return; // 함수 종료 (생략 가능)
}

int main(){
    cin >> n >> m;           // n과 m 입력

    // n개의 숫자 입력
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);     // 사전순 출력을 위한 정렬

    backtrack(0);           // 아직 아무 숫자도 선택하지 않은 상태에서 시작
}