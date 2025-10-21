#include <bits/stdc++.h>
using namespace std;

// 5001개의 수를 담을 배열 선언
long long arr[5001];
long long x, y, z;  // 결과로 출력할 수
int main(){
    int n;
    cin >> n;  // 입력으로 배열의 크기 n을 받음

    // 배열에 n개의 수 입력받기
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // 배열을 오름차순으로 정렬
    sort(arr, arr+n);
    
    long long res = 3e9;  // 초기 값은 매우 큰 값으로 설정 (3*10^9)
    
    // 배열의 각 요소를 기준으로 3개의 수의 합이 0에 가까운 값을 찾음
    for(int i = 0; i < n-2; i++){
        int left = i + 1;  // i+1부터 시작하는 left 포인터
        int right = n - 1;  // 배열 끝에서 시작하는 right 포인터
        
        // left와 right 포인터가 교차할 때까지 반복
        while(left < right){
            long long sum = arr[i] + arr[left] + arr[right];  // 현재 세 수의 합을 계산

            // 합이 0이면 바로 출력하고 종료
            if(sum == 0){
                cout << arr[i] << " " << arr[left] << " " << arr[right];
                return 0;  // 조건을 만족했으므로 바로 종료
            }
            
            // 합이 0에 더 가까운 경우, 결과 값 갱신
            if(abs(sum) < abs(res)){
                x = arr[i];  // x, y, z에 현재 값 저장
                y = arr[left];
                z = arr[right];
                res = sum;  // 가장 작은 합을 res에 저장
            }
            
            // 합이 양수이면 큰 값을 줄여야 하므로 right 포인터를 왼쪽으로 이동
            if(sum > 0)
                right--;
            // 합이 음수이면 작은 값을 키워야 하므로 left 포인터를 오른쪽으로 이동
            else
                left++;
        }
    }
    
    // 0에 가장 가까운 세 수 출력
    cout << x << " " << y << " " << z;
}
