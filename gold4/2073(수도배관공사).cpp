#include <bits/stdc++.h>
using namespace std;

int l[351]; // 파이프의 길이
int c[351]; // 파이프의 용량(최대 물 흐름)
int dp[100001]; // dp[x] : 길이 x까지 물을 끌어올 수 있을 때의 최대 최소 용량

int main(){
    int d, p; 
    // d : 강까지의 거리
    // p : 구입 가능한 파이프의 개수

    cin >> d >> p;

    for(int i = 1; i <= p; i++){
        cin >> l[i] >> c[i]; // 각 파이프의 길이와 용량 입력
    }

    memset(dp, -1, sizeof(dp)); // 초기화 (도달 불가능한 경우 -1)

    dp[0] = INT_MAX; // 길이가 0일 때는 제한이 없음 (무한대 용량으로 시작)

    // 파이프 선택을 통해 목표 거리 d를 채우는 과정
    for(int i = 1; i <= p; i++){ // i번째 파이프 고려
        for(int j = d; j >= l[i]; j--){ // 뒤에서부터 채워야 중복 사용 방지
            if(dp[j-l[i]] != -1){ // j-l[i] 거리까지 올 수 있는 경우에만
                // 새로운 경우의 용량 = 이전 용량과 현재 파이프 용량의 최소값
                // dp[j]에는 가능한 경우 중 최대 용량을 저장
                dp[j] = max(dp[j], min(dp[j-l[i]], c[i]));
            }
        } 
    }
    cout << dp[d]; // d 거리까지 도달할 수 있는 경우의 최대 최소 용량 출력
}
