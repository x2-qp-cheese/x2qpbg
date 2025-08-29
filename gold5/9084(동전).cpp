#include <bits/stdc++.h>
using namespace std;

int coin[21];       // 사용할 수 있는 동전의 금액을 저장하는 배열 (최대 20개)
int dp[10001];      // dp[i] = 금액 i를 만드는 방법의 수

int main(){
    int T, n, target;
    cin >> T; // 테스트 케이스 개수 입력

    for(int i = 0; i < T; i++){ // 각 테스트 케이스에 대해 반복
        memset(dp, 0, sizeof(dp)); // dp 배열 초기화 (모든 값을 0으로 설정)
        dp[0] = 1; // 금액 0을 만드는 방법은 '아무 동전도 사용하지 않는 경우' 한 가지

        cin >> n; // 동전의 종류 개수 입력
        for(int j = 0; j < n; j++){
            cin >> coin[j]; // 각 동전의 금액 입력
        }

        cin >> target; // 목표 금액 입력

        // 각 동전을 하나씩 사용하여 dp 배열 업데이트
        for (int k = 0; k < n; k++) { // 동전 종류마다 반복
            for (int j = coin[k]; j <= target; j++) { // coin[k]부터 target까지
                dp[j] += dp[j - coin[k]]; // 현재 금액 j를 만드는 방법 += (j - coin[k])을 만드는 방법의 수
            }
        }

        cout << dp[target] << endl; // 목표 금액을 만드는 모든 방법의 수 출력
    }
}
