#include <bits/stdc++.h>
using namespace std;

#define MAX 1500001 // 최대 날짜 수 (문제 조건에 맞게 넉넉하게 설정)

int timeNeeded[MAX];  // 상담을 하는 데 필요한 기간
int priceNeeded[MAX]; // 상담을 하면 얻는 수익
int dp[MAX];          // dp[i]: i번째 날까지 얻을 수 있는 최대 수익

int main(){
    int n; // 전체 날짜 수
    cin >> n;

    // 각 날짜별 상담 기간과 수익 입력
    for(int i = 1; i <= n; i++){
        cin >> timeNeeded[i] >> priceNeeded[i];
    }

    // 1일부터 n일까지 확인
    for(int i = 1; i <= n; i++){
        // (1) 오늘 상담을 하지 않는 경우 → 이전까지의 최대값을 그대로 가져옴
        dp[i] = max(dp[i], dp[i-1]);

        // (2) 오늘 상담을 하는 경우 → 끝나는 날(i + timeNeeded[i])에 수익 반영
        if(i + timeNeeded[i] <= n+1){
            dp[i+timeNeeded[i]] = max(dp[i] + priceNeeded[i], dp[i+timeNeeded[i]]);
        }
    }

    // 마지막 날(n+1)에도 최대값을 반영 (마지막 상담이 딱 끝나는 경우 처리)
    dp[n+1] = max(dp[n+1], dp[n]);

    cout << dp[n+1];
}