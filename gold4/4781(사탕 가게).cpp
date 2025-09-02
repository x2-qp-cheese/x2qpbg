#include <bits/stdc++.h>
using namespace std;

int calorie[5005]; // 각 사탕의 칼로리
double price[5005]; // 각 사탕의 가격

int dp[5005][10005]; // dp[i][j]는 i번째 사탕까지 고려했을 때 j만큼의 돈을 사용하여 얻을 수 있는 최대 칼로리

int main(){
    cout << fixed;
    cout.precision(2);  // 출력 시 소수점 둘째 자리까지 표시

    int n; // 사탕 종류의 수
    double m; // 상근이가 가지고 있는 돈

    while(1){
        cin >> n >> m;  // 사탕 종류의 수 n과 상근이가 가지고 있는 돈 m을 입력받음
        if(n == 0 && m == 0.00){  // n과 m이 0이면 입력 종료
            break;
        }

        // 사탕의 칼로리와 가격 입력받기
        for(int i = 1; i <= n; i++){
            cin >> calorie[i] >> price[i];  // 칼로리와 가격 입력
        }

        // m을 정수로 계산하기 위해 100을 곱하여 cent 단위로 변환
        int tmpm = round(m * 100);

        // DP 테이블 초기화 및 계산
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= tmpm; j++){
                // 현재 사탕의 가격을 cent 단위로 변환
                int tmpPrice = round(price[i] * 100);

                // 현재 금액 j로 사탕을 살 수 있으면, 최대 칼로리 계산
                if(j >= tmpPrice){
                    dp[i][j] = max(dp[i-1][j], max(dp[i][j - tmpPrice] + calorie[i], dp[i-1][j - tmpPrice] + calorie[i]));
                }
                else{
                    dp[i][j] = dp[i-1][j];  // 현재 금액으로 사탕을 살 수 없으면 이전 상태 그대로
                }
            }
        }

        // 결과 출력: 상근이가 가질 수 있는 최대 칼로리
        cout << dp[n][tmpm] << endl;
    }
}
