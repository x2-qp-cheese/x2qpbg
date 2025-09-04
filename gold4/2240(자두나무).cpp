#include <bits/stdc++.h>
using namespace std;

int treeNum[1001];      // 매 초마다 자두가 떨어지는 나무 번호 (1번 또는 2번)
int dp[31][1001];       // dp[w][t] = t초까지 w번 이동했을 때 받을 수 있는 자두의 최대 개수

int main(){
    int T, W;
    cin >> T >> W; // T: 전체 시간, W: 최대 이동 횟수
    
    for(int i = 1; i <= T; i++){
        cin >> treeNum[i]; // i초에 자두가 떨어지는 나무 번호 입력
    }

    // 초기 상태: 이동하지 않고 1번 나무에만 있을 때
    // dp[0][i]는 0번 이동(즉, 항상 1번 나무)에 머물러 있을 때의 자두 개수
    for(int i = 1; i <= T; i++){
        if(treeNum[i] == 1){ // i초에 1번 나무에서 자두가 떨어짐
            dp[0][i] = dp[0][i-1] + 1;
        }
        else{ // 2번 나무에서 떨어지므로 못 받음
            dp[0][i] = dp[0][i-1];
        }
    }

    // i = 이동 횟수, j = 시간
    for(int i = 1; i <= W; i++){
        for(int j = 1; j <= T; j++){
            if(i % 2 == 1){ // 홀수번 이동 → 현재 위치는 2번 나무
                if(treeNum[j] == 2){ 
                    // 현재 시각에 2번 나무에서 자두가 떨어짐
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1] + 1);
                }
                else{ 
                    // 현재 시각에 1번 나무에서 자두가 떨어짐
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            else{ // 짝수번 이동 → 현재 위치는 1번 나무
                if(treeNum[j] == 1){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1] + 1);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } 
            }
        }
    }

    // 최대 W번 이동했을 때, T초 동안 받을 수 있는 자두의 최대 개수
    cout << dp[W][T];
}
