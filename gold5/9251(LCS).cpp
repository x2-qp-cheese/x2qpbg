#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];  // DP 테이블 정의: dp[i][j]는 s1의 i번째 문자까지와 s2의 j번째 문자까지의 LCS (최대 공통 부분 수열) 길이를 저장

int main(){
    string s1, s2;  // 두 문자열 입력 받기
    cin >> s1 >> s2;

    // DP 테이블 초기화 및 채우기
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            // 만약 두 문자가 같다면
            if(s2[j-1] == s1[i-1]){
                // 이전의 LCS 값(dp[i-1][j-1])에 1을 더한 값과 이전의 LCS 값(dp[i-1][j]) 중 더 큰 값을 선택
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
            }
            else{
                // 두 문자가 다르면, 이전의 LCS 값들 중 더 큰 값 선택
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // 최종 결과 출력: s1과 s2의 LCS 길이
    cout << dp[s1.length()][s2.length()];
}
