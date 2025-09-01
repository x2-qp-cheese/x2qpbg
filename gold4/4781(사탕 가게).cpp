#include <bits/stdc++.h>
using namespace std;

int calorie[5005]; //사탕의 칼로리
double price[5005]; //사탕의 가격

int dp[5005][10005];

int main(){
    cout << fixed;
    cout.precision(2);
    int n; // 사탕 종류의 수
    double m; // 상근이가 가지고 있는 돈

    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0.00){
            break;
        }

        for(int i = 1; i <= n; i++){
            cin >> calorie[i] >> price[i];
        }
        int tmpm = round(m*100);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= tmpm; j++){
                int tmpPrice = round(price[i] * 100);
                if(j >= tmpPrice){
                    dp[i][j] = max(dp[i-1][j],max(dp[i][j-tmpPrice] + calorie[i], dp[i-1][j-tmpPrice] + calorie[i]));
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << dp[n][tmpm] << endl;
    }
}