#include <bits/stdc++.h> // 모든 표준 라이브러리를 포함
using namespace std;

// 좌표를 second 기준(열 기준)으로 오름차순 정렬하기 위한 비교 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.second < b.second;
}

vector<pair<int, int>> v; // 사각형의 위치를 저장할 벡터 (row, column) 형태

int main(){
    int row, column; // 전체 종이의 크기
    int paperNum;    // 사용할 수 있는 종이 개수
    int squareNum;   // 덮어야 할 사각형 개수

    cin >> row >> column;      // 종이의 행과 열 입력
    cin >> paperNum;           // 사용할 수 있는 종이 개수 입력
    cin >> squareNum;          // 사각형 개수 입력

    // 각 사각형의 위치를 입력 받아 벡터에 저장
    for(int i = 0; i < squareNum; i++){
        int tmprow, tmpcol;
        cin >> tmprow >> tmpcol;
        v.push_back({tmprow, tmpcol});
    }

    // 열(column) 기준으로 오름차순 정렬 (사각형들을 오른쪽으로 순차적으로 보기 위함)
    sort(v.begin(), v.end(), compare);

    int left = 1; // 이진 탐색의 최소 길이
    int right = min(row, column); // 종이의 최대 한 변 길이 (정사각형이므로)
    int res = right; // 결과값 (최소로 가능한 한 변의 길이)

    // 이진 탐색 시작
    while(left <= right){
        int mid = (left + right) / 2; // 현재 확인할 정사각형 한 변의 길이
        int cnt = 1; // 사용한 종이 수 (첫 사각형 덮기 위해 1장 사용)
        int startPoint = v[0].second; // 첫 번째 종이의 시작 열 위치

        for(int i = 1; i < squareNum; i++){
            // 현재 종이로 덮을 수 없는 위치면
            if(v[i].first > mid){ // 행의 길이 초과시 덮을 수 없음
                cnt = 10000000; // 큰 수로 설정해 실패 처리
                break;
            }
            // 현재 종이로 덮이지 않으면 새 종이 사용
            if(startPoint + mid - 1 < v[i].second){
                startPoint = v[i].second; // 새로운 종이의 시작 열 위치
                cnt++;
            }
        }

        // 종이 개수로 덮을 수 있으면 정답 후보로 저장하고 더 작은 길이 시도
        if(cnt <= paperNum){
            res = mid;
            right = mid - 1;
        }
        // 종이 개수가 부족하면 더 큰 길이 시도
        else{
            left = mid + 1;
        }
    }

    cout << res; // 최소로 가능한 한 변의 길이 출력
}