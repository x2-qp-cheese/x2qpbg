#include <bits/stdc++.h>
using namespace std;

pair<int, int> egg[10]; // egg[i].first : 내구도, egg[i].second : 무게
bool isbroken[10];     // 각 계란이 깨졌는지 여부
int result;            // 최대 깨진 계란 수
int n;                 // 계란 개수

// idx번째 계란을 들 차례, 현재까지 깨진 계란 수 = cnt
void backtrack(int idx, int cnt){
    // 모든 계란을 다 확인한 경우
    if(idx == n){
        result = max(result, cnt); // 최대값 갱신
        return;
    }

    // 현재 들고 있는 계란이 이미 깨져 있다면
    // 아무 것도 하지 않고 다음 계란으로 이동
    if(isbroken[idx]){
        backtrack(idx+1, cnt);
        return;
    }

    bool hit = false; // 이번 idx에서 실제로 계란을 쳤는지 여부

    // idx번째 계란으로 다른 계란들을 하나씩 쳐본다
    for(int i = 0; i < n; i++){
        if(i == idx) continue;   // 자기 자신은 칠 수 없음
        if(isbroken[i]) continue; // 이미 깨진 계란은 칠 수 없음

        hit = true;

        int tmpcnt = cnt;

        // 백트래킹을 위한 기존 상태 저장
        bool b1 = isbroken[idx];
        bool b2 = isbroken[i];

        // 서로 계란을 부딪힘
        egg[idx].first -= egg[i].second;
        egg[i].first -= egg[idx].second;

        // idx 계란이 깨졌는지 확인
        if(egg[idx].first <= 0 && !b1){
            isbroken[idx] = true;
            tmpcnt++;
        }

        // i 계란이 깨졌는지 확인
        if(egg[i].first <= 0 && !b2){
            isbroken[i] = true;
            tmpcnt++;
        }

        // 다음 계란으로 이동
        backtrack(idx+1, tmpcnt);

        // 상태 복구 (백트래킹)
        egg[idx].first += egg[i].second;
        egg[i].first += egg[idx].second;
        isbroken[idx] = b1;
        isbroken[i] = b2;
    }

    // 칠 수 있는 계란이 하나도 없었던 경우
    // 그냥 다음 계란으로 넘어감
    if(!hit) backtrack(idx+1, cnt);
}

int main(){
    cin >> n;

    // 각 계란의 내구도와 무게 입력
    for(int i = 0; i < n; i++){
        cin >> egg[i].first >> egg[i].second;
    }

    backtrack(0, 0); // 0번째 계란부터 시작
    cout << result;  // 최대 깨진 계란 수 출력
}
