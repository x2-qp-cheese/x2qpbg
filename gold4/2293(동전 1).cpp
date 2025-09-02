#include <bits/stdc++.h>
using namespace std;

int dp[10001];  // dp[i]는 i 금액을 만들 수 있는 방법의 수

int main(){
    int n;  // 동전의 개수
    int k;  // 목표 금액
    cin >> n >> k;  // 동전의 개수 n과 목표 금액 k 입력받기
    
    dp[0] = 1;  // 0 금액을 만드는 방법은 1가지 (동전을 하나도 사용하지 않는 경우)

    // 동전의 값을 입력받고 DP 배열 갱신
    for(int i = 0; i < n; i++){
        int coin;  
        cin >> coin;  // 동전 한 종류의 값을 입력받기
        for(int j = coin; j <= k; j++){  // 금액 j가 coin 이상일 때만 갱신
            dp[j] += dp[j - coin];  // 현재 금액 j를 만들 수 있는 방법은 dp[j - coin]을 이용하여 구함
        }
    }

    // dp[k]에는 목표 금액 k를 만들 수 있는 방법의 수가 저장됨
    cout << dp[k];
}
