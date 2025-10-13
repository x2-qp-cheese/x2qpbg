#include <bits/stdc++.h>
using namespace std;

int N, H; // N: 동굴 길이(입력되는 장애물 개수), H: 동굴의 높이
vector<int> tp, bt; // tp: 종유석(천장에서 자라는 돌), bt: 석순(바닥에서 자라는 돌)
int res[200001]; // (사용 안 함 — 결과 저장용 배열로 보이지만 현재는 불필요)

int main(){
    cin >> N >> H; // 장애물 개수(N), 동굴 높이(H) 입력

    // 장애물은 석순, 종유석이 번갈아 주어짐
    // N은 항상 짝수이므로 N/2 개씩 입력됨
    for(int i = 0; i < N / 2; i++){
        int tmpbt, tmptp;
        cin >> tmpbt >> tmptp; // 석순 높이, 종유석 길이 입력
        bt.push_back(tmpbt);
        tp.push_back(tmptp);
    }

    // 이분 탐색(lower_bound, upper_bound)을 위해 정렬
    sort(bt.begin(), bt.end());
    sort(tp.begin(), tp.end());

    int res = INT_MAX; // 최소 장애물 수를 저장할 변수
    int cnt = 0;       // 최소 장애물 구간(높이)의 개수

    // 동굴의 바닥부터 높이 H까지 모든 높이에 대해 검사
    for(int i = 1; i <= H; i++){
        // ─────────────────────────────────────────────
        // 석순 계산: 높이 i 이상인 석순의 개수
        // lower_bound(bt, i): i 이상인 첫 번째 석순의 인덱스
        // 따라서 전체 개수(N/2) - 그 인덱스 = i 이상인 석순의 수
        // ─────────────────────────────────────────────
        int btcnt = N / 2 - (lower_bound(bt.begin(), bt.end(), i) - bt.begin());

        // ─────────────────────────────────────────────
        // 종유석 계산: 높이 i에서 부딪히는 종유석의 개수
        // 종유석은 천장에서 자라므로 높이 H - i 이하인 종유석이 장애물이 됨
        // upper_bound(tp, H - i): H - i 초과인 첫 번째 인덱스 → 그 전까지는 충돌
        // 따라서 전체 개수(N/2) - upper_bound = i 높이에서 충돌하는 종유석 수
        // ─────────────────────────────────────────────
        int tpcnt = N / 2 - (upper_bound(tp.begin(), tp.end(), H - i) - tp.begin());

        // 현재 높이(i)에서의 총 장애물 수
        int tmpcnt = btcnt + tpcnt;

        // 최소 장애물 수 갱신
        if(tmpcnt < res){
            res = tmpcnt; // 더 작은 값 발견 시 갱신
            cnt = 1;      // 최소값 구간 개수 1로 초기화
        } 
        // 최소값과 같으면 개수 증가
        else if(tmpcnt == res){
            cnt++;
        }
    }

    // 결과 출력: 최소 장애물 수, 그러한 구간의 개수
    cout << res << " " << cnt;

    return 0;
}
