#include <bits/stdc++.h> // 모든 표준 라이브러리를 포함
using namespace std;

int arr[5001]; // 입력 배열 (최대 크기 5000)

int main(){
    int n, m;
    cin >> n >> m; // n: 배열의 크기, m: 그룹의 최대 개수
    
    // 배열 입력
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0;        // 이분 탐색의 왼쪽 경계 (최소 허용 차이)
    int right = 10000;   // 이분 탐색의 오른쪽 경계 (최대 허용 차이, 문제 조건 상 10000으로 설정)
    int res = INT_MAX;   // 결과값 (최소 가능한 최대 차이)

    // 이분 탐색 시작
    while(left <= right){
        int availmin = (left + right) / 2; // 현재 허용할 최대 차이 (중간값)
        int grp = 1;                       // 필요한 그룹 수 (처음엔 1개로 시작)
        int tmpmax = arr[0];              // 현재 그룹 내 최대값
        int tmpmin = arr[0];              // 현재 그룹 내 최소값

        // 배열을 순회하면서 그룹을 나눔
        for(int i = 1; i < n; i++){
            tmpmax = max(arr[i], tmpmax); // 현재 그룹의 최대값 갱신
            tmpmin = min(arr[i], tmpmin); // 현재 그룹의 최소값 갱신

            // 현재 그룹의 최대-최소 차이가 허용 범위를 초과하면 새 그룹 시작
            if((tmpmax - tmpmin) > availmin){
                grp++;                     // 그룹 개수 증가
                tmpmax = arr[i];          // 새 그룹의 시작: 현재 값을 최대값으로 초기화
                tmpmin = arr[i];          // 새 그룹의 시작: 현재 값을 최소값으로 초기화
            }
        }

        // 그룹 수가 m 이하이면 더 작은 차이도 가능한지 탐색
        if(grp <= m){
            res = min(res, availmin);     // 최소 가능한 최대 차이 갱신
            right = availmin - 1;         // 더 작은 차이를 탐색
        }else{
            left = availmin + 1;          // 그룹 수가 너무 많으므로 더 큰 차이 허용
        }
    }

    // 결과 출력
    cout << res;
}