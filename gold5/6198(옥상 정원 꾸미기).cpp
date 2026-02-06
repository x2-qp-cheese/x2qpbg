#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){
    int n; cin >> n;
    long long res = 0; // 결과(볼 수 있는 쌍의 개수)를 저장 (값이 커질 수 있으니 long long)

    while(n--){
        int h; cin >> h; // 현재 사람(또는 건물)의 높이 입력

        // 스택이 비어있으면 비교할 대상이 없으므로 그냥 넣고 다음으로
        if(s.empty()){
            s.push(h); 
            continue;
        }

        // 현재 높이 h보다 작거나 같은 높이들은
        // 앞으로 h가 등장했으니 h에 의해 가려져서 의미가 없어짐
        // 따라서 스택에서 제거
        while(!s.empty() && s.top() <= h){
            s.pop();
        }

        // 남아있는 스택의 원소들은 모두 h보다 큰 높이들이다.
        // 이 높이들은 현재 h를 볼 수 있으므로
        // 스택에 남아있는 개수만큼 결과에 더해준다.
        res += s.size();

        // 현재 높이도 이후 입력에서 비교 대상이 되므로 스택에 push
        s.push(h);
    }

    // 최종 결과 출력
    cout << res;   
}
