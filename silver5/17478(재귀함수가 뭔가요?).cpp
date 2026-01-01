#include <iostream>
#include <string>
using namespace std;

// depth(재귀 횟수)에 따라 "____"를 출력하는 보조 함수
void print_bar(int depth) {
    for (int i = 0; i < depth; i++) cout << "____";
}

void recursion(int n, int depth) {
    // 1. 공통 질문 영역: 재귀가 들어갈 때마다 항상 출력됨
    print_bar(depth);
    cout << "\"재귀함수가 뭔가요?\"\n";

    // 2. 베이스 케이스 (Base Case): 재귀의 끝에 도달했을 때
    if (n == 0) {
        print_bar(depth);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    } 
    // 3. 재귀 케이스 (Recursive Case): 계속해서 자기 자신을 호출
    else {
        print_bar(depth);
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        print_bar(depth);
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        print_bar(depth);
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        
        // n을 1 줄이고 depth를 1 늘려 다음 단계로 진입 (Step-in)
        recursion(n - 1, depth + 1);
    }

    // 4. 스택 반환 영역: 재귀가 끝나고 돌아 나오면서 실행됨 (Step-out)
    // 이 부분이 있어야 "라고 답변하였지"가 역순으로 중첩되어 출력됩니다.
    print_bar(depth);
    cout << "라고 답변하였지.\n";
}

int main() {
    // C++ 입출력 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0; // 입력 예외 처리
    
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    
    // 재귀 함수 시작 (depth는 0부터 시작)
    recursion(n, 0);
    
    return 0;
}