#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<char> v;

int main(){
    int n;
    cin >> n;

    int lastnum = 0;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num > lastnum){
            for(int j = lastnum + 1; j <= num; j++){
                s.push(j);
                v.push_back('+');
            }
            lastnum = num;
        }

        if(s.empty() || s.top() != num){
            cout << "NO";
            return 0;
        }

        s.pop();
        v.push_back('-');
    }

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}
