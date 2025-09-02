#include <bits/stdc++.h>
using namespace std;

int daysNeeded[1001]; // 각 문제를 푸는 데 필요한 일수
int fineTopay[1001];  // 각 문제를 늦게 제출했을 때의 벌금
int dp[1001][1001];   // dp[i][j]는 i번째 문제까지 고려했을 때 j일의 남은 기한으로 얻을 수 있는 최소 벌금

int main(){
    int n; // 문제의 개수
    int t; // 남은 제출 기한
    cin >> n >> t;
    
    int totalFine = 0; // 총 벌금 초기화

    // 각 문제의 풀이에 필요한 일수와 벌금을 입력받고, 총 벌금을 계산
    for(int i = 1; i <= n; i++){
        cin >> daysNeeded[i] >> fineTopay[i];
        totalFine += fineTopay[i]; // 모든 문제의 벌금을 더함
    }  

    // DP 테이블 초기화
    for(int i = 0; i <= n; i++){
        dp[i][0] = totalFine;  // 기한이 0일이면 모든 문제에 대해 최악의 벌금이 부과됨
    }
    for(int j = 0; j <= t; j++){
        dp[0][j] = totalFine;  // 문제를 하나도 풀지 못한 경우, 벌금은 모두 부과됨
    }

    // DP 계산
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            if(daysNeeded[i] <= j){  // i번째 문제를 풀 수 있는 기한이 남았다면
                // 현재 문제를 푼 경우와 안 푼 경우를 비교하여 최소 벌금을 선택
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-daysNeeded[i]] - fineTopay[i]);
            }
            else{  // i번째 문제를 풀 수 없으면 이전 상태를 그대로 가져옴
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // 남은 기한 t일로 문제 n개를 해결했을 때의 최소 벌금 출력
    cout << dp[n][t];
}
