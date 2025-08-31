#include <bits/stdc++.h>
using namespace std;

int caffeine[101];
int dp[101][100001];

int main(){
    int n; // 커피의 개수
    int k; // 카페인의 양
    cin >> n >> k;

    if(k == 0){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> caffeine[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = 100001;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){

            if(j == caffeine[i]){
                dp[i][j] = 1;
            }
            else if(j > caffeine[i]){
                if(dp[i-1][j-caffeine[i]]){
                    dp[i][j] = min(dp[i-1][j-caffeine[i]]+1, dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][k] == 100001){
        cout << -1;
    }
    else{
        cout << dp[n][k];
    }
}