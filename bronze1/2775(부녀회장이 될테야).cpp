#include <bits/stdc++.h>
using namespace std;

int dp[15][15]; //층, 호수

int main(){
    for(int i = 0; i <= 14; i++){
        dp[0][i] = i;
        dp[i][0] = 0;
    }
        
    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    } 

    int T; cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}