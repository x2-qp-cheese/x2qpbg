#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    int n;
    int s;
    cin >> n >> s;  // 수열의 길이 n, 목표 합 s 입력

    for(int i = 0; i < n; i++){
        cin >> arr[i];  // 수열 원소 입력
    }

    int result = INT_MAX;  // 최소 길이 결과값 (초기값: 매우 큰 값)
    int sum = arr[0];      // 현재 구간의 합
    int left = 0;          // 구간의 왼쪽 포인터
    int right = 0;         // 구간의 오른쪽 포인터

    // 투 포인터 방식으로 탐색
    while(right < n){
        // 현재 구간의 합이 목표 이상이면
        if(sum >= s){
            // 구간 길이를 갱신
            result = min(result, right-left+1);

            // 왼쪽과 오른쪽 포인터가 같은 위치라면
            // (구간이 한 원소뿐인 경우) 오른쪽을 확장
            if(left == right){
                right++;
                sum += arr[right];
            }
            // 그렇지 않다면 왼쪽을 줄여서 더 짧은 구간을 탐색
            else{
                sum -= arr[left];
                left++;
            }
        }
        // 현재 구간의 합이 목표 미만이면 오른쪽 확장
        else{
            right++;
            sum += arr[right];
        }
    }

    // 조건을 만족하는 구간이 없으면 0 출력
    if(result == INT_MAX)
        cout << 0;
    else
        cout << result;  // 최소 길이 출력
}
