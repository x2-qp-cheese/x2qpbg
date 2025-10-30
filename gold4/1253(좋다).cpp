#include <bits/stdc++.h> // 모든 표준 라이브러리 포함
using namespace std;

long long arr[2001]; // 입력받은 수들을 저장할 배열

int main(){
    ios::sync_with_stdio(0); // C의 stdio와 C++의 iostream 동기화 비활성화 (입출력 속도 향상)
    cin.tie(0);              // cin과 cout의 묶음을 해제 (입출력 속도 향상)

    int n;   // 수의 개수
    int res = 0; // 좋은 수의 개수를 세는 변수
    cin >> n;

    // n개의 수 입력
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 오름차순 정렬 (투 포인터 알고리즘을 적용하기 위함)
    sort(arr, arr + n);
    
    // 모든 수에 대해 ‘좋은 수’인지 확인
    for(int i = 0; i < n; i++){
        int target = arr[i]; // 현재 검사 중인 수 (좋은 수인지 판별할 대상)
        int st = 0;          // 시작 포인터
        int en = n - 1;      // 끝 포인터

        // 투 포인터 탐색 시작
        while(st < en){
            // 자기 자신을 더하는 경우는 제외
            if(st == i) st++;
            if(en == i) en--;
            if(st == en) break;

            int sum = arr[st] + arr[en]; // 두 수의 합 계산

            if(sum == target){
                // 두 수의 합이 target과 같으면 '좋은 수'
                res++;
                break; // 한 번 찾았으면 중복 방지를 위해 다음 target으로 넘어감
            }
            else if(sum > target){
                // 합이 너무 크면 오른쪽 포인터를 왼쪽으로 이동
                en--;
            }
            else{
                // 합이 너무 작으면 왼쪽 포인터를 오른쪽으로 이동
                st++;
            }
        }
    }
    
    // 좋은 수의 개수 출력
    cout << res;
}
