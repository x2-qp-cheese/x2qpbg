#include <bits/stdc++.h>
using namespace std;

int target[2001];
int dp[2001][2001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> target[i];
    }

    
    //dp 채우기
    for(int i = n; i >= 1 ; i--){
        for(int j = n; j >= i; j--){
            if(target[i] == target[j]){
                if(j == i+1|| i == j){
                    dp[i][j] = 1;
                }
                else if(dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                }
            }
        }
    }
    cin >> m;
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }


}