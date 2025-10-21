#include <bits/stdc++.h>
using namespace std;

int arr[1001];    // 입력 값을 저장할 배열
vector<int> xy;   // 두 수의 합 (x + y)을 저장할 벡터

int main(){
    ios::sync_with_stdio(0);   // 입출력 속도를 빠르게 하기 위해
    cin.tie(0);                // cin과 cout을 분리하여 입출력 속도 최적화

    int n;
    cin >> n;    // 배열의 크기 n을 입력받음

    // 배열에 값 입력
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);   // 배열을 오름차순으로 정렬

    // x + y를 계산하여 xy 벡터에 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            xy.push_back(arr[i] + arr[j]);   // arr[i] + arr[j]의 값을 xy 벡터에 추가
        }
    }

    sort(xy.begin(), xy.end());   // xy 벡터를 오름차순으로 정렬

    // 배열에서 두 수의 합 (x + y)로 성립하는 값 찾기
    for(int i = n - 1; i >= 0; i--){   // 가장 큰 수부터 시작
        for(int j = i; j >= 0; j--){   // 현재 값부터 뒤로 탐색
            // xy 벡터에 arr[i] - arr[j]가 있는지 이진 탐색으로 확인
            bool exists = binary_search(xy.begin(), xy.end(), arr[i] - arr[j]);
            if(exists){
                cout << arr[i];   // 조건을 만족하는 가장 큰 값 출력
                return 0;         // 첫 번째로 찾은 값을 출력 후 프로그램 종료
            }
        }
    }
}