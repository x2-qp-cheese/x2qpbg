#include <bits/stdc++.h>
using namespace std;

int target[2001];       // 입력된 수열 (1-based index)
int dp[2001][2001];     // dp[i][j] = target[i]~target[j] 구간이 팰린드롬이면 1, 아니면 0

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n; // 수열의 길이 입력

    for(int i = 1; i <= n; i++){
        cin >> target[i]; // 수열 입력
    }

    // dp 채우기 (구간 팰린드롬 여부 판단)
    // i는 시작 인덱스, j는 끝 인덱스
    // 뒤에서부터 채워야 dp[i+1][j-1] 값 참조 가능
    for(int i = n; i >= 1 ; i--){
        for(int j = n; j >= i; j--){
            if(target[i] == target[j]){ // 양 끝 값이 같을 때
                if(j == i+1 || i == j){
                    // 1) 길이가 1인 경우(i==j) → 무조건 팰린드롬
                    // 2) 길이가 2인 경우(j==i+1) → 두 원소가 같으면 팰린드롬
                    dp[i][j] = 1;
                }
                else if(dp[i+1][j-1] == 1){
                    // 3) 길이가 3 이상인 경우
                    // 내부 구간(i+1~j-1)이 팰린드롬이고, 양 끝이 같으면 팰린드롬
                    dp[i][j] = 1;
                }
            }
        }
    }

    cin >> m; // 질의 개수
    while(m--){
        int s, e;
        cin >> s >> e; // 구간 [s, e] 입력
        cout << dp[s][e] << "\n"; // 팰린드롬 여부 출력 (1: 팰린드롬, 0: 아님)
    }
}
