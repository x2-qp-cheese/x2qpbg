#include <bits/stdc++.h>
using namespace std;

int n;
int result;
int liq[100001];

int main(){
    cin >> n;  // 전체 용액의 개수 입력
    for(int i = 0; i < n; i++){
        cin >> liq[i];  // 각 용액의 특성값 입력
    }
    sort(liq, liq+n);  // 용액들을 오름차순 정렬

    int left = 0;       // 가장 왼쪽(음수 쪽) 인덱스
    int right = n-1;    // 가장 오른쪽(양수 쪽) 인덱스
    result = INT_MAX;   // 결과값(가장 0에 가까운 합) 초기화

    // 투 포인터 탐색 시작
    while(left < right){
        int tmp = liq[left] + liq[right];  // 두 용액의 합 계산

        // 지금까지의 결과보다 더 0에 가까우면 갱신
        if(abs(tmp) < abs(result)){
            result = tmp;
        }

        // 합이 정확히 0이면 더 볼 필요 없이 종료
        if(tmp == 0){
            cout << 0;
            return 0;
        }
        // 합이 양수라면 오른쪽 포인터를 줄여서 더 작은 값 시도
        else if(tmp > 0){
            right--;
        }
        // 합이 음수라면 왼쪽 포인터를 늘려서 더 큰 값 시도
        else{
            left++;
        }
    }

    // 가장 0에 가까운 합 출력
    cout << result;
}