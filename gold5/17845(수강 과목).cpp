#include <bits/stdc++.h>
using namespace std;

int importance[1001];
int timeNeeded[1001];

int dp[1001][10001];

int main(){
	int n, k; //공부시간, 과목 수
	cin >> n >> k;
	
	for(int i = 1; i <= k; i++){
		cin >> importance[i] >> timeNeeded[i];
	}
	
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			if(j-timeNeeded[i] >= 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-timeNeeded[i]] + importance[i]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[k][n];
}