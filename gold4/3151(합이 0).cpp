#include <bits/stdc++.h>
using namespace std;

long long arr[10001]; // 입력 배열 (최대 10000개)

// 메인 함수
int main() {
    int n;
    cin >> n; // 배열 크기 입력
    for(int i = 0; i < n; i++)
        cin >> arr[i]; // 배열 값 입력

    sort(arr, arr+n); // 오름차순 정렬
    long long result = 0; // 세 수의 합이 0이 되는 경우의 수

    // 기준 값 arr[i]를 하나 고정하고, 나머지 두 수를 투포인터로 탐색
    for(int i = 0; i < n-2; i++) {
        int left = i + 1;     // 왼쪽 포인터 (i 다음 인덱스)
        int right = n - 1;    // 오른쪽 포인터 (마지막 인덱스)

        while(left < right) {
            long long sum = arr[i] + arr[left] + arr[right]; // 세 수의 합

            if(sum == 0) {
                // ✅ 세 수의 합이 0인 경우
                if(arr[left] == arr[right]) {
                    // left ~ right 구간이 전부 같은 수일 때
                    long long cnt = right - left + 1; // 같은 원소 개수
                    // 이 구간에서 서로 다른 두 개를 고르는 경우의 수 = 조합 C(cnt, 2)
                    result += (cnt * (cnt - 1)) / 2;
                    break; // 더 이상 탐색할 필요 없음
                } else {
                    // arr[left]와 arr[right] 값이 서로 다른 경우
                    long long lcnt = 1, rcnt = 1;

                    // 왼쪽에서 같은 값이 연속되는 개수 세기
                    while(left+1 < right && arr[left] == arr[left+1]) {
                        lcnt++;
                        left++;
                    }
                    // 오른쪽에서 같은 값이 연속되는 개수 세기
                    while(right-1 > left && arr[right] == arr[right-1]) {
                        rcnt++;
                        right--;
                    }

                    // 왼쪽 구간 * 오른쪽 구간 만큼의 경우의 수 추가
                    result += lcnt * rcnt;

                    // 다음 탐색을 위해 포인터 이동
                    left++;
                    right--;
                }
            } else if(sum < 0) {
                // 합이 0보다 작으면 값을 키워야 하므로 left++
                left++;
            } else {
                // 합이 0보다 크면 값을 줄여야 하므로 right--
                right--;
            }
        }
    }

    cout << result; // 최종 결과 출력
}
