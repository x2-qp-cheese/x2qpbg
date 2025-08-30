#include <bits/stdc++.h>
using namespace std;

int importance[1001];  // 각 과목의 중요도 (가치)
int timeNeeded[1001];  // 각 과목을 공부하는 데 필요한 시간
int dp[1001][10001];   // dp[i][j] : i번째 과목까지 고려했을 때, 공부 시간 j 안에서 얻을 수 있는 최대 중요도

int main(){
	int n, k; // n = 총 공부 가능 시간, k = 과목 수
	cin >> n >> k;
	
	// 각 과목의 중요도와 필요 시간을 입력받음
	for(int i = 1; i <= k; i++){
		cin >> importance[i] >> timeNeeded[i];
	}
	
	// 0/1 배낭 문제의 전형적인 DP 풀이
	for(int i = 1; i <= k; i++){        // i번째 과목까지 고려
		for(int j = 1; j <= n; j++){    // 공부 시간 j일 때
			if(j - timeNeeded[i] >= 0){ 
				// i번째 과목을 공부할 시간이 충분하다면
				// 1) 이 과목을 공부하지 않는 경우(dp[i-1][j])
				// 2) 이 과목을 공부하는 경우(dp[i-1][j-timeNeeded[i]] + importance[i])
				// 두 경우 중 더 큰 값을 선택
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-timeNeeded[i]] + importance[i]);
			}
			else{
				// 시간이 부족해서 i번째 과목을 공부할 수 없으면 이전 값 그대로 유지
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	// k개의 과목을 모두 고려했을 때, 총 공부 시간 n 안에서 얻을 수 있는 최대 중요도 출력
	cout << dp[k][n];
}
