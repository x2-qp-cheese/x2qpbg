#include <bits/stdc++.h>
using namespace std;

vector<int> cakePiece; // 케이크 조각 크기를 저장할 벡터

int main(){
    int n; // 자르는 횟수가 담긴 목록의 길이
    int m; // 자를 수 있는 지점의 개수
    int l; // 롤 케이크의 길이
    cin >> n >> m >> l; // n, m, l 값을 입력 받음

    int cur = 0; // 현재 위치를 0으로 초기화
    // 케이크를 자를 수 있는 위치들을 입력 받아서 조각 크기 계산
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp; // 자를 수 있는 지점 입력
        cakePiece.push_back(tmp - cur); // 이전 지점과의 차이를 계산하여 조각 크기 추가
        cur = tmp; // 현재 지점을 갱신
    }
    cakePiece.push_back(l - cur); // 마지막 조각 크기 (끝까지의 길이)

    // 각 자르는 횟수에 대해 가장 작은 조각의 크기를 구하기
    while(n--){
        int cutCnt; // 자를 조각 수
        cin >> cutCnt; // 자를 조각 수 입력

        int left = 1; // 최소 조각 크기는 1
        int right = l-1; // 최대 조각 크기는 케이크의 전체 길이 - 1
        int res = 0; // 가장 작은 조각의 크기

        // 이진 탐색을 통해 가능한 가장 큰 최소 조각 크기 찾기
        while(left <= right){
            int mid = (left + right) / 2; // 중간값, 현재 가능한 최소 조각 크기
            int cnt = 0; // 자른 조각의 개수
            int sum = 0; // 현재까지 자른 조각의 크기 합

            // 각 조각 크기를 탐색하여 자를 수 있는지 확인
            for (int i = 0; i < m; i++) {
                sum += cakePiece[i]; // 현재 조각 크기를 합산
                if (sum >= mid) { // 합이 최소 크기보다 크면 자르기
                    cnt++; // 자른 조각 수 증가
                    sum = 0; // 자른 후에는 다시 크기 합을 초기화
                }
            }
            sum += cakePiece[m]; // 마지막 조각 처리
            // 만약 마지막 조각이 최소 크기보다 작은데 자르지 못하면 하나 빼기
            if (sum && sum < mid)
                cnt--;

            // 자른 조각 수가 목표보다 적으면 최소 크기를 줄여야 하므로 오른쪽을 줄임
            if(cnt < cutCnt)
                right = mid - 1;
            else{
                left = mid + 1; // 자른 조각 수가 충분하면 최소 크기를 늘림
                res = max(mid, res); // 최대로 자른 최소 크기 갱신
            }
        }

        cout << res << "\n"; // 최대로 자른 최소 조각 크기 출력
    }
}