#include <bits/stdc++.h>
using namespace std;

int dp[10001];  // dp[i]는 i를 만들 수 있는 방법의 수

int main(){
    int testcase;  // 테스트 케이스 개수

    dp[0] = 1;  // 0을 만드는 방법은 1가지 (아무 숫자도 사용하지 않는 방법)

    // 1, 2, 3을 사용하여 1부터 10000까지의 금액을 만들 수 있는 방법의 수를 구하기
    for(int i = 1; i <= 3; i++){  // 1, 2, 3 각각에 대해 처리
        for(int j = i; j <= 10000; j++){  // 금액 j가 i 이상일 때만 갱신
            dp[j] += dp[j-i];  // j 금액을 만들 수 있는 방법은 dp[j-i]를 이용하여 갱신
        }
    }

    cin >> testcase;  // 테스트 케이스의 개수를 입력받기
    for(int i = 0; i < testcase; i++){  // 각 테스트 케이스에 대해 처리
        int num;  
        cin >> num;  // 목표 금액 num을 입력받기
        cout << dp[num] << endl;  // num 금액을 만들 수 있는 방법의 수를 출력
    }
}
