#include <bits/stdc++.h>
using namespace std;

int caffeine[101];  // 각 커피의 카페인 양을 저장할 배열
int dp[101][100001];  // dp[i][j]는 i번째 커피까지 고려했을 때, j만큼 카페인을 만들기 위한 최소 커피의 개수를 저장

int main(){
    int n; // 커피의 개수
    int k; // 카페인의 목표 양
    cin >> n >> k;  // 입력: 커피 개수 n과 목표 카페인 양 k

    // 목표 카페인 양이 0인 경우는, 커피를 하나도 마시지 않으므로 바로 0 출력
    if(k == 0){
        cout << 0;
        return 0;
    }

    // 커피의 카페인 양 입력받기
    for(int i = 1; i <= n; i++){
        cin >> caffeine[i];
    }

    // DP 테이블 초기화: dp[i][j]는 'i'개의 커피를 사용하여 'j'만큼의 카페인을 만들기 위한 최소 커피 수
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = 100001;  // 최대 커피의 개수로 초기화
        }
    }

    // DP 테이블 채우기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            
            // 커피의 카페인 양이 목표값과 같을 경우
            if(j == caffeine[i]){
                dp[i][j] = 1;  // 1개의 커피로 목표 카페인 양을 만들 수 있음
            }
            // 커피의 카페인 양이 목표값보다 적을 경우
            else if(j > caffeine[i]){
                // 이전 상태에서 해당 커피를 사용했을 때 최소 커피 개수와 비교하여 더 작은 값 선택
                if(dp[i-1][j-caffeine[i]]){
                    dp[i][j] = min(dp[i-1][j-caffeine[i]] + 1, dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];  // 해당 커피를 사용할 수 없는 경우, 이전 상태 그대로
                }
            }
            // 커피의 카페인 양이 목표값보다 클 경우
            else{
                dp[i][j] = dp[i-1][j];  // 해당 커피는 사용할 수 없으므로 이전 상태 그대로
            }
        }
    }

    // 목표 카페인 양을 만들 수 없을 경우 dp[n][k]는 100001로 남아있음
    if(dp[n][k] == 100001){
        cout << -1;  // 불가능한 경우 -1 출력
    }
    else{
        cout << dp[n][k];  // 가능한 경우 최소 커피 개수 출력
    }
}
