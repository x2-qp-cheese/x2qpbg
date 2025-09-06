#include <bits/stdc++.h>
using namespace std;

int dp[31]; // dp[i]: 가로 길이가 i일 때 채울 수 있는 경우의 수

int main(){
    int n;
    cin >> n; 

    // 홀수 길이는 3xN을 채울 수 없음 → 경우의 수 0
    if(n % 2){
        cout << 0;
        return 0;
    }

    // 초기값 설정
    dp[0] = 1;  // 편의상 공집합 경우를 1로 둠
    dp[2] = 3;  // 3x2 보드 → 채우는 경우 3가지
    dp[4] = 11; // 3x4 보드 → 채우는 경우 11가지

    // 점화식 적용
    // dp[i] = dp[i-2]*3 + (dp[i-4]*2 + dp[i-6]*2 + ... + dp[0]*2)
    for(int i = 6; i <= n; i+=2){
        dp[i] = 3 * dp[i-2];         // 기본 패턴(3x2 블록 사용)
        for(int j = i-4; j >= 0; j-=2){
            dp[i] += 2 * dp[j];      // 특수 패턴들 추가
        }
    }

    cout << dp[n];
}