#include <bits/stdc++.h>  // 필요한 모든 헤더 파일을 포함
using namespace std;

// 최대 힙(pq1)과 최소 힙(pq2)을 정의
priority_queue<int> pq1;  // 기본적으로 큰 값이 먼저 나오는 최대 힙
priority_queue<int, vector<int>, greater<int>> pq2;  // 작은 값이 먼저 나오는 최소 힙

int main() {
    ios::sync_with_stdio(0);  // 입출력 속도 최적화
    cin.tie(0);  // cin과 cout의 동기화를 끄기 위해 설정

    int n;
    cin >> n;  // n개의 수를 입력받는다

    // 수를 하나씩 입력받으면서 중간중간 중앙값을 구하는 과정
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;  // 숫자 하나를 입력받는다

        // 힙의 크기가 같으면 pq1에 삽입, 그렇지 않으면 pq2에 삽입
        if (pq1.size() == pq2.size()) {
            pq1.push(tmp);  // pq1에 추가 (최대 힙)
        } else {
            pq2.push(tmp);  // pq2에 추가 (최소 힙)
        }

        // 두 힙의 top 값이 바뀌어야 할 경우 (최대 힙의 top이 최소 힙의 top보다 크면)
        if (pq2.size() && pq2.top() < pq1.top()) {
            // 두 힙의 top 값을 서로 교환
            int swp1 = pq1.top(); pq1.pop();  // pq1에서 최대 값 추출
            int swp2 = pq2.top(); pq2.pop();  // pq2에서 최소 값 추출
            pq2.push(swp1);  // pq2에 최대 값 삽입
            pq1.push(swp2);  // pq1에 최소 값 삽입
        }

        // 현재까지의 중앙값을 출력
        cout << pq1.top() << "\n";  // pq1의 top이 항상 중앙값이 된다
    }
}