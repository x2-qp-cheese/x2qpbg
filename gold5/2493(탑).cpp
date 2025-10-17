#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;  // (인덱스, 값) 형태로 스택을 선언

int main() {
    ios::sync_with_stdio(0);  // 입출력 속도를 빠르게 하기 위해 동기화 끄기
    cin.tie(0);  // cin과 cout의 동기화 끄기
    
    int n;
    cin >> n;  // 수열의 크기 입력 받기
    for (int i = 1; i <= n; i++) {  // 1부터 n까지 반복
        int tmp;
        cin >> tmp;  // 현재 숫자 입력 받기
        
        // 스택이 비어있지 않고, 스택의 top 값이 현재 값보다 작으면 계속 pop
        while (!s.empty() && s.top().second < tmp) {
            s.pop();
        }
        
        // 스택이 비었다면 더 큰 값이 없으므로 0 출력
        if (s.empty())
            cout << "0 ";
        else
            // 스택에 남아있는 값이 현재 값보다 큰 값이므로, 그 인덱스를 출력
            cout << s.top().first << " ";
        
        // 현재 값과 인덱스를 스택에 추가
        s.push({i, tmp});
    }

    return 0;
}