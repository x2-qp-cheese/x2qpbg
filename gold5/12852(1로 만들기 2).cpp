#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

// dp[i] : 숫자 i를 1로 만드는 데 필요한 최소 연산 횟수
int dp[MAX];

// backtrack[i] : dp[i]가 최소가 될 때, 바로 이전 숫자
int backtrack[MAX];

int main(){
    int n;
    cin >> n;

    // 1은 이미 1이므로 연산 0번
    dp[1] = 0;
    backtrack[1] = 0;

    // 2부터 n까지 차례대로 DP 계산
    for(int i = 2; i <= n; i++){

        // 기본 연산: i → i-1
        dp[i] = dp[i-1] + 1;
        backtrack[i] = i-1;

        // i가 2로 나누어 떨어질 경우: i → i/2
        // 더 적은 연산 횟수라면 갱신
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            backtrack[i] = i/2;
        }

        // i가 3으로 나누어 떨어질 경우: i → i/3
        // 더 적은 연산 횟수라면 갱신
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            backtrack[i] = i/3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[n] << '\n';

    // backtrack 배열을 이용해 n → 1 경로 출력
    while(n != 0){
        cout << n << ' ';
        n = backtrack[n];
    }

    return 0;
}