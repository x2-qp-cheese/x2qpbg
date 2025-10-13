#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];

int main(){
    cin >> n >> m; // 강의 개수 n, 블루레이 개수 m 입력
    int maxlen = 0; // 가장 긴 강의 길이를 저장할 변수
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maxlen = max(arr[i], maxlen); // 블루레이 크기의 최소값은 가장 긴 강의보다 커야 함
    }

    int r = 100000 * 10000; // 블루레이 최대 크기 (문제에서 가능한 최대값)
    int l = maxlen;          // 블루레이 최소 크기 (가장 긴 강의 길이)

    // 이분 탐색 시작
    while(l <= r){
        int mid = (l + r) / 2; // 블루레이 크기를 mid로 가정
        int sum = 0;           // 현재 블루레이에 들어간 강의들의 합
        int cnt = 0;           // 사용한 블루레이 개수

        // 모든 강의를 순서대로 담아보기
        for(int i = 0; i < n; i++){
            // 만약 현재 강의를 더 담으면 용량 초과라면 새로운 블루레이 시작
            if(sum + arr[i] > mid){
                sum = 0; // 새 블루레이로 초기화
                cnt++;   // 블루레이 개수 1 증가
            }
            sum += arr[i]; // 현재 블루레이에 강의 추가
        }

        // 마지막 블루레이가 비어있지 않다면 개수에 포함
        if(sum > 0){
            cnt++;
        }

        // 블루레이 개수가 목표 m보다 많으면, 용량이 너무 작다는 뜻 → 왼쪽 범위 증가
        if(cnt > m){
            l = mid + 1;
        }
        // 블루레이 개수가 충분히 작거나 같으면, 용량을 더 줄여도 가능할 수 있음 → 오른쪽 범위 감소
        else{
            r = mid - 1;
        }
    }

    // 최소 블루레이 크기 출력
    cout << l;
    return 0;
}