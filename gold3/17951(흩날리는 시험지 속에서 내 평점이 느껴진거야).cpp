#include <bits/stdc++.h> // 모든 표준 라이브러리를 한 번에 포함
using namespace std;

vector<int> test; // 입력 값을 저장할 벡터

int main() {
    int n, k;
    cin >> n >> k; // n: 원소 개수, k: 원하는 그룹 수

    // n개의 숫자를 입력받아 test 벡터에 저장
    for (int i = 0; i < n; i++) {
        int numQ;
        cin >> numQ;
        test.push_back(numQ);
    }

    int left = 0;         // 이분 탐색의 최소값 (가능한 최소 점수)
    int right = n * 20;   // 이분 탐색의 최대값 (각 원소 최대값이 20이라고 가정했기 때문)
    // ※ 만약 입력의 최대값을 알고 있다면 그 합으로 right 설정하는 게 더 효율적임

    // 이분 탐색 시작
    while (left <= right) {
        int mid = (left + right) / 2; // 현재 시도하는 그룹 최소 점수(mid)

        int grp = 0; // 만들어진 그룹 수
        int sum = 0; // 현재 그룹의 점수 합

        // 전체 배열을 순회하면서 그룹을 만들어봄
        for (int i = 0; i < n; i++) {
            sum += test[i]; // 현재 점수 추가
            if (sum >= mid) {
                // 누적 점수가 mid 이상이면 그룹 하나 생성
                sum = 0;    // 다음 그룹을 위해 합 초기화
                grp += 1;   // 그룹 수 증가
            }
        }

        // 만들어진 그룹이 목표보다 작으면 mid가 너무 큼 → 줄여야 함
        if (grp < k) {
            right = mid - 1;
        } 
        // 만들어진 그룹이 k 이상이면 mid가 유효함 → 더 큰 mid 시도 가능
        else {
            left = mid + 1;
        }
    }

    // 조건을 만족하는 최대 mid 값이 right에 저장되어 있음
    cout << right;
}