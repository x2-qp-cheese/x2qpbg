#include <bits/stdc++.h>
using namespace std;


stack<int> s;

int main(){
    int n, num;
    cin >> n;

    while (n--){
        string c;
        cin >> c;
        if (c == "push"){
            cin >> num;
            s.push(num);
        }
        else if (c == "pop"){
            if (!s.empty()){
                num = s.top();
                s.pop();
                cout << num << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else if (c == "size"){
            cout << s.size() << endl;
        }
        else if(c == "empty"){
            if(!s.empty()){
                cout << 0 << endl;
            }else {
                cout << 1 << endl;
            }
        }
        else if(c == "top"){
            if(!s.empty()){
                num = s.top();
                cout << num << endl;
            }else {
                cout << -1 << endl;
            }
        }
    }
}