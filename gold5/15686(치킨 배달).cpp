#include <bits/stdc++.h>
using namespace std;

int board[51][51];               // 도시 지도 (0: 빈 칸, 1: 집, 2: 치킨집)
vector<pair<int, int>> v, tmpv;  // v: 모든 치킨집 좌표, tmpv: 선택한 치킨집 좌표
int res;                         // 최소 치킨 거리 결과
int n, m;                        // n: 도시 크기, m: 선택할 치킨집 수

// 백트래킹으로 치킨집 m개를 고르는 함수
void backtrack(int st, int cnt){
    if(cnt == m){ // 치킨집 m개를 모두 선택한 경우
        int tmpres = 0; // 현재 조합에서의 치킨 거리 합
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){ // 집인 경우
                    int cur = INT_MAX;
                    // 현재 집에서 가장 가까운 선택된 치킨집 거리 구하기
                    for(int k = 0; k < (int)tmpv.size(); k++){
                        cur = min(cur, abs(i - tmpv[k].first) + abs(j - tmpv[k].second));
                    }
                    tmpres += cur; // 치킨 거리 합산
                }
            }
        }
        // 최소 치킨 거리 갱신
        res = min(res, tmpres);
        return;
    }

    // 치킨집 후보들 중에서 m개 선택 (조합)
    for(int i = st; i < (int)v.size(); i++){
        tmpv.push_back({v[i].first, v[i].second}); // i번째 치킨집 선택
        backtrack(i + 1, cnt + 1);                 // 다음 치킨집 선택
        tmpv.pop_back();                           // 선택 취소 (백트래킹)
    }
}

int main(){
    cin >> n >> m;
    res = INT_MAX;

    // 도시 정보 입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){ 
                // 치킨집 좌표 저장
                v.push_back({i, j});
            }
        }
    }

    // 치킨집 조합 탐색 시작
    backtrack(0, 0);

    // 최소 치킨 거리 출력
    cout << res;
}