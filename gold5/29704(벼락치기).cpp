#include <bits/stdc++.h>
using namespace std;

int daysNeeded[1001]; // i번 문제를 푸는데 걸리는 일수
int fineTopay[1001]; // i번 문제의 벌금
int dp[1001][1001];

int main(){
    int n; // 문제 개수
    int t; // 남은 제출 기한
    cin >> n >> t;
    
    int totalFine = 0;

    for(int i = 1; i <= n; i++){
        cin >> daysNeeded[i] >> fineTopay[i];
        totalFine+=fineTopay[i];
    }  

    //memset은 1byte 값으로만 초기화 가능하기에..
    for(int i = 0; i <= n; i++){
        dp[i][0] = totalFine;
    }
    for(int j = 0; j <= t; j++){
        dp[0][j] = totalFine;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            if(daysNeeded[i] <= j){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-daysNeeded[i]]-fineTopay[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][t];
}