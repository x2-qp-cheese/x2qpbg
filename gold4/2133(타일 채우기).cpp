#include <bits/stdc++.h>
using namespace std;

int dp[31];

int main(){
    int n;
    cin >> n; 
    if(n % 2){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;

    for(int i = 6; i <= n; i+=2){
        dp[i] = 3 * dp[i-2];
        for(int j = i-4; j >= 0; j-=2){
            dp[i] += 2* dp[j];
        }
    }
    cout << dp[n];
}