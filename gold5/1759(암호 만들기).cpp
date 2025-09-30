#include <bits/stdc++.h>
using namespace std;

char arr[16];          // 입력받은 알파벳 후보
vector<char> res;      // 현재 선택된 암호 조합
int l, c;              // l: 암호 길이, c: 알파벳 개수

// 백트래킹 함수
// st: 시작 인덱스, cnt: 현재 선택된 글자 수
// concnt: 현재까지 선택된 자음 수, vocnt: 현재까지 선택된 모음 수
void backtrack(int st, int cnt, int concnt, int vocnt){
    if(cnt == l ){ // l개의 글자를 모두 선택한 경우
        if(concnt >= 2 && vocnt >= 1){ // 조건: 최소 자음 2개, 모음 1개
            for(int i = 0; i < l; i++)
                cout << res[i]; // 현재 조합 출력
            cout << endl;
        }
        return;
    }

    // 남은 알파벳 후보에서 글자 선택
    for(int i = st; i < c; i++){
        res.push_back(arr[i]); // 글자 선택
        // 모음인지 확인
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            backtrack(i+1, cnt+1, concnt, vocnt+1); // 모음이면 vocnt 증가
        else
            backtrack(i+1, cnt+1, concnt+1, vocnt); // 자음이면 concnt 증가
        res.pop_back(); // 선택 취소 (백트래킹)
    }
}

int main(){
    cin >> l >> c; // 암호 길이와 알파벳 개수 입력
    for(int i = 0; i < c; i++)
        cin >> arr[i]; // 알파벳 입력
    sort(arr, arr+c); // 사전순 정렬
    backtrack(0, 0, 0, 0); // 백트래킹 시작
}