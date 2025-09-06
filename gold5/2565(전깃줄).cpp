#include <bits/stdc++.h>
using namespace std;

int dp[201]; // LIS(최장 증가 부분 수열)를 저장할 배열
int res;     // LIS의 마지막 인덱스를 저장

// 이진 탐색 함수: dp 배열에서 target이 들어갈 위치를 찾음
int binary_search(int target, int left, int right){
    while(left < right){
        int mid = (left+right) / 2;
        if(target > dp[mid])    // target이 더 크면 오른쪽으로 이동
            left = mid + 1;
        else                    // 같거나 작으면 왼쪽 구간 유지
            right = mid;
    }   
    return right; // target이 들어갈 위치 반환
}

int main(){
    int n;   // 전깃줄 개수
    int tmp; // 입력값 임시 저장

    cin >> n;
    cin >> tmp;
    dp[0] = tmp; // 첫 번째 값 LIS에 넣음
    res = 0;     // LIS 길이(인덱스 기준) 초기화

    // 두 번째 값부터 입력받으며 LIS 계산
    for(int i = 1; i < n; i++){
        cin >> tmp;
        if(dp[res] < tmp){          // 현재 값이 LIS의 마지막 값보다 크면
            dp[res+1] = tmp;        // LIS 뒤에 추가
            res+=1;                 // LIS 길이 증가
        }
        else{                       // 그렇지 않으면
            int pos = binary_search(tmp, 0, res); // 들어갈 위치 탐색
            dp[pos] = tmp;          // 해당 위치 값 갱신
        }
    }

    // 전체 전깃줄 개수 - LIS 길이 = 제거해야 하는 전깃줄 수
    cout << n - (res + 1);
}
