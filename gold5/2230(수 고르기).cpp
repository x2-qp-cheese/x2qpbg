#include <bits/stdc++.h>
using namespace std;

int arr[100001]; // 입력받을 수열 저장 배열

int main(){
    int n, m;
    cin >> n >> m; // n: 수열의 크기, m: 최소 차이 조건

    // 수열 입력
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 정렬 (투 포인터 사용을 위해 오름차순 정렬)
    sort(arr, arr+n);

    int left = 0;              // 왼쪽 포인터
    int right = 0;             // 오른쪽 포인터
    int mindiff = INT_MAX;     // 조건을 만족하는 차이 중 최소값 저장

    // 두 포인터 탐색 시작
    while(left < n && right < n){
        int diff = arr[right] - arr[left]; // 두 원소의 차이 계산

        if(diff < m){
            // 차이가 m보다 작으면 더 큰 차이를 만들기 위해 right 이동
            right++;
        }
        else{
            // diff >= m인 경우, 답 후보이므로 mindiff 갱신
            mindiff = min(diff, mindiff);

            if(left == right){
                // left == right라면 같은 원소를 비교하는 경우 → right를 이동
                right++;
            }
            else{
                // 그 외의 경우, 차이를 줄이기 위해 left 이동
                left++;
            }
        }
    }

    // 최종 결과 출력
    cout << mindiff;
}
