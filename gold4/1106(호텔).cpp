#include <bits/stdc++.h>
using namespace std;

int customer[21]; // 각 도시에서 얻을 수 있는 고객 수
int val[21];      // 해당 고객 수를 얻기 위한 비용
int dp[1101];     // dp[j]: j명의 고객을 얻을 수 있는 최소 비용

int main() {
    int c, n;  // c: 목표 고객 수, n: 도시 수
    cin >> c >> n; // 목표 고객 수 c와 도시 수 n을 입력받음

    // dp 배열을 INT_MAX로 초기화 (불가능한 경우를 표시)
    fill(dp, dp + 1101, INT_MAX);
    dp[0] = 0;  // 고객 0명을 얻는 데 드는 비용은 0

    // 도시 정보 입력 (각 도시에서 얻을 수 있는 고객 수와 비용)
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> customer[i]; // val[i]: 비용, customer[i]: 고객 수
    }

    // 동적 계획법(DP) 수행
    for (int i = 0; i < n; i++) {  // 각 도시에서
        for (int j = 0; j <= 1100; j++) {  // 이미 계산된 고객 수에 대해 반복
            if (dp[j] != INT_MAX) {  // 만약 j명의 고객을 얻을 수 있다면
                int n_customer = j + customer[i];  // j명의 고객에 현재 도시에서 얻을 수 있는 고객 수를 더함
                int n_val = dp[j] + val[i];  // 기존 비용에 현재 도시에서 얻을 수 있는 비용을 더함
                if (n_customer <= 1100) // 만약 고객 수가 1100명 이하라면
                    dp[n_customer] = min(dp[n_customer], n_val); // 최소 비용 갱신
            }
        }
    }

    // c명 이상의 고객을 얻을 수 있는 최소 비용을 찾음
    int res = INT_MAX;  // 최소 비용을 매우 큰 값으로 초기화
    for (int i = c; i <= 1100; i++) {  // 목표 고객 수 c부터 1100명까지 확인
        res = min(res, dp[i]);  // 최소 비용 갱신
    }

    cout << res;  // 결과 출력 (최소 비용)
}
