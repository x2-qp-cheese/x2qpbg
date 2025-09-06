#include <bits/stdc++.h>
using namespace std;

int liq[100001];  // 액체의 양을 저장할 배열
pair<int, int> res;  // 결과를 저장할 변수 (두 액체의 양)

int main(){
    int n;
    cin >> n;  // 액체의 개수 입력
    for(int i = 0; i < n; i++){
        cin >> liq[i];  // 액체의 양 입력
    }

    sort(liq, liq + n);  // 액체 양을 오름차순으로 정렬
    int left = 0;  // 왼쪽 포인터 (배열의 첫 번째 원소)
    int right = n - 1;  // 오른쪽 포인터 (배열의 마지막 원소)
    int svsum = liq[left] + liq[right];  // 초기 합을 계산 (가장 왼쪽과 오른쪽 값의 합)
    res.first = liq[left];  // 초기 왼쪽 값을 결과에 저장
    res.second = liq[right];  // 초기 오른쪽 값을 결과에 저장

    while(left < right){  // 왼쪽 포인터가 오른쪽 포인터보다 작을 때 반복
        int sum = liq[left] + liq[right];  // 현재 두 값의 합을 계산
        if(sum == 0){  // 합이 0이면 바로 출력하고 종료
            cout << liq[left] << " " << liq[right];
            return 0;
        }
        if(abs(svsum) > abs(sum)){  // 기존의 합보다 현재 합이 더 0에 가까우면 업데이트
            svsum = sum;
            res.first = liq[left];
            res.second = liq[right];
        }
        if(sum > 0){  // 합이 양수일 경우 오른쪽 포인터를 왼쪽으로 이동
            right--;
        }
        else{  // 합이 음수일 경우 왼쪽 포인터를 오른쪽으로 이동
            left++;
        }   
    }

    cout << res.first << " " << res.second;  // 결과 출력
}
