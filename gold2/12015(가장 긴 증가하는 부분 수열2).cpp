#include <bits/stdc++.h>
using namespace std;

int arr[1000001]; // 입력값 저장용 (여기서는 사실 안 써도 됨)
int lis[1000001]; // LIS(최장 증가 부분 수열) 저장용 배열
int res;                    // LIS 길이 - 1 (마지막 인덱스)

// 이진 탐색: lis 배열에서 target이 들어갈 위치를 찾음
int binary_Search(int target, int start, int last){
    while(start < last){
        int mid = (start + last) / 2;
        if(lis[mid] == target){   // 같은 값이면 해당 위치 반환
            return mid;
        }
        else if(lis[mid] < target){ // target이 더 크면 오른쪽 탐색
            start = mid + 1;
        }
        else{                       // target이 작으면 왼쪽으로 이동
            last = mid;
        }
    }
    return last; // target이 들어갈 위치 반환
}

int main(){
    int n, tmp;
    cin >> n;

    // 첫 번째 값으로 LIS 초기화
    cin >> tmp;
    lis[0] = tmp;
    res = 0;

    // 나머지 값들 입력받으며 LIS 계산
    for(int i = 1; i < n; i++){
        cin >> tmp;
        if(lis[res] < tmp){          // 현재 값이 LIS 마지막 값보다 크면
            lis[res+1] = tmp;        // LIS 뒤에 추가
            res += 1;                // LIS 길이 증가
        }
        else{                        // 그렇지 않으면
            int pos = binary_Search(tmp, 0, res); // 들어갈 위치 탐색
            lis[pos] = tmp;          // 해당 위치 값 교체
        }
    }

    // LIS 길이 출력
    cout << res + 1;
}