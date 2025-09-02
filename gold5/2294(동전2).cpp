#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main(){
    int n, k;
    cin >> n >> k;
    fill(dp, dp+10001, 100001);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        for(int j = coin; j <= k; j++){
            dp[j] = min(dp[j-coin]+1, dp[j]); 
        }
    }

    if(dp[k] == 100001){
        cout << -1;
    }
    else{
        cout << dp[k];
    }
}