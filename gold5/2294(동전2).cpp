#include <bits/stdc++.h>
using namespace std;

int dp[10001];  // dp[i]는 i 금액을 만들기 위한 최소 동전의 수

int main(){
    int n, k;
    cin >> n >> k;  // 동전의 개수 n과 목표 금액 k 입력받기
    fill(dp, dp+10001, 100001);  // dp 배열을 매우 큰 값(100001)으로 초기화, 이 값은 불가능한 금액을 의미
    dp[0] = 0;  // 0 금액을 만드는 데 필요한 동전의 수는 0

    // 동전 값 입력받고 DP 배열 갱신
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;  // 동전 한 종류의 값을 입력받기
        for(int j = coin; j <= k; j++){  // 금액 j가 coin 이상일 때만 업데이트
            dp[j] = min(dp[j-coin] + 1, dp[j]);  // dp[j-coin] + 1과 dp[j] 중 더 작은 값으로 갱신
        }
    }

    // dp[k]가 여전히 초기화된 값(100001)이라면 불가능한 경우 -1 출력
    if(dp[k] == 100001){
        cout << -1;
    }
    else{
        cout << dp[k];  // dp[k]는 목표 금액 k를 만들기 위한 최소 동전 수
    }
}
