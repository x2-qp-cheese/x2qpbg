#include <bits/stdc++.h>
using namespace std;

int arr[200001];  // 집들의 위치를 저장할 배열
int dist[200001]; // 각 집들 간의 거리 차이를 저장할 배열 (사용되지 않음)
int n, c;         // n: 집의 개수, c: 설치할 공유기의 개수

int main(){
    cin >> n >> c;  // n (집의 개수)과 c (설치할 공유기의 개수) 입력 받기
    for(int i = 0; i < n; i++){
        cin >> arr[i];  // 각 집들의 위치 입력 받기
    }
    sort(arr, arr + n);  // 집들의 위치를 오름차순으로 정렬 (공유기 설치에 필요한 전제 조건)

    // 이진 탐색을 위한 최소 거리 범위 설정
    int left = 1;  // 최소 거리 (공유기 간의 최소 거리는 1 이상이어야 함)
    int right = arr[n - 1] - arr[0];  // 최대 거리 (가장 먼 집들 간의 거리)

    int res = 0;  // 최대 가능한 최소 거리 (결과를 저장할 변수)

    // 이진 탐색 시작 (left <= right)
    while(left <= right){
        int mid = (left + right) / 2;  // mid: 현재 가능한 최소 거리 후보
        int count = 1;  // 첫 번째 집에는 공유기를 설치했으므로 count는 1
        int last_position = arr[0];  // 첫 번째 집에 공유기를 설치한 위치

        // 두 번째 집부터 끝까지 공유기 설치 가능 여부 확인
        for(int i = 1; i < n; i++){
            // 만약 현재 집과 마지막으로 설치한 집 사이의 거리가 mid 이상이면
            if(arr[i] - last_position >= mid){
                count++;  // 공유기를 설치하고
                last_position = arr[i];  // 마지막으로 설치한 집의 위치 갱신
            }
        }

        // 설치한 공유기의 수가 c개 미만이라면, mid 거리로는 불가능하므로
        if(count < c){
            right = mid - 1;  // 최소 거리를 줄여서 다시 시도
        } else {
            res = max(res, mid);  // mid 거리로 설치 가능한 경우, 최대값 갱신
            left = mid + 1;  // 최소 거리를 늘려서 다시 시도
        }
    }

    // 최종적으로 찾은 최대 최소 거리 출력
    cout << res;
}
