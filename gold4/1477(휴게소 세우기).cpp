#include <bits/stdc++.h>
using namespace std;

int arr[1001];  // 기존 휴게소의 위치를 저장할 배열
int dist[2000]; // 각 구간의 거리를 저장할 배열

int main(){
    int n, m, l;
    // n: 현재 고속도로에 있는 휴게소의 개수
    // m: 새로 설치할 휴게소의 개수
    // l: 고속도로의 총 길이
    cin >> n >> m >> l; 
    
    // 기존 휴게소들의 위치 입력
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // 휴게소 위치 배열을 오름차순으로 정렬
    sort(arr, arr+n);

    // 각 구간의 거리를 계산
    dist[0] = arr[0];  // 첫 번째 구간은 첫 휴게소까지의 거리
    for(int i = 1; i < n; i++){
        dist[i] = arr[i] - arr[i-1];  // 두 휴게소 간의 거리 계산
    }
    dist[n] = l - arr[n-1];  // 마지막 구간은 마지막 휴게소부터 고속도로 끝까지의 거리

    // 이진 탐색을 위한 좌우 경계를 설정
    int lft = 1;  // 최소 가능한 간격은 1
    int rgt = l - 1;  // 최대 가능한 간격은 고속도로 전체 길이-1
    int res = INT_MAX;  // 결과값, 최소 간격을 찾기 위한 변수 (초기값은 매우 큰 값)

    // 이진 탐색
    while(lft <= rgt){
        int rest = 0;  // 휴게소 설치에 필요한 여유 공간 (이후에 추가할 휴게소의 수)
        int mid = (lft + rgt) / 2;  // 중간값, 이 중간값이 최소 설치 간격이 될 수 있는지 확인
        int tmpcnt = 0;  // 각 구간에 추가할 수 있는 휴게소의 수

        // 각 구간에 대해 설치할 수 있는 휴게소의 수 계산
        for(int i = 0; i <= n; i++){
            tmpcnt = dist[i] / mid;  // 구간 거리에서 최소 간격으로 몇 개의 휴게소를 설치할 수 있는지
            if(tmpcnt > 0){
                // dist[i]가 mid로 나누어 떨어지면 그 구간에 필요한 휴게소는 tmpcnt - 1개
                // 나누어 떨어지지 않으면 tmpcnt개를 추가해야 함
                if(dist[i] % mid == 0) 
                    rest += tmpcnt - 1;
                else 
                    rest += tmpcnt;
            }
        }

        // 추가해야 하는 휴게소가 m개 이하라면
        if(rest <= m){
            rgt = mid - 1;  // 간격을 좁혀서 더 작은 값을 시도
            res = min(res, mid);  // 최소 간격을 갱신
        }
        else{
            lft = mid + 1;  // 간격을 늘려서 더 큰 값을 시도
        }
    }

    // 결과 출력: 설치할 수 있는 최소 간격
    cout << res;
}