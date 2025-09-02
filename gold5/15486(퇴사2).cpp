#include <bits/stdc++.h>
using namespace std;

#define MAX 1500001

int timeNeeded[MAX];
int priceNeeded[MAX];

int dp[MAX];

int main(){
    int n;
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> timeNeeded[i] >> priceNeeded[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i-1]);
        if(i + timeNeeded[i] <= n+1){
            dp[i+timeNeeded[i]] = max(dp[i] + priceNeeded[i], dp[i+timeNeeded[i]]);
        }
    }
    dp[n+1] = max(dp[n+1], dp[n]);

    cout << dp[n+1];
}