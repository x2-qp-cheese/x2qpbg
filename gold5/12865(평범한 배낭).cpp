// 평범한 배낭
#include <bits/stdc++.h>
using namespace std;

int weight[101];      // 각 물건의 무게
int val[101];         // 각 물건의 가치

int dp[105][100005];  // dp[i][j] = i번째 물건까지 고려했을 때,
                      // 무게 j 이하에서 얻을 수 있는 최대 가치

int main(){
    int n, k; // n = 물건 개수, k = 배낭 최대 무게

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> weight[i]; // i번째 물건 무게
        cin >> val[i];    // i번째 물건 가치
    }

    // i = 현재 고려하는 물건 번호 (1 ~ n)
    // j = 현재 배낭의 허용 무게 (1 ~ k)
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= k; j++){
            // dp에는 현재 무게에서 가질 수 있는 최대 가치
            if(weight[i] <= j){
                // 물건 i를 담을 수 있는 경우:
                // ① 담지 않는다 → dp[i-1][j]
                // ② 담는다 → dp[i-1][j-weight[i]] + val[i]
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);
            }
            else{
                // 물건 i를 담을 수 없는 경우 → 이전 물건까지 고려한 값 그대로
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // n개의 물건까지 고려했을 때, 최대 무게 k에서 얻을 수 있는 최대 가치 출력
    cout << dp[n][k];
}